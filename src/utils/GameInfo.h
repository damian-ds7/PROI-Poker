#pragma once
#include <string>

struct GameInfo {
    GameInfo(std::string name, int count, int money);
    std::string player_name;
    int player_count;
    int initial_money;
};