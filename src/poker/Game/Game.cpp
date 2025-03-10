#include "Game.h"
#include "BotPlayer.h"
#include <random>
#include <string>

Game::Game(const std::string& name, unsigned int player_count, unsigned int initial_money) {
    this->player_count = player_count;
    this->currently_playing = player_count;
    players.push_back(std::make_unique<HumanPlayer>(name, initial_money, 0));
    auto random_names = Names::get_names(player_count - 1);
    for (unsigned int i = 0; i < player_count - 1; ++i) {
        players.push_back(std::make_unique<BotPlayer>(random_names[i], initial_money, 0));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0, player_count - 1);

    dealer = dist(gen);
//    dealer = 5;
    current_player = (dealer + 1) % player_count;
    players[dealer]->set_dealer(true);
    players[(dealer + 1) % player_count]->set_small_blind(true);
    players[(dealer + 2) % player_count]->set_big_blind(true);
}

unsigned int Game::find_active_player(unsigned int index) {
    unsigned int active_player = index;
    do {
        active_player = (active_player + 1) % player_count;
    } while (players[active_player]->folded());
    return active_player;
}

void Game::add_table_card(unsigned int num_of_cards) {
    for (unsigned int i = 0; i < num_of_cards; ++i) {
        for (auto& player : players) {
            player->add_table_card(deck->front()->card_index());
        }
        table->push_back(std::move(deck->front()));
        deck->pop_front();
    }
}

void Game::deal() {
    for (int i = 0; i < 2; ++i) {
        for (auto& player : players) {
            player->add_card(std::move(deck->front()));
            deck->pop_front();
        }
    }
}

void Game::next_phase() {
    can_check = true;
    switch (phase) {
        case Phase::PreFlop:
            add_table_card(3);
            phase = Phase::Flop;
            break;
        case Phase::Flop:
            add_table_card(1);
            phase = Phase::Turn;
            break;
        case Phase::Turn:
            add_table_card(1);
            phase = Phase::River;
            break;
        case Phase::River:
            phase = Phase::Showdown;
            break;
        case Phase::Showdown:
            break;
    }
    collect_bets();
}

void Game::collect_bets() {
    for (auto& player : players) {
        pot += player->remove_bet();
    }
}

void Game::next_player() {
    if (players[current_player]->folded()) {
        --currently_playing;
//        pot += players[current_player]->remove_bet();
        discarded->add_cards(players[current_player]->clear_hand());
    }

    if (check_round_end()) {
        next_phase();
        current_player = find_active_player(dealer);
        for (auto& player : players) {
            player->reset_after_phase();
        }
        return;
    }
    current_player = find_active_player(current_player);
}

unsigned int Game::get_previous_bet() {
    int idx = current_player - 1;
    if (idx < 0) idx += player_count;
    while (players[idx]->folded()) {
        --idx;
        if (idx < 0) idx += player_count;
    }
    return players[idx]->bet();
}

int Game::bot_play() {
    unsigned int previous_bet = get_previous_bet();
    return dynamic_cast<BotPlayer&>(*players[current_player]).make_decision(previous_bet, player_count    , table->to_string(), can_check, false);
}

void Game::make_move(Decision decision, int bet) {
    // do not reset status if player is big or small blind to preserve status description until next play
    if (!players[current_player]->big_blind() && !players[current_player]->small_blind()) {
        players[current_player]->reset_after_round();
    }
    if (decision == Decision::Bot) {
        bet = bot_play();
        decision = convert_bot_decision(bet);
    }
    switch (decision) {
        case Decision::Bet:
            can_check = false;
            if(anyone_all_in){
                players[current_player]->make_call(get_previous_bet());
            } else {
                players[current_player]->make_bet(bet);
                break;
            }
        case Decision::Raise:
            can_check = false;
            if(anyone_all_in){
                players[current_player]->make_call(get_previous_bet());
            } else {
                players[current_player]->make_raise(bet);
            }
            break;
        case Decision::Call:
            if (players[current_player]->money() == bet) {
                players[current_player]->make_all_in();
            } else {
                players[current_player]->make_call(bet);
            }
            break;
        case Decision::Fold:
            players[current_player]->make_fold();
            break;
        case Decision::AllIn:
            if (players[current_player]->all_in()) {
                players[current_player]->make_call(players[current_player]->bet());
            } else {
                players[current_player]->make_all_in();
                anyone_all_in = true;
            }
            break;
        case Decision::Check:
            if (anyone_all_in){
                players[current_player]->make_call(bet);
            } else {
                players[current_player]->make_check();
            }
            break;
    }
    next_player();
}

Decision Game::convert_bot_decision(int bet) {
    Decision decision;
    int previous_bet = get_previous_bet();
    int current_money = players[current_player]->money();
    if (bet == 0) {
        decision = Decision::Check;
    } else if (players[current_player]->small_blind() || players[current_player]->big_blind()) {
        decision = Decision::Bet;
    } else if (bet  > previous_bet && bet < current_money) {
        decision = Decision::Raise;
    } else if (bet >= current_money) {
        decision = Decision::AllIn;
    } else if (bet == previous_bet) {
        decision = Decision::Call;
    } else {
        decision = Decision::Fold;
    }
    return decision;
}

bool Game::check_round_end() {
    bool equal_bets = true;
    for (const auto& player : players) {
        if (!player->folded() && !player->called() && !player->checked()) {
            equal_bets = false;
        }
    }
    return equal_bets;
}

void Game::delete_broke_players() {
    while (true) {
        auto it = std::find_if(players.begin() + 1, players.end(), [](const auto &player) { return player->money() == 0; });
        if (it != players.end()) {
            players.erase(it);
            --player_count;
        }
        else {
            break;
        }
    }
    if (players[0]->money() == 0) {
        players[0].reset();
    }
    currently_playing = player_count;
}

void Game::share_pot() {
    bool all_in = false;
    std::vector<unsigned int> allin_bets;
    int idx = 0;
    for (const auto& player : players) {
        if (player->all_in()) {
            allin_bets.push_back(idx);
            all_in = true;
        }
        ++idx;
    }
    if (!all_in)
    {
        for (auto& winner : winners) {
            players[winner]->set_money(players[winner]->money() + pot / winners.size());
        }
        pot = 0;
    } else {
        std::sort(allin_bets.begin(), allin_bets.end(), [&](unsigned int a, unsigned int b) {
            return players[a]->sum_bet() < players[b]->sum_bet();
        });
        smallest_allin = 0;
        for(unsigned int allin_bet : allin_bets) {
            unsigned int allin_pot = (players[allin_bet]->sum_bet()-smallest_allin) * currently_playing;
            for (auto& winner : winners) {
                players[winner]->set_money(players[winner]->money() + allin_pot / winners.size());
            }
            pot -= allin_pot;
            winners.erase(std::remove_if(winners.begin(), winners.end(), [&](unsigned int winner) {
                return players[winner]->sum_bet() == smallest_allin;
            }), winners.end());
            smallest_allin = players[allin_bet]->sum_bet();
        }
        for (auto& winner : winners) {
            players[winner]->set_money(players[winner]->money() + pot / winners.size());
        }
    }
}
void Game::find_winner() {
    unsigned int max = 0;
    for (unsigned int i = 0; i < player_count; ++i) {
        auto eval = players[i]->evaluate();
        if (!players[i]->folded() && eval > max) {
            winners.clear();
            max = eval;
            winners.push_back(i);
        } else if (!players[i]->folded() && eval == max) {
            winners.push_back(i);
        }
    }
}

void Game::collect_cards() {
    for (auto& player : players) {
        if (player->hand_size() == 2)
            discarded->add_cards(player->clear_hand());
    }
    for (auto& card : *table) {
        discarded->add_card(std::move(card));
    }
    table->clear();
    std::shuffle(discarded->begin(), discarded->end(), std::mt19937(std::random_device()()));
    for (auto& card : *discarded) {
        deck->push_back(std::move(card));
    }
    discarded->clear();
}

void Game::set_new_dealer() {
    dealer = find_active_player(dealer);
    current_player = find_active_player(dealer);
    players[dealer]->set_dealer(true);
    players[current_player]->set_small_blind(true);
    players[find_active_player(current_player)]->set_big_blind(true);}

void Game::reset_phase() {
    phase = Phase::PreFlop;
}

void Game::reset_winners() {
    winners.clear();
}

void Game::reset_players_status() {
    for (auto& player : players) {
        player->reset_after_phase();
        player->set_all_in(false);
        player->set_sum_bet(0);
        player->set_folded(false);
    }
}

void Game::reset_initial_status() {
    players[dealer]->set_dealer(false);
    players[(dealer + 1) % player_count]->set_small_blind(false);
    players[(dealer + 2) % player_count]->set_big_blind(false);
}

void Game::restart_game() {
    reset_players_status();
    collect_cards();
    set_new_dealer();
    reset_winners();
    pot = 0;
    reset_phase();
    smallest_allin = 0;
}