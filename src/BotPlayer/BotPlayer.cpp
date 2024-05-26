#include "BotPlayer.h"

BotPlayer::BotPlayer(std::string name, unsigned int money, unsigned int bet) : Player(name, money, bet) {
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
    uint64_t board = omp::CardRange::getCardMask(board_cards);
    calc.start(get_bot_hand(num_of_players), board);
    calc.wait();
    auto r = calc.getResults();
    m_equity = r.equity[0];
}