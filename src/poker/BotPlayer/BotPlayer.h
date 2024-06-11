#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include <random>
#include "EquityCalculator.h"
#include "CardRange.h"


class BotPlayer : public Player{
    std::random_device rd;
    std::mt19937 engine;
    std::uniform_int_distribution<int> dist;
    double m_equity;
    bool has_enough_money(unsigned int money_to_bet) const noexcept;
public:
    BotPlayer(std::string name, unsigned int money, unsigned int bet);
    [[nodiscard]] double equity() const noexcept;
    void set_equity(double equity) noexcept;
    [[nodiscard]] std::vector<omp::CardRange> get_bot_hand(int num_of_players) const noexcept;
    omp::EquityCalculator calc;
    void calc_equity(const std::string& board_cards, int num_of_players);
    int make_decision(unsigned int money_to_bet, unsigned int num_of_players, const std::string& board_cards, bool can_check,bool is_bluffing = true);
    unsigned int make_bluff(unsigned int money_to_bet, unsigned int num_of_players, const std::string& board_cards);
};

