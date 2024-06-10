#pragma once
#include "CardCollection.h"
#include "Card.h"
#include <memory>

template <typename Ptr>
class Deck : public CardCollection<Ptr> {
private:
    void populate() {
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 4; ++j) {
                this->add_card(std::make_unique<Card>(static_cast<Suit>(j), static_cast<Value>(i)));
            }
        }
    }
public:
    Deck() = default;
    Deck(bool populate) {
        if (populate) {
            this->populate();
            this->shuffle();
            }
    };

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(this->begin(), this->end(), g);
    }
};