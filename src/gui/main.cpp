#include <QApplication>
#include <QObject>
#include <memory>
#include "menu.h"
#include "MainWindow.h"
#include "GameHandler.h"
#include "GameInfo.h"
#include <iostream>

void handleGameInfo(const GameInfo& gameInfo, MainWindow* ptr) {
    qDebug() << "Player Name:" << QString::fromStdString(gameInfo.player_name);
    qDebug() << "Number of Players:" << gameInfo.player_count;
    qDebug() << "Initial Money:" << gameInfo.initial_money;

    ptr->createWidgets(ptr);
    qDebug() << "Game started";
    ptr->PlayGame();
    ptr->show();
}

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath(R"(C:\Qt\6.7.1\mingw_64\plugins)");
    QApplication a(argc, argv);
    std::shared_ptr<GameHandler> game_handler = std::make_shared<GameHandler>();
    MenuWindow w(game_handler);
    MainWindow Main_Window(game_handler);
    MainWindow* ptr = &Main_Window;

    QObject::connect(&w, &MenuWindow::gameInfoReady, [ptr](const GameInfo& gameInfo) {
        handleGameInfo(gameInfo, ptr);
    });

    w.show();


    return a.exec();
}
