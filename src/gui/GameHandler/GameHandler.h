#pragma once
#include <memory>
#include <vector>
#include <QString>
#include "Game.h"
#include "GameInfo.h"
#include "MainWindow.h"
#include "Decision.h"


class GameHandler {
public:
    GameHandler() = default;

    [[nodiscard]] unsigned int player_count() const noexcept;
    [[nodiscard]] unsigned int currently_playing() const noexcept;
    [[nodiscard]] unsigned int current_player() const noexcept;
    [[nodiscard]] unsigned int pot() const noexcept;
    [[nodiscard]] unsigned int initial_money() const noexcept;
    [[nodiscard]] std::string player_name() const noexcept;
    [[nodiscard]] const std::unique_ptr<Player>& player(int index);

    void initialize_game(const GameInfo& game_info);
    void start_game();
    void player_make_call();
    void play_turn(Decision player_decision, int player_bet);

    int phase_to_int();
    std::string current_player_to_string();
    std::string name_to_string(int index);
    std::string status_to_string(int index);
    std::string begin_status_to_string(int index);

    static QString cash_to_QString(unsigned int cash);
private:
    std::unique_ptr<Game> game;
    GameInfo game_info;

    friend class MainWindow;
};