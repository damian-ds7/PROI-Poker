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
