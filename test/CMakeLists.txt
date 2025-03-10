file(GLOB TEST_FILES *.cpp)

add_executable(PokerTest ${SOURCE_FILES} ${TEST_FILES} ../src/gui/GameHandler/GameHandler.cpp ../src/gui/GameHandler/GameHandler.h)
target_link_libraries(PokerTest PUBLIC gtest_main)
target_link_libraries(PokerTest PRIVATE poker_lib Qt::Core)

add_executable(CardTest ${CARD_FILES} ${UTILS_FILES} CardTest.cpp)
target_link_libraries(CardTest PRIVATE poker_lib)
target_link_libraries(CardTest PUBLIC gtest_main)

add_executable(HandTest ${COLLECTION_FILES} ${CARD_FILES} ${UTILS_FILES} HandTest.cpp)
target_link_libraries(HandTest PRIVATE poker_lib)
target_link_libraries(HandTest PUBLIC gtest_main)

add_executable(CollectionTest ${COLLECTION_FILES} ${CARD_FILES} ${UTILS_FILES} CollectionTest.cpp)
target_link_libraries(CollectionTest PRIVATE poker_lib)
target_link_libraries(CollectionTest PUBLIC gtest_main)

add_executable(PlayerTest ${SOURCE_FILES} ${EVALUATOR_FILES} PlayerTest.cpp)
target_link_libraries(PlayerTest PRIVATE poker_lib)
target_link_libraries(PlayerTest PUBLIC gtest_main)

add_executable(BotPlayerTest ${SOURCE_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${OMP_FILES} BotPlayerTest.cpp)
target_link_libraries(BotPlayerTest PRIVATE poker_lib)
target_link_libraries(BotPlayerTest PUBLIC gtest_main)

add_executable(GameTest ${SOURCE_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${OMP_FILES} GameTest.cpp)
target_link_libraries(GameTest PRIVATE poker_lib)
target_link_libraries(GameTest PUBLIC gtest_main)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src/gui/GameHandler)

add_executable(GameHandlerTest ${SOURCE_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${OMP_FILES} GameHandlerTest.cpp ../src/gui/GameHandler/GameHandler.cpp ../src/gui/GameHandler/GameHandler.h)
target_link_libraries(GameHandlerTest PRIVATE poker_lib)
target_link_libraries(GameHandlerTest PUBLIC gtest_main)
target_link_libraries(GameHandlerTest PRIVATE poker_lib Qt::Core)