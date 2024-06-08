#include "Game.h"
#include "gtest/gtest.h"

TEST(GameTest, GameCreate){
    Game game("Herkules", 6, 1000);
}

TEST(GameTest, GameMakeMove){
    Game game("Herkules", 6, 1000);
    game.make_move(Decision::AllIn);
}

TEST(GameTest, GameDeleteBrokePlayers){
    Game game("Herkules", 6, 1000);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.delete_broke_players();
}

TEST(GameTest, GameFindWinner) {
    Game game("Herkules", 6, 1000);
    game.deal();
    game.next_phase();
    game.next_phase();
    game.next_phase();
    game.next_phase();
    game.find_winner();
}

TEST(GameTest, GameSharePot){
    Game game("Herkules", 6, 1000);
    game.deal();
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.next_phase();
    game.next_phase();
    game.next_phase();
    game.next_phase();
    game.find_winner();
    game.share_pot();
}

TEST(GameTest, GameConvertDecision) {
    Game game("Herkules", 6, 1000);
    ASSERT_EQ(game.convert_bot_decision(0), Decision::Check);
    game.make_move(Decision::Bet, 100);
    game.make_move(Decision::Bet, 200);
    ASSERT_EQ(game.convert_bot_decision(200), Decision::Call);
    ASSERT_EQ(game.convert_bot_decision(400), Decision::Raise);
    ASSERT_EQ(game.convert_bot_decision(-1), Decision::Fold);
    ASSERT_EQ(game.convert_bot_decision(1000), Decision::AllIn);
}




