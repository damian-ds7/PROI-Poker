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
    void play_round();

    int phase_to_int();
    std::string current_player_to_string();
    std::string name_to_string(int index);
    std::string status_to_string(int index);
    std::string begin_status_to_string(int index);

private:
    std::unique_ptr<Game> game;
    GameInfo game_info;

    friend class MainWindow;
};