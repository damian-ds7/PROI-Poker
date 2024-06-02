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