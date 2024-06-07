#include "gtest/gtest.h"
#include "GameHandler.h"
#include "GameInfo.h"

TEST(GameHandlerTest, GameHandlerCreate){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    EXPECT_EQ(game_handler.player_count(), 6);
    EXPECT_EQ(game_handler.currently_playing(), 6);
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 1);
}

TEST(GameHandlerTest, GameHandlerPlayTurn){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    auto idx = (game_handler.dealer() + 2) % game_info.player_count;
    auto prev_idx = (idx == 0) ? game_info.player_count - 1 : idx - 1;
    EXPECT_EQ(game_handler.current_player(), idx);
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnTwoPlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    auto idx = (game_handler.dealer() + 3) % game_info.player_count;
    auto prev_idx = (idx == 0) ? game_info.player_count - 1 : idx - 1;
    EXPECT_EQ(game_handler.current_player(), idx);
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnThreePlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    auto idx = (game_handler.dealer() + 4) % game_info.player_count;
    EXPECT_EQ(game_handler.current_player(), idx);
    auto prev_idx = (idx == 0) ? game_info.player_count - 1 : idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
}

TEST(GameHandlerTest, GameHandlerPlayTurnFourPlayers){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    game_handler.play_turn(Decision::AllIn, 1000);
    auto idx = (game_handler.dealer() + 5) % game_info.player_count;
    EXPECT_EQ(game_handler.current_player(), idx);
    auto prev_idx = (idx == 0) ? game_info.player_count - 1 : idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
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
    auto idx = (game_handler.dealer() + 6) % game_info.player_count;
    EXPECT_EQ(game_handler.current_player(), idx);
    auto prev_idx = (idx == 0) ? game_info.player_count - 1 : idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
    prev_idx = (prev_idx == 0) ? game_info.player_count - 1 : prev_idx - 1;
    EXPECT_EQ(game_handler.player(prev_idx)->money(), 0);
    EXPECT_EQ(game_handler.player(prev_idx)->bet(), 1000);
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
    auto idx = (game_handler.dealer() + 7) % game_info.player_count;
    EXPECT_EQ(game_handler.current_player(), idx);
    EXPECT_EQ(game_handler.player(0)->money(), 0);
    EXPECT_EQ(game_handler.player(0)->bet(), 1000);
    EXPECT_EQ(game_handler.player(1)->money(), 0);
    EXPECT_EQ(game_handler.player(1)->bet(), 1000);
    EXPECT_EQ(game_handler.player(2)->money(), 0);
    EXPECT_EQ(game_handler.player(2)->bet(), 1000);
    EXPECT_EQ(game_handler.player(3)->money(), 0);
    EXPECT_EQ(game_handler.player(3)->bet(), 1000);
    EXPECT_EQ(game_handler.player(4)->money(), 0);
    EXPECT_EQ(game_handler.player(4)->bet(), 1000);
    EXPECT_EQ(game_handler.player(5)->money(), 0);
    EXPECT_EQ(game_handler.player(5)->bet(), 1000);
}

TEST(GameHandlerTest, GameHandlerStartGame){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 6, 1000);
    game_handler.initialize_game(game_info);
    game_handler.start_game();
    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 1);
    EXPECT_EQ(game_handler.player(0)->money(), 1000);
    EXPECT_EQ(game_handler.player(1)->money(), 1000);
    EXPECT_EQ(game_handler.player(2)->money(), 1000);
    EXPECT_EQ(game_handler.player(3)->money(), 1000);
    EXPECT_EQ(game_handler.player(4)->money(), 1000);
    EXPECT_EQ(game_handler.player(5)->money(), 1000);
    EXPECT_EQ(game_handler.pot(), 0);
    EXPECT_EQ(game_handler.player(0)->clear_hand().size(), 2);
    EXPECT_EQ(game_handler.player(1)->clear_hand().size(), 2);
    EXPECT_EQ(game_handler.player(2)->clear_hand().size(), 2);
    EXPECT_EQ(game_handler.player(3)->clear_hand().size(), 2);
    EXPECT_EQ(game_handler.player(4)->clear_hand().size(), 2);
    EXPECT_EQ(game_handler.player(5)->clear_hand().size(), 2);
}

//TEST(GameHandlerTest, GameHandlerMakeBigBlind){
//    GameHandler game_handler;
//    GameInfo game_info("Herkules", 6, 1000);
//    game_handler.initialize_game(game_info);
//    game_handler.start_game();
//    game_handler.make_big_blind();
//    EXPECT_EQ(game_handler.current_player(), game_handler.dealer() + 1);
//    EXPECT_EQ(game_handler.player(0)->money(), 998);
//    EXPECT_EQ(game_handler.player(1)->money(), 1000);
//    EXPECT_EQ(game_handler.pot(), 2);
//}

TEST(GameHandlerTest, GameHandlerPhaseToInt){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 2, 1000);
    game_handler.initialize_game(game_info);
    EXPECT_EQ(game_handler.phase_to_int(), 0);
    game_handler.start_game();
    game_handler.play_turn(Decision::Raise, 10);
    game_handler.play_turn(Decision::Call, 10);
    game_handler.play_turn(Decision::Call, 0);
    EXPECT_EQ(game_handler.phase_to_int(), 1);
    game_handler.play_turn(Decision::Raise, 10);
    game_handler.play_turn(Decision::Call, 10);
    game_handler.play_turn(Decision::Call, 0);
    EXPECT_EQ(game_handler.phase_to_int(), 2);
    game_handler.play_turn(Decision::Raise, 10);
    game_handler.play_turn(Decision::Call, 10);
    game_handler.play_turn(Decision::Call, 0);
    EXPECT_EQ(game_handler.phase_to_int(), 3);
    game_handler.play_turn(Decision::Raise, 10);
    game_handler.play_turn(Decision::Call, 10);
    game_handler.play_turn(Decision::Call, 0);
    EXPECT_EQ(game_handler.phase_to_int(), 4);
}

TEST(GameHandlerTest, GameHandlerCurrentPlayerToString){
    GameHandler game_handler;
    GameInfo game_info("Herkules", 2, 1000);
    game_handler.initialize_game(game_info);
    EXPECT_EQ(game_handler.current_player_to_string(), game_handler.name_to_string(game_handler.dealer()+1));
}