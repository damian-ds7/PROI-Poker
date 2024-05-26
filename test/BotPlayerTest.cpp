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

TEST(BotPlayerTest, BotPlayerMakeDecisionFold){
    BotPlayer bot("Bot", 1000, 0);
    bot.set_equity(0.2);
    bot.make_decision(100, 2);
    EXPECT_TRUE(bot.folded());
}

TEST(BotPlayerTest, BotPlayerMakeDecisionCall){
    BotPlayer bot("Bot", 1000, 0);
    bot.set_equity(0.4);
    bot.make_decision(100, 2);
    EXPECT_EQ(bot.bet(), 100);
}

TEST(BotPlayerTest, BotPlayerMakeDecisionRaise){
    BotPlayer bot("Bot", 1000, 0);
    bot.set_equity(0.6);
    bot.make_decision(100, 2);
    EXPECT_GT(bot.bet(), 100);
}