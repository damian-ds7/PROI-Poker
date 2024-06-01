#pragma once
#include <memory>
#include "Game.h"
#include "GameInfo.h"
#include "MainWindow.h"


class GameHandler {
public:
    GameHandler();
    void initialize_game(const GameInfo& game_info);
    ~GameHandler();

private:
    std::unique_ptr<Game> game;
    MainWindow* window;
};