#pragma once
#include <random>
#include <algorithm>
#include <cstddef>
#include <deque>
#include "Card.h"

template <typename Ptr>
class CardCollection : public std::deque<Ptr>{
public:
    CardCollection() = default;
    CardCollection(std::deque<Ptr> cards) : std::deque<Ptr>(cards) {};
    virtual ~CardCollection() = default;
    CardCollection(const CardCollection<Ptr>&) = default;
    CardCollection(CardCollection<Ptr>&&) = default;

    virtual void add_card(Ptr&& card) {
        std::deque<Ptr>::push_back(std::move(card));
    }

    virtual void add_card(const Ptr& card) {
        std::deque<Ptr>::push_back(card);
    }

    virtual Ptr remove_card() {
        Ptr card = std::move(std::deque<Ptr>::front());
        std::deque<Ptr>::pop_front();
        return card;
    }
};