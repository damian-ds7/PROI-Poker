#pragma once
#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string name, unsigned int money, unsigned int bet);
};