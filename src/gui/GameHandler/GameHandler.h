#pragma once
#include <memory>
#include <vector>
#include <QString>
#include "Game.h"
#include "GameInfo.h"
#include "Decision.h"


class GameHandler {
public:
    GameHandler() = default;

    [[nodiscard]] bool finished() const noexcept;
    [[nodiscard]] bool one_player() const noexcept;

    void set_finished(bool finished) noexcept;
    void set_one_player(bool one_player) noexcept;

    [[nodiscard]] unsigned int player_count() const noexcept;
    [[nodiscard]] unsigned int currently_playing() const noexcept;
    [[nodiscard]] unsigned int current_player() const noexcept;
    [[nodiscard]] unsigned int pot() const noexcept;
    [[nodiscard]] unsigned int initial_money() const noexcept;
    [[nodiscard]] unsigned int previous_bet() const noexcept;
    [[nodiscard]] std::string player_name() const noexcept;
    [[nodiscard]] bool can_check() const noexcept;
    [[nodiscard]] const std::unique_ptr<Player> & player(int index) const;
    [[nodiscard]] const std::unique_ptr<Card>& get_table_card(int index);
    [[nodiscard]] const std::unique_ptr<Card>& get_player_hand(int player_index, int card_index);
    [[nodiscard]] unsigned int dealer();
    void initialize_game(const GameInfo& game_info);
    void start_game();
    void finish_game();
    void play_turn(Decision player_decision, int player_bet);
    void make_big_blind();

    int phase_to_int();
    std::string current_player_to_string();
    std::string name_to_string(int index);
    std::string status_to_string(int index);
    QString cash_to_QString(unsigned int cash);
    unsigned int previous_bet();
private:
    std::unique_ptr<Game> game;
    GameInfo game_info;
    bool m_finished = false;
    bool m_one_player = false;

    friend class MainWindow;
};