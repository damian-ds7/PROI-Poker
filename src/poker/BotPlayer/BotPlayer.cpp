#include "BotPlayer.h"

#include <utility>

BotPlayer::BotPlayer(std::string name, unsigned int money, unsigned int bet) : Player(std::move(name), money, bet) {
    m_equity = 0;
    engine = std::mt19937(rd());
    dist = std::uniform_int_distribution<int>(0, 1000);
};

bool BotPlayer::has_enough_money(unsigned int money_to_bet) const noexcept {
    return money() >= money_to_bet;
}

double BotPlayer::equity() const noexcept {
    return m_equity;
}

void BotPlayer::set_equity(double equity) noexcept {
    m_equity = equity;
}

std::vector<omp::CardRange> BotPlayer::get_bot_hand(int num_of_players) const noexcept {
    std::string hand;
    for (auto& card : *m_hand) {
        hand += card->to_string();
    }
    switch(num_of_players){
        case 2:
            return {hand, "random"};
        case 3:
            return {hand, "random", "random"};
        case 4:
            return {hand, "random", "random", "random"};
        case 5:
            return {hand, "random", "random", "random", "random"};
        case 6:
            return {hand, "random", "random", "random", "random", "random"};
        default:
            return {hand};
    }
}

void BotPlayer::calc_equity(const std::string& board_cards, int num_of_players){
    uint64_t board =(board_cards == "0") ? 0 : omp::CardRange::getCardMask(board_cards);
    calc.start(get_bot_hand(num_of_players), board);
    calc.wait();
    auto r = calc.getResults();
    set_equity(r.equity[0]);
}

int BotPlayer::make_decision(unsigned int money_to_bet, unsigned int num_of_players, const std::string& board_cards, bool can_check, bool is_bluffing) {
    int result = 0;
    if (small_blind()) {
        return money() / 20;
    }
    if (big_blind()){
        return money_to_bet * 2;
    }
    calc_equity(board_cards, num_of_players);
    if(money_to_bet == 0 && can_check){
        auto random_number = dist(engine);
        if(random_number % 2 == 0) {
            return 0;
        } else {
            auto rand = dist(engine) % 10 + 4;
            int money_divided_by_rand = money() / rand;
            int floored_to_closest_10 = (money_divided_by_rand / 10) * 10;
            return floored_to_closest_10;
        }
    } else if ( equity() < 0.5 / static_cast<double>(num_of_players)){ //fold
        result = -1;
        return result;
    } else if (equity() > 1.0 / static_cast<double>(num_of_players)) { // raise or call
        auto random_number = dist(engine);
        if (random_number % 4 == 0) { // raise
            result = (has_enough_money(money_to_bet - bet())) ? money_to_bet + static_cast<int>(((money() - money_to_bet) * equity())) : money();
        }
        else{ // call
            result = (has_enough_money(money_to_bet - bet())) ? money_to_bet : money();
            return result;
        }
    } else { // call
        result = (has_enough_money(money_to_bet - bet())) ? money_to_bet : money();
        return result;
    }
    if (result > money_to_bet && result < money()){
        auto percent_of_money = (money() - money_to_bet) / 100;
        auto random_number = dist(engine) % 30 + 5;
        result = (has_enough_money(money_to_bet - bet())) ? ((money_to_bet + percent_of_money * random_number) / 10 * 10) : money();
    }
    else {
        result = (result < money()) ? result : money();
    }
    return result;
}

unsigned int BotPlayer::make_bluff(unsigned int money_to_bet, unsigned int num_of_players, const std::string&) {
    //make_raise(money_to_bet + static_cast<int>((money() - money_to_bet) * 0.5));
    return money_to_bet + static_cast<int>((money() - money_to_bet) * 0.5);
}