#include "GameHandler.h"

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);

    
    window->createWidgets(window, game_info.player_count, game_info.initial_money, game_info.player_name);

    window->show();
}

GameHandler::~GameHandler() {
	delete window;
}

GameHandler::GameHandler(): window(new MainWindow(nullptr)) 
{
}