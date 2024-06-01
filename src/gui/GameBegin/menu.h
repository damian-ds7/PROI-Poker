#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "GameInfo.h"
#include "GameHandler.h"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT
    std::shared_ptr<GameHandler> game_handler;

public:
    MenuWindow(std::shared_ptr<GameHandler> Igame, QWidget *parent = nullptr);
    ~MenuWindow();

signals:
    void gameInfoReady(GameInfo gameInfo, std::shared_ptr<GameHandler> game_handler);

private slots:
    void startGame();
    void updatePlayerCount(int count);
    void updateStartMoney(int count);

private:
    Ui::MenuWindow *ui;
};

#endif // MAINWINDOW_H
