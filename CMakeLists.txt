cmake_minimum_required(VERSION 3.28)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/Card src/CardCollection src/Deck src/Hand src/Player utils)
set(SOURCE_FILES src/Card/Card.cpp src/Card/Card.h src/CardCollection/CardCollection.h src/Deck/Deck.h src/Hand/Hand.h
        src/Player/Player.h src/Player/Player.cpp utils/CardsTypedef.h
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