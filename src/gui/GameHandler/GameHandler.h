#pragma once
#include <memory>
#include <QString>
#include "Game.h"
#include "GameInfo.h"
#include "MainWindow.h"
#include "Decision.h"


class GameHandler {
public:
    GameHandler() = default;
    void initialize_game(const GameInfo& game_info);
    void start_game();
    void player_make_call();
    void play_round(Decision player_decision, int player_bet);

    int phase_to_int();
    std::string current_player_to_string();
    std::string name_to_string(int index);
    std::string status_to_string(int index);
    std::string begin_status_to_string(int index);
    QString cash_to_QString(int cash);

private:
    std::unique_ptr<Game> game;
    GameInfo game_info;

    friend class MainWindow;
};