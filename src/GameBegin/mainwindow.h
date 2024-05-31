#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "GameInfo.h"
#include "Game.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::shared_ptr<Game> game;

public:
    MainWindow(QWidget *parent = nullptr, std::shared_ptr<Game> Igame);
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
