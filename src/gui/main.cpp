#include <QApplication>
#include <QObject>
#include <memory>
#include "menu.h"
#include "MainWindow.h"
#include "GameHandler.h"
#include "GameInfo.h"
#include <iostream>

void handleGameInfo(const GameInfo& gameInfo) {
    qDebug() << "Player Name:" << QString::fromStdString(gameInfo.player_name);
    qDebug() << "Number of Players:" << gameInfo.player_count;
    qDebug() << "Initial Money:" << gameInfo.initial_money;
}

int main(int argc, char *argv[])
{
    QCoreApplication::addLibraryPath(R"(C:\Qt\6.7.1\mingw_64\plugins)");
//    QApplication a(argc, argv);
//    std::shared_ptr<GameHandler> game_handler = std::make_shared<GameHandler>();
//    MenuWindow w(game_handler);
//
//    QObject::connect(&w, &MenuWindow::gameInfoReady, &handleGameInfo);
//
//    w.show();
//    return a.exec();
    QApplication a(argc, argv);
    MainWindow Main_Window(nullptr, 5);
    MainWindow* ptr = &Main_Window;
    //Main_Window.createWidgets(ptr, 1);
    //Main_Window.createWidgets(ptr, 2);
    //Main_Window.createWidgets(ptr, 3);
    //Main_Window.createWidgets(ptr, 4);
    Main_Window.createWidgets(ptr);

    Main_Window.show();

    return a.exec();
}
