#pragma once
#include <string>
#include "CardCollection.h"
#include <memory>
#include "Hand.h"

class Player {
    std::string m_name;
    unsigned int m_money;
    unsigned int m_bet;
    bool m_folded;
    bool m_all_in;
    bool m_big_blind;
    bool m_small_blind;
    bool m_dealer;
    Hand<std::unique_ptr<Card>> m_hand;
public:
    Player(std::string name, unsigned int money, unsigned int bet, bool folded,
           bool all_in, bool big_blind, bool small_blind, bool dealer);
    virtual ~Player() = default;
    [[nodiscard]] virtual std::string name() const noexcept;
    [[nodiscard]] virtual unsigned int money() const noexcept;
    [[nodiscard]] virtual unsigned int bet() const noexcept;
    [[nodiscard]] virtual bool folded() const noexcept;
    [[nodiscard]] virtual bool all_in() const noexcept;
    [[nodiscard]] virtual bool big_blind() const noexcept;
    [[nodiscard]] virtual bool small_blind() const noexcept;
    [[nodiscard]] virtual bool dealer() const noexcept;
    virtual void set_name(std::string name);
    virtual void set_money(unsigned int money);
    virtual void set_bet(unsigned int bet);
    virtual void set_folded(bool folded);
    virtual void set_all_in(bool all_in);
    virtual void set_big_blind(bool big_blind);
    virtual void set_small_blind(bool small_blind);
    virtual void set_dealer(bool dealer);
    virtual void add_card(std::unique_ptr<Card>&& card);
    virtual std::unique_ptr<Card> pop_card();
};

