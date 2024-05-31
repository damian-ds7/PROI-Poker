cmake_minimum_required(VERSION 3.28)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/Card src/CardCollection src/Deck src/Hand src/Table src/Player src/BotPlayer
        src/HumanPlayer src/Game utils utils/libdivide utils/omp utils/MonteCarloPoker)


file(GLOB GAME_FILES src/GameHandler/*.h src/GameHandler/*.cpp src/Game/*.h src/Game/*.cpp)
file(GLOB CARD_FILES src/Card/*.cpp src/Card/*.h)
file(GLOB COLLECTION_FILES src/CardCollection/*.h src/CardCollection/*.cpp
        src/Deck/*.h src/Deck/*.cpp src/Hand/*.h src/Hand/*.cpp src/Table/*.h)
file(GLOB PLAYERS_FILES src/Player/*.h src/Player/*.cpp src/HumanPlayer/*.h src/HumanPlayer/*.cpp src/BotPlayer/*.h src/BotPlayer/*.cpp)
file(GLOB UTILS_FILES utils/*.h utils/*.cpp)
file(GLOB EVALUATOR_FILES utils/omp/*.h utils/omp/*.cpp utils/omp/*.hxx)
file(GLOB EQUITY_CALC_FILES utils/libdivide/*.h)
file(GLOB TEST_FILES test/*.cpp)

set(OMP_FILES ${EQUITY_CALC_FILES} ${EVALUATOR_FILES})
set(SOURCE_FILES ${GAME_FILES} ${CARD_FILES} ${COLLECTION_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${OMP_FILES})

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

add_executable(PokerTest ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(PokerTest PUBLIC gtest_main)

add_executable(CardTest ${CARD_FILES} ${UTILS_FILES} test/CardTest.cpp)
target_link_libraries(CardTest PUBLIC gtest_main)

add_executable(HandTest ${COLLECTION_FILES} ${CARD_FILES} ${UTILS_FILES} test/HandTest.cpp)
target_link_libraries(HandTest PUBLIC gtest_main)

add_executable(DeckTest ${COLLECTION_FILES} ${CARD_FILES} ${UTILS_FILES} test/DeckTest.cpp)
target_link_libraries(DeckTest PUBLIC gtest_main)

add_executable(PlayerTest ${SOURCE_FILES} ${EVALUATOR_FILES} test/PlayerTest.cpp)
target_link_libraries(PlayerTest PUBLIC gtest_main)

add_executable(BotPlayerTest ${SOURCE_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${OMP_FILES} test/BotPlayerTest.cpp)
target_link_libraries(BotPlayerTest PUBLIC gtest_main)