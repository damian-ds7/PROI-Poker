#pragma once
#include "Player.h"
#include "simulator.h"


class BotPlayer : public Player{
    double m_probability;
    Simulator m_simulator;
public:
    BotPlayer(std::string name, unsigned int money, unsigned int bet);
    double get_probability();
    void make_decision();
};

