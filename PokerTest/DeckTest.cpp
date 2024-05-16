#include "Deck.h"
#include "Card.h"
#include "gtest/gtest.h"
#include <memory>

TEST(DeckTest, DeckCreate) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    EXPECT_EQ(deck.size(), 0);
}

TEST(DeckTest, DeckInsert) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    EXPECT_EQ(deck.size(), 1);
}

TEST(DeckTest, DeckPop) {
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    auto card = deck.pop();
    EXPECT_EQ(deck.size(), 0);
    EXPECT_EQ(card->value(), Value::Ace);
}

TEST(DeckTest, DeckSize){
    Deck<std::vector, std::unique_ptr<Card>> deck;
    EXPECT_EQ(deck.size(), 0);
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Two));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Three));
    EXPECT_EQ(deck.size(), 3);
}

TEST(DeckTest, DeckShuffle){
    Deck<std::vector, std::unique_ptr<Card>> deck;
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Two));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Three));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Four));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Five));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Six));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Seven));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Eight));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Nine));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Ten));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Jack));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::Queen));
    deck.insert(std::make_unique<Card>(Suit::Hearts, Value::King));
    deck.shuffle();
    EXPECT_EQ(deck.size(), 13);
}
