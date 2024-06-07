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
    current_player = (dealer + 1) % player_count;
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
        currently_playing = find_active_player(dealer);
        for (auto& player : players) {
            player->reset_after_phase();
        }
    }

    current_player = find_active_player(current_player);
}

void Game::bot_play() {
    unsigned int previous_bet = players[(current_player - 1) % player_count]->bet();
    dynamic_cast<BotPlayer&>(*players[current_player]).make_decision(previous_bet, currently_playing    , table->to_string());
}

void Game::make_move(Decision decision, int bet) {
    switch (decision) {
        case Decision::Bot:
            bot_play();
            break;
        case Decision::Bet:
            players[current_player]->make_bet(bet);
            break;
        case Decision::Raise:
            players[current_player]->make_raise(bet);
            break;
        case Decision::Call:
            players[current_player]->make_call(bet);
            break;
        case Decision::Fold:
            players[current_player]->make_fold();
            break;
        case Decision::AllIn:
            players[current_player]->make_all_in();
            break;
        case Decision::Check:

            players[current_player]->make_check();
            break;
    }
    next_player();
}

bool Game::check_round_end() {
    bool equal_bets = true;
    auto current_bet = players[current_player]->bet();
    for (const auto& player : players) {
        if (!player->folded() && !player->called()) {
            equal_bets = false;
            break;
        }
    }
    return equal_bets;
}

void Game::delete_broke_players() {
    while (true) {
        auto it = std::find_if(players.begin(), players.end(), [](const auto &player) { return player->money() == 0; });
        if (it != players.end()) {
            players.erase(it);
            --player_count;
            --currently_playing;
        }
        else {
            break;
        }
    }
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
    } else{
        std::sort(allin_bets.begin(), allin_bets.end(), [&](unsigned int a, unsigned int b) {
            return players[a]->bet() < players[b]->bet();
        });
        smallest_allin = 0;
        for(unsigned int allin_bet : allin_bets) {
            for (auto& winner : winners) {
                players[winner]->set_money(players[winner]->money() + (players[allin_bet]->bet()-smallest_allin) / winners.size());
            }
            pot -= players[allin_bet]->bet() * winners.size();
            winners.erase(std::remove(winners.begin(), winners.end(), allin_bet), winners.end());
            smallest_allin = players[allin_bet]->bet();
        }
        for (auto& winner : winners) {
            players[winner]->set_money(players[winner]->money() + pot / winners.size());
        }
    }

}
void Game::find_winner() {
    for(auto& player : players) {
        for (const auto & i : *table) {
            player->add_table_card(i->card_index());
        }
    }
    unsigned int max = 0;
    for (unsigned int i = 0; i < player_count; ++i) {
        if (!players[i]->folded() && players[i]->evaluate() > max) {
            winners.clear();
            max = players[i]->evaluate();
            winners.push_back(i);
        } else if (!players[i]->folded() && players[i]->evaluate() == max) {
            winners.push_back(i);
        }
    }
}

void Game::collect_cards() {
    for (auto& player : players) {
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
}

void Game::set_new_dealer() {
    ++dealer;
    dealer %= player_count;
    current_player = (dealer + 1) % player_count;
    players[dealer]->set_dealer(true);
    players[(dealer + 1) % player_count]->set_small_blind(true);
    players[(dealer + 2) % player_count]->set_big_blind(true);
}

void Game::reset_phase() {
    phase = Phase::PreFlop;
}

void Game::reset_winners() {
    winners.clear();
}

void Game::reset_players_status() {
    for (auto& player : players) {
        player->reset_status();
        player->reset_after_phase();
    }
}
void Game::restart_game() {
    reset_players_status();
    collect_cards();
    set_new_dealer();
    pot = 0;
    reset_phase();
    smallest_allin = 0;
    reset_winners();
}