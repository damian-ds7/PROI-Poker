#include "GameHandler.h"

bool GameHandler::finished() const noexcept {
    return this->m_finished;
}

void GameHandler::set_finished(bool finished) noexcept {
    this->m_finished = finished;
}

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

unsigned int GameHandler::previous_bet() const noexcept {
    int idx = current_player() - 1;
    if (idx < 0) idx += player_count();
    return player(idx)->bet();
}

std::string GameHandler::player_name() const noexcept {
    return game_info.player_name;
}

bool GameHandler::can_check() const noexcept {
    return game->can_check;
}

const std::unique_ptr<Player> & GameHandler::player(int index) const {
    return game->players[index];
}

const std::unique_ptr<Card>& GameHandler::get_table_card(int index) {
    return game->table->at(index);
}

const std::unique_ptr<Card>& GameHandler::get_player_hand(int player_index, int card_index) {
    return player(player_index)->get_hand_card(card_index);
}

unsigned int GameHandler::dealer() {
    return game->dealer;
}

void GameHandler::initialize_game(const GameInfo& game_info) {
    game = std::make_unique<Game>(game_info.player_name, game_info.player_count, game_info.initial_money);
    this->game_info = game_info;
}

void GameHandler::start_game() {
	game->deal();
}

void GameHandler::finish_game() {
    game->find_winner();
    game->share_pot();
    game->delete_broke_players();
    game->restart_game();
}

void GameHandler::play_turn(Decision player_decision, int player_bet) {
//    if (game->players[current_player()]->all_in() && player_decision != Decision::Fold) {
//        player_decision = Decision::Call;
//        player_bet = previous_bet();
//    }
    game->make_move(player_decision, player_bet);
    if (game->phase == Phase::Showdown || game->currently_playing == 1) {
        game->collect_bets();
        finish_game();
        set_finished(true);
        if (game->currently_playing == 1) {
            initialize_game(game_info);
        }
        return;
    }
}

void GameHandler::make_big_blind() {
    play_turn(Decision(6), 2*previous_bet());
    game->reset_initial_status();
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
    return game->players[index]->status();
}

QString GameHandler::cash_to_QString(unsigned int cash) {
	return QString(std::to_string(cash).append("$").c_str());
}

unsigned int GameHandler::previous_bet() {
    return game->get_previous_bet();
}