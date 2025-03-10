#include "BotPlayer.h"
#include "gtest/gtest.h"

TEST(BotPlayerTest, BotPlayerCreate) {
    BotPlayer bot("Bot", 1000, 0);
    EXPECT_EQ(bot.name(), "Bot");
    EXPECT_EQ(bot.money(), 1000);
    EXPECT_EQ(bot.bet(), 0);
    EXPECT_EQ(bot.equity(), 0);
}

TEST(BotPlayerTest, BotPlayerSetters) {
    BotPlayer bot("Bot", 1000, 0);
    bot.set_name("Bot2");
    bot.set_money(2000);
    bot.set_bet(100);
    bot.set_equity(0.5);
    EXPECT_EQ(bot.name(), "Bot2");
    EXPECT_EQ(bot.money(), 2000);
    EXPECT_EQ(bot.bet(), 100);
    EXPECT_EQ(bot.equity(), 0.5);
}

TEST(BotPlayerTest, BotPlayerGetBotHand) {
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    std::vector<omp::CardRange> hand = bot.get_bot_hand(2);
    EXPECT_EQ(hand.size(), 2);
    std::string temp1 = "AsKs";
    EXPECT_EQ(hand[0], omp::CardRange(temp1));
}

TEST(BotPlayerTest, BotPlayerCalcEquityBasic) {
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s5s6s", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityOnePlayer){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s5s6s", 1);
    EXPECT_DOUBLE_EQ(bot.equity(), 1.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityRoyalFlush){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("TsJsQsKhAh", 2);
    EXPECT_NEAR(bot.equity(), 1.0, 0.01);
}

TEST(BotPlayerTest, BotPlayerCalcEquityFlush){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s5s6s", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityPreFlop){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("0", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityFlop){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityTurn){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s5s", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerCalcEquityRiver){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    bot.calc_equity("2s3s4s5s6s", 2);
    EXPECT_GT(bot.equity(), 0.0);
}

TEST(BotPlayerTest, BotPlayerMakeDecisionRaise){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Ace);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::King);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    auto res = bot.make_decision(100, 2, "JsTs9s", false, false);
    EXPECT_GE(res, 100);
}

TEST(BotPlayerTest, BotPlayerMakeDecisionFold){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Two);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::Three);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    auto res = bot.make_decision(100, 2, "7h8h9h", false, false);
    EXPECT_EQ(res, -1);
}

TEST(BotPlayerTest, BotPlayerMakeDecisionCheck){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Spades, Value::Two);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::Three);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    auto res = bot.make_decision(0, 2, "7h8h9h", true, false);
    EXPECT_GE(res, 0);
}

TEST(BotPlayerTest, BotPlayerMakeDecisionCall){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Hearts, Value::Two);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::Three);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    auto res = bot.make_decision(100, 2, "7h8h9h", false, false);
    EXPECT_EQ(res, 100);
}

TEST(BotPlayerTest, BotPlayerMakeBluff){
    BotPlayer bot("Bot", 1000, 0);
    std::unique_ptr<Card> card1 = std::make_unique<Card>(Suit::Hearts, Value::Two);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(Suit::Spades, Value::Three);
    bot.add_card(std::move(card1));
    bot.add_card(std::move(card2));
    auto res = bot.make_bluff(100, 2, "7h8h9h");
    EXPECT_GT(res, 100);
}