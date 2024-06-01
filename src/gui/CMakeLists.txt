set(CMAKE_AUTORCC ON)

include_directories(../utils GameHandler GameBegin PokerUI)

set(MENU_SOURCES
        GameBegin/menu.cpp
        GameBegin/menu.h
        GameBegin/menu.ui
        GameBegin/resources.qrc
)

set(MAIN_WINDOW_SOURCES
        PokerUI/MainWindow.cpp
        PokerUI/MainWindow.h
        PokerUI/mainwindow.ui
        PokerUI/background.qrc
        PokerUI/cards.qrc
)

set(GAME_HANDLER GameHandler/GameHandler.h GameHandler/GameHandler.cpp)

add_executable(Poker main.cpp ${MAIN_WINDOW_SOURCES} ${MENU_SOURCES} ${GAME_HANDLER})
target_link_libraries(Poker PRIVATE poker_lib Qt::Widgets Qt::Core Qt::Gui)
