#include <QApplication>
#include <QObject>
#include <memory>
#include "menu.h"
#include "MainWindow.h"
#include "GameHandler.h"
#include "GameInfo.h"
#include <iostream>

void handleGameInfo(const GameInfo& gameInfo, std::shared_ptr<GameHandler> game_handler) {
    qDebug() << "Player Name:" << QString::fromStdString(gameInfo.player_name);
    qDebug() << "Number of Players:" << gameInfo.player_count;
    qDebug() << "Initial Money:" << gameInfo.initial_money;


    MainWindow Main_Window(game_handler);
    MainWindow* ptr = &Main_Window;
    Main_Window.createWidgets(ptr);

    qDebug() << "Main Window Created";


    Main_Window.show();
}

int main(int argc, char* argv[])
{
    QCoreApplication::addLibraryPath(R"(C:\Qt\6.7.1\mingw_64\plugins)");
    QApplication a(argc, argv);
    std::shared_ptr<GameHandler> game_handler = std::make_shared<GameHandler>();
    MenuWindow w(game_handler);

    // Connect the signal emitted when the game info is ready to a lambda function
    QObject::connect(&w, &MenuWindow::gameInfoReady, [&game_handler](const GameInfo& gameInfo) {
        handleGameInfo(gameInfo, game_handler);
        });

    w.show();

    // Start the Qt event loop
    return a.exec();
}
