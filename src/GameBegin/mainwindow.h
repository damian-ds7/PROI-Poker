#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct GameInfo {
    GameInfo(std::string name, int count, int money) : player_name(name), player_count(count), initial_money(money) {}
    std::string player_name;
    int player_count;
    int initial_money;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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
