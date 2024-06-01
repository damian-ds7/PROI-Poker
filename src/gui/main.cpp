#include <QApplication>
#include <QObject>
#include <memory>
#include "mainwindow.h"
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
    QApplication a(argc, argv);
    std::shared_ptr<GameHandler> game_handler = std::make_shared<GameHandler>();
    MainWindow w(game_handler);

    QObject::connect(&w, &MainWindow::gameInfoReady, &handleGameInfo);

    w.show();
    return a.exec();
}
