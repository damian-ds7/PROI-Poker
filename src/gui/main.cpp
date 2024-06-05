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
//    QCoreApplication::addLibraryPath(R"(C:\Qt\6.7.1\mingw_64\plugins)");
    QApplication a(argc, argv);
    std::unique_ptr<GameHandler> game_handler = std::make_unique<GameHandler>();
    MainWindow Main_Window;
    MainWindow* ptr = &Main_Window;
    MenuWindow w(std::move(game_handler), ptr);

    QObject::connect(&w, &MenuWindow::gameInfoReady, [ptr](const GameInfo& gameInfo) {
        handleGameInfo(gameInfo, ptr);
    });

    w.show();


    w.show();
    return a.exec();
//    QApplication a(argc, argv);
//    MainWindow Main_Window(nullptr, 5);
//    MainWindow* ptr = &Main_Window;
//    //Main_Window.createWidgets(ptr, 1);
//    //Main_Window.createWidgets(ptr, 2);
//    //Main_Window.createWidgets(ptr, 3);
//    //Main_Window.createWidgets(ptr, 4);
//    Main_Window.createWidgets(ptr);
//
//    Main_Window.show();

//    return a.exec();
}
