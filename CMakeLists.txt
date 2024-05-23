cmake_minimum_required(VERSION 3.28)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

include_directories(PokerLib)
set(SOURCE_FILES src/Card/src/Card.cpp src/Card/src/Card.h src/CardCollection/src/CardCollection.h src/Deck/src/Deck.h src/Hand/src/Hand.h
        src/Player/src/Player.h src/Player/src/Player.cpp utils/CardsTypedef.h
        utils/Suit.h utils/Value.h)
set(TEST_FILES test/CardTest.cpp test/DeckTest.cpp test/PlayerTest.cpp)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)
add_executable(PokerTest ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(PokerTest PUBLIC gtest_main)