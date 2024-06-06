#include "Game.h"
#include "BotPlayer.h"
#include <random>
#include <string>

Game::Game(const std::string& name, unsigned int player_count, unsigned int initial_money) {
    this->player_count = player_count;
    this->currently_playing = player_count;
    players.push_back(std::make_unique<HumanPlayer>(name, initial_money, 0));
    for (unsigned int i = 1; i < player_count; ++i) {
        players.push_back(std::make_unique<BotPlayer>("Bot " + std::to_string(i), initial_money, 0));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned int> dist(0, player_count - 1);

    dealer = dist(gen);
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
    }

    current_player = find_active_player(current_player);
}

void Game::bot_play() {
    unsigned int previous_bet = players[(current_player - 1) % player_count]->bet();
    dynamic_cast<BotPlayer&>(*players[current_player]).make_decision(previous_bet, currently_playing    , table->to_string());
}

bool Game::check_round_end() {
    bool equal_bets = true;
    auto current_bet = players[current_player]->bet();
    for (const auto& player : players) {
        if (!player->folded() && player->bet() < current_bet) {
            equal_bets = false;
            break;
        }
    }
    return equal_bets;
}

void Game::find_winner() {

}