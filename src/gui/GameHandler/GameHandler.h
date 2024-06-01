#pragma once
#include <memory>
#include "Game.h"
#include "GameInfo.h"
#include "MainWindow.h"


class GameHandler {
public:
    GameHandler() = default;
    void initialize_game(const GameInfo& game_info);
    void start_game();
    void player_make_call();
private:
    std::unique_ptr<Game> game;
    GameInfo game_info;

    friend class MainWindow;
};