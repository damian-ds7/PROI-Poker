#include "BotPlayer.h"
#include "gtest/gtest.h"

TEST(BotPlayerTest, BotPlayerCreate) {
    BotPlayer bot("Bot", 1000, 0);
    EXPECT_EQ(bot.name(), "Bot");
    EXPECT_EQ(bot.money(), 1000);
    EXPECT_EQ(bot.bet(), 0);
}
