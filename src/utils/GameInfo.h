#pragma once
#include <string>

struct GameInfo {
    GameInfo(std::string name, int count, int money);
    GameInfo() = default;
    std::string player_name;
    int player_count = 0;
    int initial_money = 0;
};