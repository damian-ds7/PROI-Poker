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

unsigned int Player::sum_bet() const noexcept {
    return m_sum_bet;
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

bool Player::called() const noexcept {
    return m_called;
}

bool Player::raised() const noexcept {
    return m_raised;
}

bool Player::checked() const noexcept {
    return m_checked;
}

std::string Player::status() const noexcept {
    return m_status;
}

unsigned int Player::evaluate() const noexcept {
    return eval.evaluate(card_eval);
}

const std::unique_ptr<Card>& Player::get_hand_card(int index) {
    return m_hand->at(index);
}

void Player::set_name(std::string name) {
    m_name = std::move(name);
}

void Player::set_money(unsigned int money) {
    m_money = money;
}

void Player::set_bet(unsigned int bet) {
    m_bet = bet;
    m_sum_bet += bet;
}

void Player::set_folded(bool folded) {
    m_folded = folded;
    if (folded) {
        m_status = "FOLD";
    }
}

void Player::set_all_in(bool all_in) {
    m_all_in = all_in;
    if (all_in) {
        m_status = "ALL IN";
    }

}

void Player::set_big_blind(bool big_blind) {
    m_big_blind = big_blind;
    if (big_blind) {
        m_status = "BIG B";
    } else {
        m_status = "";
    }

}

void Player::set_small_blind(bool small_blind) {
    m_small_blind = small_blind;
    if (small_blind) {
        m_status = "SMALL B";
    } else {
        m_status = "";
    }
}

void Player::set_dealer(bool dealer) {
    m_dealer = dealer;
    if (dealer) {
        m_status = "DEALER";
    } else {
        m_status = "";
    }
}

void Player::set_called(bool called) {
    m_called = called;
    if (called) {
        m_status = "CALL";
    }
}

void Player::set_raised(bool raised) {
    m_raised = raised;
    if (raised) {
        m_status = "RAISE";
    }
}

void Player::set_checked(bool checked) {
    m_checked = checked;
    if (checked) {
        m_status = "CHECK";
    }
}

//void Player::reset_status() {
//    m_status = "";
//    set_small_blind(false);
//    set_big_blind(false);
//    set_dealer(false);
//}

void Player::make_helper(unsigned money) {
    m_money -= money;
    m_bet += money;
    m_sum_bet += money;
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
    set_raised(true);
    raise -= m_bet;
    make_helper(raise);
}

void Player::make_call(unsigned previous_bet) {
    set_called(true);
    previous_bet -= m_bet;
    make_helper(previous_bet);
}

void Player::make_fold() {
    set_folded(true);
}

void Player::make_all_in() {
    set_all_in(true);
    make_helper(m_money);
}

void Player::make_check() {
    set_checked(true);
    // Do nothing.
}

unsigned int Player::remove_bet() noexcept {
    unsigned int bet = m_bet;
    m_bet = 0;
    return bet;
}

std::deque<std::unique_ptr<Card>> Player::clear_hand() noexcept {
    std::deque<std::unique_ptr<Card>> temp;
    for (auto& card : *m_hand) {
        temp.push_back(std::move(card));
        m_hand->pop_front();
    }
    return std::move(temp);
}

void Player::reset_after_phase() noexcept {
    m_bet = 0;
    set_called(false);
    set_raised(false);
    set_checked(false);
    set_all_in(false);
    set_small_blind(false);
    set_big_blind(false);
    set_dealer(false);
    m_status = "";
}

omp::HandEvaluator Player::eval;