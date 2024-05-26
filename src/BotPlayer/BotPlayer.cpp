#include "BotPlayer.h"

#include <utility>

BotPlayer::BotPlayer(std::string name, unsigned int money, unsigned int bet) : Player(std::move(name), money, bet) {
    m_equity = 0;
};

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

void BotPlayer::make_decision(unsigned int biggest_bet, int num_of_players){
    if (equity() > 1.0 / static_cast<double>(num_of_players)) {
        (money() <= biggest_bet) ? make_all_in() : make_raise(biggest_bet + (money() - biggest_bet) * equity());
    } else if (equity() < 0.5 / static_cast<double>(num_of_players)) {
        make_fold();
    } else {
        (money() <= biggest_bet) ? make_all_in() : make_call(biggest_bet);
    }
}