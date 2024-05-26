#include "BotPlayer.h"
#include "gtest/gtest.h"

TEST(BotPlayerTest, BotPlayerCreate) {
    BotPlayer bot("Bot", 1000, 0);
    EXPECT_EQ(bot.name(), "Bot");
    EXPECT_EQ(bot.money(), 1000);
    EXPECT_EQ(bot.bet(), 0);
    bot.add_card(std::make_unique<Card>(Suit::Hearts, Value::Ace));
    bot.add_card(std::make_unique<Card>(Suit::Spades, Value::Queen));
    auto hand = bot.get_bot_hand(4);
    bot.calc_equity("AsKsQhJhTh", 4);
}
