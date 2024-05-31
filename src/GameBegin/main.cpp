#include "mainwindow.h"
#include <QApplication>
#include <QObject>

void handleGameInfo(GameInfo gameInfo) {
    qDebug() << "Player Name:" << QString::fromStdString(gameInfo.player_name);
    qDebug() << "Number of Players:" << gameInfo.player_count;
    qDebug() << "Initial Money:" << gameInfo.initial_money;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject::connect(&w, &MainWindow::gameInfoReady, &handleGameInfo);

    w.show();
    return a.exec();
}
