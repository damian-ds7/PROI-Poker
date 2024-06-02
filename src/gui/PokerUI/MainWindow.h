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
#include <QGridLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include "GameHandler.h"
#include "CardsTypedef.h"

class GameHandler;

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT
    std::shared_ptr<GameHandler> game_handler;

public:
    MainWindow(std::shared_ptr<GameHandler> Igame, QWidget* parent = nullptr);
    ~MainWindow();
    
    void InputNames(std::vector<std::string> names);
    void createWidgets(MainWindow* ptr);

    void PlayGame();

private:
    void createPlayerCards(MainWindow* ptr);
    void createTableCards(MainWindow* ptr);
    void createOpponentCards(MainWindow* ptr, const int opponents);
    void createOpponentLabels(MainWindow* ptr, const int opponents, const char* initial_money);
    void createPlayerLabels(MainWindow* ptr, const char* name, const char* initial_money);
    void createTableLabels(MainWindow* ptr);

    void createEndLabels(MainWindow* ptr);



    void setPlayerCards();
    void setTableCards();
    void setCash();

    void setButtons();
    void setBetButton(bool bet);
    void setCheckButton(bool check);

    //buttons signals
    void check();
    void bet();
    void fold();
    void all_in();
    void bet_confirmed();

    QLabel PlayerCard1;
    QLabel PlayerCard2;
    QLabel TableCard1;
    QLabel TableCard2;
    QLabel TableCard3;
    QLabel TableCard4;
    QLabel TableCard5;
    QLabel TableCardBack;
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
    QLabel Pot;
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
    QLabel PotToken;

    QLabel CurrentPotDecsription;

    QLabel EndBackground;
    QLabel EndWinner;
    QLabel EndToken;
    QLabel EndWinnerName;
    QLabel EndWinnerCash;

    Ui::Widget* ui;
};
#endif // WIDGET_H
