#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "GameInfo.h"
#include "GameHandler.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::shared_ptr<GameHandler> game_handler;

public:
    MainWindow(std::shared_ptr<GameHandler> Igame, QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void gameInfoReady(GameInfo gameInfo);

private slots:
    void startGame();
    void updatePlayerCount(int count);
    void updateStartMoney(int count);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
