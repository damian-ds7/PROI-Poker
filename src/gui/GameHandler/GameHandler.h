#pragma once
#include <memory>
#include "Game.h"
#include "GameInfo.h"
#include "MainWindow.h"


class GameHandler {
public:
    GameHandler() = default;
    void initialize_game(const GameInfo& game_info);
private:
    std::unique_ptr<Game> game;
    std::unique_ptr<MainWindow> window;
};