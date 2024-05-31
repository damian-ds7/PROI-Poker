#pragma once
#include <memory>
#include "Game.h"
#include "GameInfo.h"


class GameHandler {
public:
    GameHandler() = default;
    void initialize_game(GameInfo game_info);
private:
    std::unique_ptr<Game> game;
};