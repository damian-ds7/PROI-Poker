#pragma once
#include <vector>
#include <memory>
#include "Player.h"
#include "BotPlayer.h"
#include "HumanPlayer.h"
#include "Table.h"
#include "CardCollection.h"
#include "Card.h"
#include "Deck.h"
#include "CardsTypedef.h"
#include "Phase.h"
#include "Decision.h"
#include "Names.h"

class Game {
private:
    unsigned int player_count;
    unsigned int currently_playing;
    unsigned int current_player;
    unsigned int pot = 0;
    unsigned int smallest_allin = 0;
    unsigned int dealer;
    bool can_check = false;
    std::vector<unsigned int> winners;
    std::vector<std::unique_ptr<Player>> players;
    Cards table = std::make_unique<Table<std::unique_ptr<Card>>>();
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>(true);
    Cards discarded = std::make_unique<Table<std::unique_ptr<Card>>>();
    Phase phase = Phase::PreFlop;

    unsigned int find_active_player(unsigned int index);
public:
    Game(const std::string& name, unsigned int player_count, unsigned int initial_money);
    Game() = default;
    void add_table_card(unsigned int num_of_cards);
    void deal();
    void next_phase();
    void collect_bets();
    void next_player();
    int bot_play();
    void make_move(Decision decision, int bet = 0);
    Decision convert_bot_decision(int bet);
    void find_winner();
    bool check_round_end();
    void delete_broke_players();
    void collect_cards();
    void set_new_dealer();
    void reset_phase();
    void reset_winners();
    void reset_players_status();
    void restart_game();
    friend class MainWindow;
    friend class GameHandler;
};