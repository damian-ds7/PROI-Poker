cmake_minimum_required(VERSION 3.28)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

include_directories(PokerLib)
set(SOURCE_FILES PokerLib/Card.cpp PokerLib/Card.h PokerLib/CardCollection.h PokerLib/Deck.h PokerLib/Hand.h
PokerLib/Player.h PokerLib/Player.cpp PokerLib/constants.h)
set(TEST_FILES PokerTest/CardTest.cpp PokerTest/DeckTest.cpp PokerTest/PlayerTest.cpp)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)
add_executable(PokerTest ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(PokerTest PUBLIC gtest_main)