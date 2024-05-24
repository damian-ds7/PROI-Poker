#include "Player.h"
#include "gtest/gtest.h"
#include "Card.h"
#include "HandEvaluator.h"

TEST(PlayerTest, Constructor) {
    Player player("Player", 1000, 0);
    EXPECT_EQ(player.name(), "Player");
    EXPECT_EQ(player.money(), 1000);
    EXPECT_EQ(player.bet(), 0);
    EXPECT_EQ(player.folded(), false);
    EXPECT_EQ(player.all_in(), false);
    EXPECT_EQ(player.big_blind(), false);
    EXPECT_EQ(player.small_blind(), false);
    EXPECT_EQ(player.dealer(), false);
}

TEST(PlayerTest, SetName) {
    Player player("Player", 1000, 0);
    player.set_name("Player2");
    EXPECT_EQ(player.name(), "Player2");
}

TEST(PlayerTest, SetMoney) {
    Player player("Player", 1000, 0);
    player.set_money(2000);
    EXPECT_EQ(player.money(), 2000);
}

TEST(PlayerTest, SetBet) {
    Player player("Player", 1000, 0);
    player.set_bet(100);
    EXPECT_EQ(player.bet(), 100);
}

TEST(PlayerTest, SetFolded) {
    Player player("Player", 1000, 0);
    player.set_folded(true);
    EXPECT_EQ(player.folded(), true);
}

TEST(PlayerTest, SetAllIn) {
    Player player("Player", 1000, 0);
    player.set_all_in(true);
    EXPECT_EQ(player.all_in(), true);
}

TEST(PlayerTest, SetBigBlind) {
    Player player("Player", 1000, 0);
    player.set_big_blind(true);
    EXPECT_EQ(player.big_blind(), true);
}

TEST(PlayerTest, SetSmallBlind) {
    Player player("Player", 1000, 0);
    player.set_small_blind(true);
    EXPECT_EQ(player.small_blind(), true);
}

TEST(PlayerTest, SetDealer) {
    Player player("Player", 1000, 0);
    player.set_dealer(true);
    EXPECT_EQ(player.dealer(), true);
}

TEST(PlayerTest, AddCard) {
    Player player("Player", 1000, 0);
    player.add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    auto card = player.clear_hand()->remove_card();
    EXPECT_EQ(card->value(), Value::Ace);
}

TEST(PlayerTest, PopCard) {
    Player player("Player", 1000, 0);
    player.add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    auto card = player.clear_hand()->remove_card();
    EXPECT_EQ(card->value(), Value::Ace);
    EXPECT_EQ(player.clear_hand()->size(), 0);
    EXPECT_EQ(card->suit(), Suit::Hearts);
}