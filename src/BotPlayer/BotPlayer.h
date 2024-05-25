#pragma once
#include "Player.h"
#include <string>
#include <vector>


class BotPlayer : public Player{
public:
    BotPlayer(std::string name, unsigned int money, unsigned int bet);
    [[nodiscard]] double probability() const noexcept;
    void set_probability(double probability) noexcept;
    void count_probability(std::vector<std::string> common_cards, int num_of_players=1) noexcept;
    [[nodiscard]] std::vector<std::vector<std::string>> get_bot_hand() const noexcept;
    void make_decision();
    //[[nodiscard]] std::vector<string> get_table_hand() const noexcept;
};

