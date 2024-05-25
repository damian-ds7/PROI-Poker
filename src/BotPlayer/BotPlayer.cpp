#include "BotPlayer.h"

BotPlayer::BotPlayer(std::string name, unsigned int money, unsigned int bet) : Player(name, money, bet) {};


std::vector<std::vector<std::string>> BotPlayer::get_bot_hand() const noexcept {
    std::vector<std::string> hand;
    for (auto& card : *m_hand) {
        hand.push_back(card->to_string());
    }
    std::vector<std::vector<std::string>> result = {hand};
    return result;
}
/*std::vector<string> BotPlayer::get_table_hand() const noexcept {
    std::vector<string> hand;
    for (auto& card : *m_table) {
        hand.push_back(card->to_string());
    }
    return hand;
}*/
