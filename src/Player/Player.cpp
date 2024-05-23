#include "Player.h"

Player::Player(std::string name, unsigned int money, unsigned int bet) :
    m_name(std::move(name)), m_money(money), m_bet(bet) {};

std::string Player::name() const noexcept {
    return m_name;
}

unsigned int Player::money() const noexcept {
    return m_money;
}

unsigned int Player::bet() const noexcept {
    return m_bet;
}

bool Player::folded() const noexcept {
    return m_folded;
}

bool Player::all_in() const noexcept {
    return m_all_in;
}

bool Player::big_blind() const noexcept {
    return m_big_blind;
}

bool Player::small_blind() const noexcept {
    return m_small_blind;
}

bool Player::dealer() const noexcept {
    return m_dealer;
}

void Player::set_name(std::string name) {
    m_name = std::move(name);
}

void Player::set_money(unsigned int money) {
    m_money = money;
}

void Player::set_bet(unsigned int bet) {
    m_bet = bet;
}

void Player::set_folded(bool folded) {
    m_folded = folded;
}

void Player::set_all_in(bool all_in) {
    m_all_in = all_in;
}

void Player::set_big_blind(bool big_blind) {
    m_big_blind = big_blind;
}

void Player::set_small_blind(bool small_blind) {
    m_small_blind = small_blind;
}

void Player::set_dealer(bool dealer) {
    m_dealer = dealer;
}

void Player::add_card(std::unique_ptr<Card>&& card) {
    m_hand->add_card(std::move(card));
}

Cards&& Player::clear_hand() noexcept {
    return std::move(m_hand);
}