#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <memory>
#include <QMainWindow>
#include <QKeyEvent>
#include "GameInfo.h"
#include "GameHandler.h"
#include "MainWindow.h"



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
protected:
    void keyPressEvent(QKeyEvent *event) override;

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
