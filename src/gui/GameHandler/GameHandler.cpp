#include "GameHandler.h"

unsigned int GameHandler::player_count() const noexcept {
    return game->player_count;
}

unsigned int GameHandler::currently_playing() const noexcept {
    return game->currently_playing;
}

unsigned int GameHandler::current_player() const noexcept {
    return game->current_player;
}

unsigned int GameHandler::pot() const noexcept {
    return game->pot;
}

unsigned int GameHandler::initial_money() const noexcept {
    return game_info.initial_money;
}

std::string GameHandler::player_name() const noexcept {
    return game_info.player_name;
}

const std::unique_ptr<Player>& GameHandler::player(int index) {
    return game->players[index];
}

const std::unique_ptr<Card>& GameHandler::get_table_card(int index) {
    return game->table->at(index);
}

const std::unique_ptr<Card>& GameHandler::get_player_hand(int player_index, int card_index) {
    return player(player_index)->get_hand_card(card_index);
}

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);
    this->game_info = game_info;
}

void GameHandler::start_game() {
//    if (game->current_player != 0) {
//        game->bot_play();
//    }
//    game->next_player();

    int idx = current_player() - 1;
    if (idx < 0) idx += player_count();
    unsigned int previous_bet = player(idx)->bet();
    game->players[current_player()]->make_bet(2 * previous_bet);
    game->next_player();
	game->deal();
//	game->next_player();
//	game->players[game->current_player]->make_bet(10); //small blind
//	game->next_player();
//	game->players[game->current_player]->make_bet(20); //big blind
//	game->next_player();
}

void GameHandler::player_make_call() {
	//TODO
}

void GameHandler::play_turn(Decision player_decision, int player_bet) {
    switch (player_decision) {
    case Decision::Bot:
    {
        game->bot_play();
        break;
    }
    case Decision::Raise:
    {
        //if big blind dont't change status
        break;
    }
    case Decision::Fold:
    {
        break;
    }
    case Decision::Check:
    {
        break;
    }
    case Decision::Call:
    {
        break;
    }
    case Decision::AllIn:
    {
        break;
    }
    case Decision::Bet:
    {
        //if small blind dont't change status
        break;
    }
    }
    game->next_player();
}

void GameHandler::make_big_blind() {
    if (game->current_player != 0) {
		play_turn(Decision(0), 0);
	}
    else
    {
        play_turn(Decision(1), 2*previous_bet());
    }
}

int GameHandler::phase_to_int() {
	return static_cast<int>(game->phase);
}

std::string GameHandler::current_player_to_string() {
	return game->players[current_player()]->name();
}

std::string GameHandler::name_to_string(int index) {
	return game->players[index]->name();
}

std::string GameHandler::status_to_string(int index) {
//	if (game->players[index]->folded()) return "FOLD";
//	if (game->players[index]->all_in()) return "ALL IN";
//	//call
//	//raise
//	//check
//	//bet
//	return "";
    return game->players[index]->status();
}

QString GameHandler::cash_to_QString(int cash) {
	return QString(std::to_string(cash).append("$").c_str());
}

int GameHandler::previous_bet() {
	return game->players[(game->current_player - 1) % game->player_count]->bet();
}