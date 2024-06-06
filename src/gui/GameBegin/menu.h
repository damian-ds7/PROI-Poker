#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "GameInfo.h"
#include "GameHandler.h"
#include "MainWindow.h"
#include <memory>

class GameHandler;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT
    std::unique_ptr<GameHandler> game_handler = std::make_unique<GameHandler>();
    MainWindow* main_window;

public:
    MenuWindow(MainWindow* main_window, QWidget *parent = nullptr);
    ~MenuWindow();

signals:
    void gameInfoReady(GameInfo gameInfo);

private slots:
    void startGame();
    void updatePlayerCount(int count);
    void updateStartMoney(int count);

private:
    Ui::MenuWindow *ui;
};

#endif // MAINWINDOW_H
