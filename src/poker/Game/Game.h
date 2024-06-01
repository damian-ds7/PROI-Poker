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

class Game {
private:
    unsigned int player_count;
    unsigned int current_player;
    unsigned int pot = 0;
    unsigned int dealer;
    std::vector<std::unique_ptr<Player>> players;
    Cards table = std::make_unique<Table<std::unique_ptr<Card>>>();
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>(true);
    Phase phase = Phase::PreFlop;
public:
    Game(const std::string& name, unsigned int player_count, unsigned int initial_money);
    Game() = default;
    void add_table_card(unsigned int num_of_cards);
    void deal();
    void next_phase();
    void collect_bets();
    void next_player();

    friend class MainWindow;
    friend class GameHandler;
};