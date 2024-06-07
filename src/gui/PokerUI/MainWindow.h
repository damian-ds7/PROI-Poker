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


class GameHandler;

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

    void createPlayerCards(MainWindow* ptr);
    void createTableCards(MainWindow* ptr);
    void createOpponentCards(MainWindow* ptr, unsigned int opponents);
    void createOpponentLabels(MainWindow* ptr, unsigned int opponents, const char* initial_money);
    void createPlayerLabels(MainWindow* ptr, const char* name, const char* initial_money);

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

    QLabel PlayerCard1;
    QLabel PlayerCard2;
    QLabel* TableCards[6];
    QLabel Opponent1Card1;
    QLabel Opponent1Card2;
    QLabel Opponent2Card1;
    QLabel Opponent2Card2;
    QLabel Opponent3Card1;
    QLabel Opponent3Card2;
    QLabel Opponent4Card1;
    QLabel Opponent4Card2;
    QLabel Opponent5Card1;
    QLabel Opponent5Card2;

    QLabel PlayerName;
    QLabel Opponent1Name;
    QLabel Opponent2Name;
    QLabel Opponent3Name;
    QLabel Opponent4Name;
    QLabel Opponent5Name;
    QLabel PlayerCash;
    QLabel Opponent1Cash;
    QLabel Opponent2Cash;
    QLabel Opponent3Cash;
    QLabel Opponent4Cash;
    QLabel Opponent5Cash;
    QLabel PlayerBet;
    QLabel Opponent1Bet;
    QLabel Opponent2Bet;
    QLabel Opponent3Bet;
    QLabel Opponent4Bet;
    QLabel Opponent5Bet;
    QLabel PlayerStatus;
    QLabel Opponent1Status;
    QLabel Opponent2Status;
    QLabel Opponent3Status;
    QLabel Opponent4Status;
    QLabel Opponent5Status;

    QLabel PlayerSelfToken;
    QLabel Opponent1SelfToken;
    QLabel Opponent2SelfToken;
    QLabel Opponent3SelfToken;
    QLabel Opponent4SelfToken;
    QLabel Opponent5SelfToken;
    QLabel PlayerTableToken;
    QLabel Opponent1TableToken;
    QLabel Opponent2TableToken;
    QLabel Opponent3TableToken;
    QLabel Opponent4TableToken;
    QLabel Opponent5TableToken;


    QLabel EndBackground;
    QLabel EndWinner;
    QLabel EndToken;
    QLabel EndWinnerName;
    QLabel EndWinnerCash;

    Ui::Widget* ui;
};
#endif // WIDGET_H
