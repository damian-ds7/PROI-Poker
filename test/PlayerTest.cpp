#include "Player.h"
#include "gtest/gtest.h"
#include "Card.h"
#include "HandEvaluator.h"

TEST(PlayerTest, Constructor) {
    Player player("Player", 1000, 0);
    EXPECT_EQ(player.name(), "Player");
    EXPECT_EQ(player.money(), 1000);
    EXPECT_EQ(player.bet(), 0);
    ASSERT_FALSE(player.folded());
    ASSERT_FALSE(player.all_in());
    ASSERT_FALSE(player.big_blind());
    ASSERT_FALSE(player.small_blind());
    ASSERT_FALSE(player.dealer());
    ASSERT_TRUE(player.can_check());
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
    ASSERT_TRUE(player.folded());
}

TEST(PlayerTest, SetAllIn) {
    Player player("Player", 1000, 0);
    player.set_all_in(true);
    ASSERT_TRUE(player.all_in());
}

TEST(PlayerTest, SetBigBlind) {
    Player player("Player", 1000, 0);
    player.set_big_blind(true);
    ASSERT_TRUE(player.big_blind());
}

TEST(PlayerTest, SetSmallBlind) {
    Player player("Player", 1000, 0);
    player.set_small_blind(true);
    ASSERT_TRUE(player.small_blind());
}

TEST(PlayerTest, SetDealer) {
    Player player("Player", 1000, 0);
    player.set_dealer(true);
    ASSERT_TRUE(player.dealer());
}

TEST(PlayerTest, SetCanCheck) {
    Player player("Player", 1000, 0);
    player.set_can_check(false);
    ASSERT_FALSE(player.can_check());
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

TEST(PlayerTest, MakeBet) {
    Player player("Player", 1000, 0);
    player.make_bet(100);
    EXPECT_EQ(player.bet(), 100);
    EXPECT_EQ(player.money(), 900);
}

TEST(PlayerTest, MakeRaise) {
    Player player("Player", 1000, 0);
    player.make_raise(100);
    EXPECT_EQ(player.bet(), 100);
    EXPECT_EQ(player.money(), 900);
}

TEST(PlayerTest, MakeCall) {
    Player player("Player", 1000, 0);
    player.make_call(100);
    EXPECT_EQ(player.bet(), 100);
    EXPECT_EQ(player.money(), 900);
}

TEST(PlayerTest, MakeFold) {
    Player player("Player", 1000, 0);
    player.make_fold();
    EXPECT_EQ(player.folded(), true);
}

TEST(PlayerTest, MakeAllIn) {
    Player player("Player", 1000, 0);
    player.make_all_in();
    EXPECT_EQ(player.all_in(), true);
    EXPECT_EQ(player.money(), 0);
    EXPECT_EQ(player.bet(), 1000);
}

TEST(PlayerTest, MakeCheck) {
    Player player("Player", 1000, 0);
    player.make_check();
    EXPECT_EQ(player.bet(), 0);
}

typedef std::unique_ptr<Player> PlayerPtr;

TEST(PlayerTest, EvaluateRoyalStraight) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);
    for (int i = 8; i < 13; i++) {
        player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, static_cast<Value>(i))));
    }
    for (int i = 5; i < 10; i++) {
        player2->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, static_cast<Value>(i))));
    }
    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 9);
    ASSERT_EQ(p2 / 4096, 9);
}

TEST(PlayerTest, EvaluateDifferentStraightFlushes) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);
    for (int i = 8; i < 13; i++) {
        player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, static_cast<Value>(i))));
    }
    for (int i = 0; i < 5; i++) {
        player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, static_cast<Value>(i))));
    }
    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 9);
}

TEST(PlayerTest, EvaluateDifferentQuads) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    for (int i = 0; i < 4; i++) {
        player1->add_card(std::move(std::make_unique<Card>(static_cast<Suit>(i), Value::Ace)));
    }
    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Three)));

    for (int i = 0; i < 4; i++) {
        player2->add_card(std::move(std::make_unique<Card>(static_cast<Suit>(i), Value::King)));
    }
    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Four)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 8);
}

TEST(PlayerTest, EvaluateSameQuadsDifferentKicker) {
    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Nine).card_index();
    board[1] = Card(Suit::Spades, Value::Nine).card_index();
    board[2] = Card(Suit::Diamonds, Value::Nine).card_index();

    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Nine)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Ten)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Nine)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Eight)));

    ASSERT_TRUE(player1->evaluate() > player2->evaluate());
}

TEST(PlayerTest, EvaluateWeakerFullOnBoard) {
    unsigned board[5];
    board[0] = Card(Suit::Hearts, Value::Nine).card_index();
    board[1] = Card(Suit::Spades, Value::Nine).card_index();
    board[2] = Card(Suit::Diamonds, Value::Nine).card_index();
    board[3] = Card(Suit::Hearts, Value::Two).card_index();
    board[4] = Card(Suit::Diamonds, Value::Two).card_index();

    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Ten)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ten)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Eight)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Eight)));

    ASSERT_TRUE(player1->evaluate() > player2->evaluate());
}

TEST(PlayerTest, EvaluateStrongerFullOnBoard) {
    unsigned board[5];
    board[0] = Card(Suit::Hearts, Value::Nine).card_index();
    board[1] = Card(Suit::Spades, Value::Nine).card_index();
    board[2] = Card(Suit::Diamonds, Value::Nine).card_index();
    board[3] = Card(Suit::Hearts, Value::Seven).card_index();
    board[4] = Card(Suit::Diamonds, Value::Seven).card_index();

    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Six)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Five)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Five)));

    ASSERT_TRUE(player1->evaluate() == player2->evaluate());
}

TEST(PlayerTest, EvaluateDifferentFlushes) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::King)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Eight)));


    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 6);
}

TEST(PlayerTest, EvaluateFlushStraight) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Ace)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Hearts, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Four)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Six)));


    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 6);
    ASSERT_EQ(p2 / 4096, 5);
}

TEST(PlayerTest, EvaluateDifferentStraights) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[5];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();
    board[3] = Card(Suit::Spades, Value::Nine).card_index();
    board[4] = Card(Suit::Hearts, Value::Jack).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Eight)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Ten)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Four)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Six)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 5);
    ASSERT_EQ(p2 / 4096, 5);
}

TEST(PlayerTest, EvaluateDifferentThreeOfAKind) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Four).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Four)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Four)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 4);
    ASSERT_EQ(p2 / 4096, 4);
}

TEST(PlayerTest, EvaluateEqualThreeOfAKindDifferentKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Three).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Ten)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Nine)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 4);
    ASSERT_EQ(p2 / 4096, 4);
}

TEST(PlayerTest, EvaluateEqualThreeOfAKindEqualKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Three).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Ten)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Ten)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 == p2);
    ASSERT_EQ(p1 / 4096, 4);
    ASSERT_EQ(p2 / 4096, 4);
}

TEST(PlayerTest, EvaluateDifferentTwoPair) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[4];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Four).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();
    board[3] = Card(Suit::Hearts, Value::Eight).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Four)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Seven)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Eight)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 3);
    ASSERT_EQ(p2 / 4096, 3);
}

TEST(PlayerTest, EvaluateTwoPairEqualHigherRankPair) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Four).card_index();
    board[2] = Card(Suit::Hearts, Value::Eight).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Four)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Eight)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 3);
    ASSERT_EQ(p2 / 4096, 3);
}

TEST(PlayerTest, EvaluateTwoPairEqualLowerRankPair) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Spades, Value::Eight).card_index();
    board[2] = Card(Suit::Hearts, Value::Eight).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Four)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Nine)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 3);
    ASSERT_EQ(p2 / 4096, 3);
}

TEST(PlayerTest, EvaluateTwoPairEqualKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Spades, Value::Eight).card_index();
    board[2] = Card(Suit::Hearts, Value::Eight).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Nine)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Nine)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 == p2);
    ASSERT_EQ(p1 / 4096, 3);
    ASSERT_EQ(p2 / 4096, 3);
}

TEST(PlayerTest, EvaluateDifferentPair) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Eight).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Five)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Seven)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Six)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 2);
    ASSERT_EQ(p2 / 4096, 2);
}

TEST(PlayerTest, EvaluateEqualPairDifferentKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Eight).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Five)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Six)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 < p2);
    ASSERT_EQ(p1 / 4096, 2);
    ASSERT_EQ(p2 / 4096, 2);
}

TEST(PlayerTest, EvaluateEqualPairEqualKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Hearts, Value::Three).card_index();
    board[1] = Card(Suit::Diamonds, Value::Eight).card_index();
    board[2] = Card(Suit::Hearts, Value::Seven).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Three)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Five)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Three)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Five)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 == p2);
    ASSERT_EQ(p1 / 4096, 2);
    ASSERT_EQ(p2 / 4096, 2);
}

TEST(PlayerTest, EvaluateDifferentHighCard) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Clubs, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Spades, Value::Ten).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Queen)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Jack)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Two)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 1);
    ASSERT_EQ(p2 / 4096, 1);
}

TEST(PlayerTest, EvaluateDifferentHighCardEqualFirstKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Clubs, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Spades, Value::Ten).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Queen)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Queen)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Two)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 > p2);
    ASSERT_EQ(p1 / 4096, 1);
    ASSERT_EQ(p2 / 4096, 1);
}

TEST(PlayerTest, EvaluateDifferentHighCardEqualSecondKicker) {
    PlayerPtr player1 = std::make_unique<Player>("Player", 1000, 0);
    PlayerPtr player2 = std::make_unique<Player>("Player", 1000, 0);

    unsigned board[3];
    board[0] = Card(Suit::Clubs, Value::Three).card_index();
    board[1] = Card(Suit::Hearts, Value::Five).card_index();
    board[2] = Card(Suit::Spades, Value::Ten).card_index();

    for (auto card : board) {
        player1->add_table_card(card);
        player2->add_table_card(card);
    }

    player1->add_card(std::move(std::make_unique<Card>(Suit::Diamonds, Value::Queen)));
    player1->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Six)));

    player2->add_card(std::move(std::make_unique<Card>(Suit::Clubs, Value::Queen)));
    player2->add_card(std::move(std::make_unique<Card>(Suit::Spades, Value::Six)));

    auto p1 = player1->evaluate();
    auto p2 = player2->evaluate();
    ASSERT_TRUE(p1 == p2);
    ASSERT_EQ(p1 / 4096, 1);
    ASSERT_EQ(p2 / 4096, 1);
}