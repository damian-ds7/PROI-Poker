#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string name, unsigned int money, unsigned int bet) : Player(std::move(name), money, bet) {}