#pragma once
#include "CardCollection.h"

template <typename Ptr>
class Deck : public CardCollection<Ptr> {
public:
    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->begin(), this->end(), g);
    }
};