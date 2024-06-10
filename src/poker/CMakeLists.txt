set(UTILS_PATH ../utils)

set(INCLUDE_DIRS Card CardCollection Deck Hand Table Player BotPlayer
        HumanPlayer Game ${UTILS_PATH} ${UTILS_PATH}/libdivide ${UTILS_PATH}/omp)
include_directories(${INCLUDE_DIRS})

file(GLOB GAME_FILES Game/*.h Game/*.cpp)
file(GLOB CARD_FILES Card/*.cpp Card/*.h)
file(GLOB COLLECTION_FILES CardCollection/*.h CardCollection/*.cpp
        Deck/*.h Deck/*.cpp Hand/*.h Hand/*.cpp Table/*.h)
file(GLOB PLAYERS_FILES Player/*.h Player/*.cpp HumanPlayer/*.h HumanPlayer/*.cpp BotPlayer/*.h BotPlayer/*.cpp)
file(GLOB UTILS_FILES ${UTILS_PATH}/*.h ${UTILS_PATH}/*.cpp)
file(GLOB EVALUATOR_FILES ${UTILS_PATH}/omp/*.h ${UTILS_PATH}/omp/*.cpp ${UTILS_PATH}/omp/*.hxx)
file(GLOB EQUITY_CALC_FILES ${UTILS_PATH}/libdivide/*.h)


set(SOURCE_FILES ${GAME_FILES} ${CARD_FILES} ${COLLECTION_FILES} ${PLAYERS_FILES} ${UTILS_FILES} ${EVALUATOR_FILES} ${EQUITY_CALC_FILES})
add_library(poker_lib STATIC ${SOURCE_FILES})
target_include_directories(poker_lib INTERFACE
        ${INCLUDE_DIRS}
)