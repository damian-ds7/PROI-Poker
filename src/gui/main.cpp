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
    ptr->show();
    ptr->StartGame();
}

void handleDecisionMade(Decision decision, int bet, MainWindow* ptr) {
	qDebug() << "Decision made: " << int(decision) << " with bet: " << bet;
    ptr->playerMakeDecision(decision, bet);
}

void handleSmallBlind(int bet, MainWindow* ptr) {
	qDebug() << "Small blind made: " << bet;
    ptr->playerMakeSmallBlind(bet);
}

void handleBotMove(MainWindow* ptr) {
    ptr->botMakeMove();
}

int main(int argc, char *argv[])
{
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
    QObject::connect(ptr, &MainWindow::botMove, [ptr]() {
        handleBotMove(ptr);
        });


    w.show();
    return a.exec();
}
