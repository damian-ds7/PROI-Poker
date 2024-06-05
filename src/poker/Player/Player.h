#pragma once
#include <string>
#include "CardCollection.h"
#include <memory>
#include "Hand.h"
#include "CardsTypedef.h"
#include "HandEvaluator.h"

class Player {
protected:
    std::string m_name;
    unsigned int m_money;
    unsigned int m_bet;
    bool m_folded = false;
    bool m_all_in = false;
    bool m_big_blind = false;
    bool m_small_blind = false;
    bool m_dealer = false;
    bool m_can_check = true;
    bool m_called = false;
    bool m_raised = false;
    bool m_checked = false;
    std::string m_status;
    Cards m_hand = std::make_unique<Hand<std::unique_ptr<Card>>>();
    omp::Hand card_eval = omp::Hand::empty();
    virtual void make_helper(unsigned money);
public:
    Player(std::string name, unsigned int money, unsigned int bet);
    virtual ~Player() = default;
    [[nodiscard]] virtual std::string name() const noexcept;
    [[nodiscard]] virtual unsigned int money() const noexcept;
    [[nodiscard]] virtual unsigned int bet() const noexcept;
    [[nodiscard]] virtual bool folded() const noexcept;
    [[nodiscard]] virtual bool all_in() const noexcept;
    [[nodiscard]] virtual bool big_blind() const noexcept;
    [[nodiscard]] virtual bool small_blind() const noexcept;
    [[nodiscard]] virtual bool dealer() const noexcept;
    [[nodiscard]] virtual bool can_check() const noexcept;
    [[nodiscard]] virtual bool called() const noexcept;
    [[nodiscard]] virtual bool raised() const noexcept;
    [[nodiscard]] virtual bool checked() const noexcept;
    [[nodiscard]] virtual std::string status() const noexcept;
    [[nodiscard]] unsigned int evaluate() const noexcept;
    virtual void set_name(std::string name);
    virtual void set_money(unsigned int money);
    virtual void set_bet(unsigned int bet);
    virtual void set_folded(bool folded);
    virtual void set_all_in(bool all_in);
    virtual void set_big_blind(bool big_blind);
    virtual void set_small_blind(bool small_blind);
    virtual void set_dealer(bool dealer);
    virtual void set_can_check(bool can_check);
    virtual void set_called(bool called);
    virtual void set_raised(bool raised);
    virtual void set_checked(bool checked);
    virtual void reset_status();
    virtual void add_card(std::unique_ptr<Card>&& card);
    virtual void add_table_card(unsigned int index);
    virtual void make_bet(unsigned bet);
    virtual void make_raise(unsigned raise);
    virtual void make_call(unsigned call);
    virtual void make_fold();
    virtual void make_all_in();
    virtual void make_check();
    virtual unsigned int remove_bet() noexcept;
    Cards&& clear_hand() noexcept;
protected:
    static omp::HandEvaluator eval;

    friend class MainWindow;
};

