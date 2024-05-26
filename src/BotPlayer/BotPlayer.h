#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include "EquityCalculator.h"
#include "CardRange.h"


class BotPlayer : public Player{
    double m_equity;
public:
    BotPlayer(std::string name, unsigned int money, unsigned int bet);
    [[nodiscard]] double equity() const noexcept;
    void set_equity(double equity) noexcept;
    [[nodiscard]] std::vector<omp::CardRange> get_bot_hand(int num_of_players) const noexcept;
    omp::EquityCalculator calc;
    void calc_equity(const std::string& board_cards, int num_of_players);
    void make_decision();
    //[[nodiscard]] std::vector<string> get_table_hand() const noexcept;
};

