#include "Deck.h"
#include "Card.h"
#include "gtest/gtest.h"
#include <memory>
#include "constants.h"



TEST(DeckTest, DeckCreate) {
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>();
    EXPECT_EQ(deck->size(), 0);
}

TEST(DeckTest, DeckAddCard) {
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>();
    deck->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    EXPECT_EQ(deck->size(), 1);
}

TEST(DeckTest, DeckRemoveCard) {
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>();
    deck->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    auto card = deck->remove_card();
    EXPECT_EQ(deck->size(), 0);
    EXPECT_EQ(card->value(), Value::Ace);
}

TEST(DeckTest, DeckSize){
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>();
    EXPECT_EQ(deck->size(), 0);
    deck->add_card(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    deck->add_card(std::make_unique<Card>(Suit::Hearts, Value::Two));
    deck->add_card(std::make_unique<Card>(Suit::Hearts, Value::Three));
    EXPECT_EQ(deck->size(), 3);
}

TEST(DeckTest, DeckShuffle){
    Cards deck = std::make_unique<Deck<std::unique_ptr<Card>>>();
    for (int i = 2; i <= 14; ++i) {
        deck->add_card(std::make_unique<Card>(Suit::Hearts, static_cast<Value>(i)));
    }
    dynamic_cast<Deck<std::unique_ptr<Card>>*>(deck.get())->shuffle();
    EXPECT_EQ(deck->size(), 13);
}
