#include "CardCollection.h"
#include "Card.h"
#include "gtest/gtest.h"
#include <memory>

TEST(DeckTest, DeckCreate) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    EXPECT_EQ(deck.size(), 0);
}

TEST(DeckTest, DeckPush) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.push_back(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    EXPECT_EQ(deck.size(), 1);
}

TEST(DeckTest, DeckPop) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.push_back(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    auto card = std::move(deck.back());
    deck.pop_back();
    EXPECT_EQ(deck.size(), 0);
    EXPECT_EQ(card->value(), Value::Ace);
}

TEST(DeckTest, DeckSize){
    Deck<std::vector, std::unique_ptr<Card>> deck;
    EXPECT_EQ(deck.size(), 0);
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Two));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Three));
    EXPECT_EQ(deck.size(), 3);
}

TEST(DeckTest, DeckShuffle){
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Two));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Three));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Four));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Five));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Six));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Seven));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Eight));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Nine));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Ten));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Jack));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::Queen));
    deck.push_back(std::make_unique<Card>(Suit::Hearts, Value::King));
    deck.shuffle();
    EXPECT_EQ(deck.size(), 13);
}
