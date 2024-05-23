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

TEST(CardTest, CardComparison) {
Card card1(Suit::Spades, Value::Ace);
Card card2(Suit::Hearts, Value::Ace);
Card card3(Suit::Spades, Value::King);
Card card4(Suit::Hearts, Value::King);
Card card5(Suit::Spades, Value::Queen);
Card card6(Suit::Hearts, Value::Queen);
Card card7(Suit::Spades, Value::Jack);
Card card8(Suit::Hearts, Value::Jack);
Card card9(Suit::Spades, Value::Ten);
Card card10(Suit::Hearts, Value::Ten);
Card card11(Suit::Spades, Value::Nine);
Card card12(Suit::Hearts, Value::Nine);
Card card13(Suit::Spades, Value::Eight);
Card card14(Suit::Hearts, Value::Eight);
Card card15(Suit::Spades, Value::Seven);
Card card16(Suit::Hearts, Value::Seven);
Card card17(Suit::Spades, Value::Six);
Card card18(Suit::Hearts, Value::Six);
Card card19(Suit::Spades, Value::Five);
Card card20(Suit::Hearts, Value::Five);
Card card21(Suit::Spades, Value::Four);
Card card22(Suit::Hearts, Value::Four);
Card card23(Suit::Spades, Value::Three);
Card card24(Suit::Hearts, Value::Three);
Card card25(Suit::Spades, Value::Two);
Card card26(Suit::Hearts, Value::Two);

EXPECT_EQ(card1, card2);
EXPECT_EQ(card3, card4);
EXPECT_EQ(card5, card6);
EXPECT_EQ(card7, card8);
EXPECT_EQ(card9, card10);
EXPECT_EQ(card11, card12);
EXPECT_EQ(card13, card14);
EXPECT_EQ(card15, card16);
EXPECT_EQ(card17, card18);
EXPECT_EQ(card19, card20);
EXPECT_EQ(card21, card22);
EXPECT_EQ(card23, card24);
EXPECT_EQ(card25, card26);

EXPECT_NE(card1, card3);
EXPECT_NE(card1, card5);
EXPECT_NE(card1, card7);
EXPECT_NE(card1, card9);
EXPECT_NE(card1, card11);
EXPECT_NE(card1, card13);
EXPECT_NE(card1, card15);
EXPECT_NE(card1, card17);
EXPECT_NE(card1, card19);
EXPECT_NE(card1, card21);
EXPECT_NE(card1, card23);
EXPECT_NE(card1, card25);
}

TEST(CardTest, CardIndex) {
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            Card card(static_cast<Suit>(j), static_cast<Value>(i));
            EXPECT_EQ(card.card_index(), 4 * i + j);
        }
    }
}