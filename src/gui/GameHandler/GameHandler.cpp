#include "GameHandler.h"

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);
    this->game_info = game_info;
}

void GameHandler::start_game() {
	game->deal();
}

void GameHandler::player_make_call() {
	//TODO
}