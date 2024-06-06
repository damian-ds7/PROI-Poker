#include "Game.h"
#include "gtest/gtest.h"

TEST(GameTest, GameDeleteBrokePlayers){
    Game game("Herkules", 6, 1000);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.make_move(Decision::AllIn);
    game.delete_broke_players();
}
