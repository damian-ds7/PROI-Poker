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
    ptr->StartGame();
    ptr->show();
}

void handleDecisionMade(Decision decision, int bet, MainWindow* ptr) {
	qDebug() << "Decision made: " << " with bet: " << bet;
    ptr->playerMakeDecision(decision, bet);
}

void handleSmallBlind(int bet, MainWindow* ptr) {
	qDebug() << "Small blind made: " << bet;
    ptr->playerMakeSmallBlind(bet);
}

int main(int argc, char *argv[])
{
//    QCoreApplication::addLibraryPath(R"(C:\Qt\6.7.1\mingw_64\plugins)");
    QApplication a(argc, argv);
    MainWindow Main_Window;
    MainWindow* ptr = &Main_Window;
    MenuWindow w(ptr);

    QObject::connect(&w, &MenuWindow::gameInfoReady, [ptr](const GameInfo& gameInfo) {
        handleGameInfo(gameInfo, ptr);
    });

    QObject::connect(ptr, &MainWindow::decisionMade, [ptr](Decision decision, int bet) {
        handleDecisionMade(decision, bet, ptr);
        });
    QObject::connect(ptr, &MainWindow::smallBlindMade, [ptr](int bet) {
        handleSmallBlind(bet, ptr);
        });


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
