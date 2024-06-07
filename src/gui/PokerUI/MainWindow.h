#ifndef WIDGET_H
#define WIDGET_H

#include "GameInfo.h"
#include "GameHandler.h"
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTransform>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <QTimer>
#include "GameHandler.h"
#include "CardsTypedef.h"
#include "menu.h"
#include "Decision.h"
#include "UIPlayer/UIPlayer.h"
#include <vector>


class GameHandler;
class UIPlayer;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT
    std::unique_ptr<GameHandler> game_handler;

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    
    void InputNames(std::vector<std::string> names);
    void createWidgets(MainWindow* ptr);

    void StartGame();
    void PlayGame();

    void playerMakeDecision(Decision decision, int bet);
    void playerMakeSmallBlind(int bet);
    void botMakeMove();

    QTimer* bot_cooldown;

signals:
    void decisionMade(Decision decision, int bet);
signals:
    void smallBlindMade(int bet);
signals:
    void botMove();

private:
    void BigBlind();

    friend class MenuWindow;

    void createPlayers(MainWindow* ptr);

    void createTableCards(MainWindow* ptr);
    void movePlayerLabels();
    void moveOpponentLabels();

    void createEndLabels(MainWindow* ptr);

    void showButtons();
    void showEndScreen(bool visible);
    void showPlayersCards();

    void setPlayerCards();
    void setTableCards();
    void setCash();
    void setStatus();
    void setCurrentPlayer();

    void setButtons();
    void setBetButton(bool bet);
    void setCheckButton(bool check);

    void setWinnerScreen();
    void reverseCards(bool front);



    //buttons signals
    void check();
    void bet();
    void fold();
    void all_in();
    void bet_confirmed();
    void small_blind();
    void small_blind_confirmed();

    void bot_timer_ended();

    std::vector<std::unique_ptr<UIPlayer>> uiplayers;
    QLabel* TableCards[6];

    QLabel EndBackground;
    QLabel EndWinner;
    QLabel EndToken;
    QLabel EndWinnerName;
    QLabel EndWinnerCash;

    Ui::Widget* ui;
};
#endif // WIDGET_H
