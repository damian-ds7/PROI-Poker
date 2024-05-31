#include "beginmainwindow.h"
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
    BeginMainWindow w;

    QObject::connect(&w, &BeginMainWindow::gameInfoReady, &handleGameInfo);

    w.show();
    return a.exec();
}
