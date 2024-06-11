#include "Card.h"
#include "gtest/gtest.h"

TEST(CardTest, CardCreate){
    Card card1(Suit::Spades, Value::Ace);
    Card card2(Suit::Hearts, Value::Ace);
    Card card3(Suit::Diamonds, Value::Ace);
    Card card4(Suit::Clubs, Value::Ace);

    EXPECT_EQ(card1.suit(), Suit::Spades);
    EXPECT_EQ(card1.value(), Value::Ace);
    EXPECT_EQ(card2.suit(), Suit::Hearts);
    EXPECT_EQ(card2.value(), Value::Ace);
    EXPECT_EQ(card3.suit(), Suit::Diamonds);
    EXPECT_EQ(card3.value(), Value::Ace);
    EXPECT_EQ(card4.suit(), Suit::Clubs);
    EXPECT_EQ(card4.value(), Value::Ace);
}

TEST(CardTest, CardIndex) {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            Card card(static_cast<Suit>(j), static_cast<Value>(i));
            EXPECT_EQ(card.card_index(), 4 * i + j);
        }
    }
}

TEST(CardTest, CardToString) {
    Card card1(Suit::Spades, Value::Ace);
    Card card2(Suit::Hearts, Value::Three);
    Card card3(Suit::Diamonds, Value::Queen);
    Card card4(Suit::Clubs, Value::Ten);

    EXPECT_EQ(card1.to_string(), "As");
    EXPECT_EQ(card2.to_string(), "3h");
    EXPECT_EQ(card3.to_string(), "Qd");
    EXPECT_EQ(card4.to_string(), "10c");
}

TEST(CardTest, CardGetFileName){
    Card card1(Suit::Spades, Value::Ace);
    Card card2(Suit::Hearts, Value::Three);
    Card card3(Suit::Diamonds, Value::Queen);
    Card card4(Suit::Clubs, Value::Ten);

    EXPECT_EQ(card1.get_file_path(), ":/resources/Deck/spades_ace.png");
    EXPECT_EQ(card2.get_file_path(), ":/resources/Deck/hearts_three.png");
    EXPECT_EQ(card3.get_file_path(), ":/resources/Deck/diamonds_queen.png");
    EXPECT_EQ(card4.get_file_path(), ":/resources/Deck/clubs_ten.png");
}