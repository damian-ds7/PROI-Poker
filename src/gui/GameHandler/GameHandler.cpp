#include "GameHandler.h"

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);
    this->game_info = game_info;
}

void GameHandler::start_game() {
    if (game->current_player != 0) {
        game->bot_play();
    }
    unsigned int previous_bet = game->players[(game->current_player - 1) % game->player_count]->bet();
    game->players[game->current_player]->make_bet(2 * previous_bet);
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

void GameHandler::play_round(Decision player_decision, int player_bet) {
    switch (player_decision) {
        case Decision::Bot:
        {
            game->bot_play();
            break;
        }
        case Decision::Raise:
        {
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
            break;
        }
        game->next_player();
        
    }

}

int GameHandler::phase_to_int() {
	return static_cast<int>(game->phase);
}

std::string GameHandler::current_player_to_string() {
	return game->players[game->current_player]->name();
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

std::string GameHandler::begin_status_to_string(int index) {
//	if (game->players[index]->big_blind()) return "BIG B";
//	if (game->players[index]->small_blind()) return "SMALL B";
//	if (game->players[index]->dealer()) return "DEALER";
//	return "";
return game->players[index]->status();
}

QString GameHandler::cash_to_QString(int cash) {
	return QString(std::to_string(cash).append("$").c_str());
}