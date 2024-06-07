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

int BotPlayer::make_decision(unsigned int money_to_bet, unsigned int num_of_players, const std::string& board_cards, bool is_bluffing) {
    if (small_blind()) {
        return money() / 10;
    calc_equity(board_cards, num_of_players);
    if (money_to_bet == 0 && equity() < 0.4) {
        return 0;
    } else if (equity() > 1.0 / static_cast<double>(num_of_players)) {
        return (has_enough_money(money_to_bet)) ? money_to_bet + static_cast<int>((money() - money_to_bet) * equity()) : money();
    } else if (equity() < 0.5 / static_cast<double>(num_of_players)) {
        if (is_bluffing) {
            auto random_number = dist(engine);
            if (random_number > 900) {
                return (has_enough_money(money_to_bet)) ? make_bluff(money_to_bet, num_of_players, board_cards) : money();
            } else if (random_number > 800) {
                return (has_enough_money(money_to_bet)) ? money_to_bet : money();
            } else return 0; // make fold
        }
        else{
            return -1; //make fold
        }
    } else {
        //(has_enough_money(money_to_bet)) ? make_call(money_to_bet) : make_all_in();
        return (has_enough_money(money_to_bet)) ? money_to_bet : money();
    }
}

unsigned int BotPlayer::make_bluff(unsigned int money_to_bet, unsigned int num_of_players, const std::string&) {
    //make_raise(money_to_bet + static_cast<int>((money() - money_to_bet) * 0.5));
    return money_to_bet + static_cast<int>((money() - money_to_bet) * 0.5);
}