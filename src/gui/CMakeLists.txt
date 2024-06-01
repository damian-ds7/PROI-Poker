set(CMAKE_AUTORCC ON)

include_directories(../utils GameHandler GameBegin)

set(MENU_SOURCES
        main.cpp
        GameBegin/mainwindow.cpp
        GameBegin/mainwindow.h
        GameBegin/mainwindow.ui
        GameBegin/resources.qrc
)

set(UI_SOURCES)


set(GAME_HANDLER GameHandler/GameHandler.h GameHandler/GameHandler.cpp)

add_executable(Poker ${MENU_SOURCES} ${GAME_HANDLER})
#target_include_directories(Poker INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/utils ${CMAKE_CURRENT_SOURCE_DIR}/src/gui/GameHandler)
target_link_libraries(Poker PRIVATE poker_lib Qt::Widgets Qt::Core Qt::Gui)
