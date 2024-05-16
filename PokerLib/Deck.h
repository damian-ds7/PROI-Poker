#pragma once
#include <random>
#include <algorithm>
#include <cstddef>
#include "Card.h"

template <template<typename...> class Collection, typename Ptr>
class Deck : public Collection<Ptr>{
public:
    Deck() = default;
    Deck(Collection<Ptr> cards) : Collection<Ptr>(cards) {};

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->begin(), this->end(), g);
    }
};