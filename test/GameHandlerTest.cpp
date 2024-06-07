#include "gtest/gtest.h"
#include "GameHandler.h"
#include "GameInfo.h"

TEST(GameHandlerTest, GameHandlerCreate){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    EXPECT_EQ(game_handler.player_count(), 6);
    EXPECT_EQ(game_handler.currently_playing(), 6);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer());
}

TEST(GameHandlerTest, GameHandlerPlayTurn){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 1);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 1000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnTwoPlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 2);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 2000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnThreePlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 3);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.player(2)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 3000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnFourPlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 4);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.player(2)->money(), 0);
    EXPECT_EQ(game_handler.player(3)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 4000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnFivePlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 5);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.player(2)->money(), 0);
    EXPECT_EQ(game_handler.player(3)->money(), 0);
    EXPECT_EQ(game_handler.player(4)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 5000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnSixPlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer());
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.player(2)->money(), 0);
    EXPECT_EQ(game_handler.player(3)->money(), 0);
    EXPECT_EQ(game_handler.player(4)->money(), 0);
    EXPECT_EQ(game_handler.player(5)->money(), 0);
    EXPECT_EQ(game_handler.pot(), 6000);
}

TEST(GameHandlerTest, GameHandlerStartGame){

}