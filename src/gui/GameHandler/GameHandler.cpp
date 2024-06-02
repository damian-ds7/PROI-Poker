#include "GameHandler.h"

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);
    this->game_info = game_info;
}

void GameHandler::start_game() {
	game->deal();
	game->next_player();
	game->players[game->current_player]->make_bet(10); //small blind
	game->next_player();
	game->players[game->current_player]->make_bet(20); //big blind
	game->next_player();
}

void GameHandler::player_make_call() {
	//TODO
}

void GameHandler::play_round() {
	/*game->next_player();*/

}

int GameHandler::phase_to_int() {
	switch (game->phase) {
	case Phase::PreFlop:
		return 0;
	case Phase::Flop:
		return 1;
	case Phase::Turn:
		return 2;
	case Phase::River:
		return 3;
	case Phase::Showdown:
		return 4;
	}
}

std::string GameHandler::current_player_to_string() {
	return game->players[game->current_player]->name();
}

std::string GameHandler::name_to_string(int index) {
	return game->players[index]->name();
}

std::string GameHandler::status_to_string(int index) {
	if (game->players[index]->folded()) return "FOLD";
	if (game->players[index]->all_in()) return "ALL IN";
	//call
	//raise
	//check
	//bet
	return "";
}

std::string GameHandler::begin_status_to_string(int index) {
	if (game->players[index]->big_blind()) return "BIG B";
	if (game->players[index]->small_blind()) return "SMALL B";
	if (game->players[index]->dealer()) return "DEALER";
	return "";
}