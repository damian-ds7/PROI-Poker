#include "Player.h"

Player::Player(std::string name, unsigned int money, unsigned int bet) :
    m_name(std::move(name)), m_money(money), m_bet(bet) {};

std::string Player::name() const noexcept {
    return m_name;
}

void Player::make_helper(unsigned money) {
    m_money -= money;
    m_bet += money;
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

unsigned int Player::evaluate() const noexcept {
    return eval.evaluate(card_eval);
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
    card_eval += omp::Hand(card->card_index());
    m_hand->add_card(std::move(card));
}

void Player::add_table_card(unsigned int index) {
    card_eval += omp::Hand(index);
}

void Player::make_bet(unsigned bet) {
    make_helper(bet);
}

void Player::make_raise(unsigned raise) {
   make_helper(raise);
}

void Player::make_call(unsigned call) {
    make_helper(call);
}

void Player::make_fold() {
    m_folded = true;
}

void Player::make_all_in() {
    m_all_in = true;
    make_helper(m_money);
}

void Player::make_check() {
    // Do nothing.
}

Cards&& Player::clear_hand() noexcept {
    return std::move(m_hand);
}

omp::HandEvaluator Player::eval;