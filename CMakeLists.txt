cmake_minimum_required(VERSION 3.28)
project(Poker)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/Card src/CardCollection src/Deck src/Hand src/Player utils/omp utils)
set(SOURCE_FILES src/Card/Card.cpp src/Card/Card.h src/CardCollection/CardCollection.h src/Deck/Deck.h src/Hand/Hand.h
        src/Player/Player.h src/Player/Player.cpp utils/CardsTypedef.h
        utils/Suit.h utils/Value.h)

file(GLOB CARD_FILES src/Card/*.cpp src/Card/*.h)
file(GLOB COLLECTION_FILES src/CardCollection/*.h src/CardCollection/*.cpp
        src/Deck/*.h src/Deck/*.cpp src/Hand/*.h src/Hand/*.cpp)
file(GLOB PLAYER_FILES src/Player/*.h src/Player/*.cpp)
file(GLOB UTILS_FILES utils/*.h utils/*.cpp)
file(GLOB EVALUATOR_FILES utils/omp/*.h utils/omp/*.cpp utils/omp/*.hxx)
file(GLOB TEST_FILES test/*.cpp)

set(SOURCE_FILES ${CARD_FILES} ${COLLECTION_FILES} ${PLAYER_FILES} ${UTILS_FILES} ${EVALUATOR_FILES})

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

add_executable(PlayerTest ${SOURCE_FILES} test/PlayerTest.cpp)
target_link_libraries(PlayerTest PUBLIC gtest_main)