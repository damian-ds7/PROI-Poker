#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //label.hide();
    //label.show();
	//label.raise();

    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createWidgets(MainWindow* ptr, int opponents, int initial_money, QString player_name)
{
	std::string str = std::to_string(initial_money);
	const char* cstr = str.c_str();

	createPlayerCards(ptr);
    createTableCards(ptr);
    createOpponentCards(ptr, opponents);
	createOpponentLabels(ptr, opponents, cstr);
	createPlayerLabels(ptr, player_name, cstr);
	createTableLabels(ptr);
}

void MainWindow::createPlayerCards(MainWindow* ptr)
{
	PlayerCard1.setParent(ptr);
	PlayerCard1.setScaledContents(true);
	PlayerCard1.setFixedSize(107, 150);
	PlayerCard1.move(440, 520);

	PlayerCard2.setParent(ptr);
	PlayerCard2.setScaledContents(true);
	PlayerCard2.setFixedSize(107, 150);
	PlayerCard2.move(560, 520);


	//
	QPixmap pcard1(":/resources/Deck/clubs_ace.png");
	PlayerCard1.setPixmap(pcard1);
	QPixmap pcard2(":/resources/Deck/clubs_two.png");
	PlayerCard2.setPixmap(pcard2);
	//
}
void MainWindow::createTableCards(MainWindow* ptr)
{
	TableCard1.setParent(ptr);
	TableCard1.setScaledContents(true);
	TableCard1.setFixedSize(107, 150);
	TableCard1.move(340, 225);

	TableCard2.setParent(ptr);
	TableCard2.setScaledContents(true);
	TableCard2.setFixedSize(107, 150);
	TableCard2.move(460, 225);

	TableCard3.setParent(ptr);
	TableCard3.setScaledContents(true);
	TableCard3.setFixedSize(107, 150);
	TableCard3.move(580, 225);

	TableCard4.setParent(ptr);
	TableCard4.setScaledContents(true);
	TableCard4.setFixedSize(107, 150);
	TableCard4.move(700, 225);

	TableCard5.setParent(ptr);
	TableCard5.setScaledContents(true);
	TableCard5.setFixedSize(107, 150);
	TableCard5.move(820, 225);

	TableCardBack.setParent(ptr);
	TableCardBack.setScaledContents(true);
	TableCardBack.setFixedSize(107, 150);
	TableCardBack.move(1000, 225);
	QPixmap tcardback(":/resources/Deck/card_back.png");
	TableCardBack.setPixmap(tcardback);



	//
	QPixmap tcard1(":/resources/Deck/clubs_three.png");
	TableCard1.setPixmap(tcard1);
	QPixmap tcard2(":/resources/Deck/clubs_four.png");
	TableCard2.setPixmap(tcard2);
	QPixmap tcard3(":/resources/Deck/clubs_five.png");
	TableCard3.setPixmap(tcard3);
	QPixmap tcard4(":/resources/Deck/clubs_six.png");
	TableCard4.setPixmap(tcard4);
	QPixmap tcard5(":/resources/Deck/clubs_seven.png");
	TableCard5.setPixmap(tcard5);
	//
}
void MainWindow::createOpponentCards(MainWindow* ptr, int opponents)
{
	QPixmap ocard(":/resources/Deck/card_back.png");
	QTransform transform;
	transform.rotate(90);
	QPixmap ocardr = ocard.transformed(transform);

	if (opponents == 1 || opponents == 3 || opponents == 5)
	{
		//Opponent 1
		Opponent1Card1.setParent(ptr);
		Opponent1Card1.setScaledContents(true);
		Opponent1Card1.setFixedSize(80, 110);
		Opponent1Card1.move(670, -80);

		Opponent1Card2.setParent(ptr);
		Opponent1Card2.setScaledContents(true);
		Opponent1Card2.setFixedSize(80, 110);
		Opponent1Card2.move(700, -80);


		Opponent1Card1.setPixmap(ocard);
		Opponent1Card2.setPixmap(ocard);
	}
	if (opponents == 2 || opponents == 4)
	{
		//Opponent 1
		Opponent1Card1.setParent(ptr);
		Opponent1Card1.setScaledContents(true);
		Opponent1Card1.setFixedSize(80, 110);
		Opponent1Card1.move(300, -80);

		Opponent1Card2.setParent(ptr);
		Opponent1Card2.setScaledContents(true);
		Opponent1Card2.setFixedSize(80, 110);
		Opponent1Card2.move(330, -80);

		Opponent1Card1.setPixmap(ocard);
		Opponent1Card2.setPixmap(ocard);
		

		//Opponent 2
		Opponent2Card1.setParent(ptr);
		Opponent2Card1.setScaledContents(true);
		Opponent2Card1.setFixedSize(80, 110);
		Opponent2Card1.move(1010, -80);

		Opponent2Card2.setParent(ptr);
		Opponent2Card2.setScaledContents(true);
		Opponent2Card2.setFixedSize(80, 110);
		Opponent2Card2.move(1040, -80);

		Opponent2Card1.setPixmap(ocard);
		Opponent2Card2.setPixmap(ocard);
	}
	if (opponents == 3 || opponents == 5)
	{
		//Opponent 2
		Opponent2Card1.setParent(ptr);
		Opponent2Card1.setScaledContents(true);
		Opponent2Card1.setFixedSize(80, 110);
		Opponent2Card1.move(-50, 200);

		Opponent2Card2.setParent(ptr);
		Opponent2Card2.setScaledContents(true);
		Opponent2Card2.setFixedSize(80, 110);
		Opponent2Card2.move(-50, 230);

		Opponent2Card1.setPixmap(ocardr);
		Opponent2Card2.setPixmap(ocardr);


		//Opponent 3
		Opponent3Card1.setParent(ptr);
		Opponent3Card1.setScaledContents(true);
		Opponent3Card1.setFixedSize(80, 110);
		Opponent3Card1.move(1400, 200);

		Opponent3Card2.setParent(ptr);
		Opponent3Card2.setScaledContents(true);
		Opponent3Card2.setFixedSize(80, 110);
		Opponent3Card2.move(1400, 230);

		Opponent3Card1.setPixmap(ocardr);
		Opponent3Card2.setPixmap(ocardr);
	}
	if (opponents == 4) 
	{
		//Opponent 3
		Opponent3Card1.setParent(ptr);
		Opponent3Card1.setScaledContents(true);
		Opponent3Card1.setFixedSize(80, 110);
		Opponent3Card1.move(-50, 200);

		Opponent3Card2.setParent(ptr);
		Opponent3Card2.setScaledContents(true);
		Opponent3Card2.setFixedSize(80, 110);
		Opponent3Card2.move(-50, 230);

		Opponent3Card1.setPixmap(ocardr);
		Opponent3Card2.setPixmap(ocardr);

		//Opponent 4
		Opponent4Card1.setParent(ptr);
		Opponent4Card1.setScaledContents(true);
		Opponent4Card1.setFixedSize(80, 110);
		Opponent4Card1.move(1400, 200);

		Opponent4Card2.setParent(ptr);
		Opponent4Card2.setScaledContents(true);
		Opponent4Card2.setFixedSize(80, 110);
		Opponent4Card2.move(1400, 230);

		Opponent4Card1.setPixmap(ocardr);
		Opponent4Card2.setPixmap(ocardr);
	}
	if (opponents == 5)
	{
		//Opponent 4
		Opponent4Card1.setParent(ptr);
		Opponent4Card1.setScaledContents(true);
		Opponent4Card1.setFixedSize(80, 110);
		Opponent4Card1.move(300, -80);

		Opponent4Card2.setParent(ptr);
		Opponent4Card2.setScaledContents(true);
		Opponent4Card2.setFixedSize(80, 110);
		Opponent4Card2.move(330, -80);

		Opponent4Card1.setPixmap(ocard);
		Opponent4Card2.setPixmap(ocard);


		//Opponent 5
		Opponent5Card1.setParent(ptr);
		Opponent5Card1.setScaledContents(true);
		Opponent5Card1.setFixedSize(80, 110);
		Opponent5Card1.move(1010, -80);

		Opponent5Card2.setParent(ptr);
		Opponent5Card2.setScaledContents(true);
		Opponent5Card2.setFixedSize(80, 110);
		Opponent5Card2.move(1040, -80);

		Opponent5Card1.setPixmap(ocard);
		Opponent5Card2.setPixmap(ocard);
	}
}

void MainWindow::createOpponentLabels(MainWindow* ptr, int opponents, const char* initial_money)
{
	QFont NameFont("Arial", 14, QFont::Bold);
	QFont CashFont("Arial", 13, QFont::Bold);
	QFont StatusFont("Arial", 18, QFont::Bold);
	QPixmap token(":/resources/token.png");

	if (opponents == 1 || opponents == 3 || opponents == 5)
	{
		//Opponent 1
		Opponent1Name.setParent(ptr);
		Opponent1Name.setFont(NameFont);
		Opponent1Name.setStyleSheet("background: transparent;");
		Opponent1Name.move(800, 5);

		Opponent1Cash.setParent(ptr);
		Opponent1Cash.setFont(CashFont);
		Opponent1Cash.move(825, 30);

		Opponent1Status.setParent(ptr);
		Opponent1Status.setFont(StatusFont);
		Opponent1Status.move(800, 60);

		Opponent1Bet.setParent(ptr);
		Opponent1Bet.setFont(CashFont);
		Opponent1Bet.setStyleSheet("background: transparent;");
		Opponent1Bet.move(735, 150);

		Opponent1SelfToken.setParent(ptr);
		Opponent1SelfToken.setScaledContents(true);
		Opponent1SelfToken.setStyleSheet("background: transparent;");
		Opponent1SelfToken.setFixedSize(20, 20);
		Opponent1SelfToken.move(800, 29);
		Opponent1SelfToken.setPixmap(token);

		Opponent1TableToken.setParent(ptr);
		Opponent1TableToken.setScaledContents(true);
		Opponent1TableToken.setStyleSheet("background: transparent;");
		Opponent1TableToken.setFixedSize(20, 20);
		Opponent1TableToken.move(710, 149);
		Opponent1TableToken.setPixmap(token);

		Opponent1Cash.setText(initial_money);

		
		//
		Opponent1Name.setText("Opponent 1");
		Opponent1Status.setText("CALL");
		Opponent1Bet.setText("100$");
		//

	}
	if (opponents == 2 || opponents == 4)
	{
		//Opponent 1
		Opponent1Name.setParent(ptr);
		Opponent1Name.setFont(NameFont);
		Opponent1Name.setStyleSheet("background: transparent;");
		Opponent1Name.move(430, 5);

		Opponent1Cash.setParent(ptr);
		Opponent1Cash.setFont(CashFont);
		Opponent1Cash.move(455, 30);

		Opponent1Status.setParent(ptr);
		Opponent1Status.setFont(StatusFont);
		Opponent1Status.move(430, 60);

		Opponent1Bet.setParent(ptr);
		Opponent1Bet.setFont(CashFont);
		Opponent1Bet.setStyleSheet("background: transparent;");
		Opponent1Bet.move(335, 150);

		Opponent1SelfToken.setParent(ptr);
		Opponent1SelfToken.setScaledContents(true);
		Opponent1SelfToken.setStyleSheet("background: transparent;");
		Opponent1SelfToken.setFixedSize(20, 20);
		Opponent1SelfToken.move(430, 29);
		Opponent1SelfToken.setPixmap(token);

		Opponent1TableToken.setParent(ptr);
		Opponent1TableToken.setScaledContents(true);
		Opponent1TableToken.setStyleSheet("background: transparent;");
		Opponent1TableToken.setFixedSize(20, 20);
		Opponent1TableToken.move(310, 149);
		Opponent1TableToken.setPixmap(token);

		//Opponent 2
		Opponent2Name.setParent(ptr);
		Opponent2Name.setFont(NameFont);
		Opponent2Name.setStyleSheet("background: transparent;");
		Opponent2Name.move(1140, 5);
		
		Opponent2Cash.setParent(ptr);
		Opponent2Cash.setFont(CashFont);
		Opponent2Cash.move(1165, 30);

		Opponent2Status.setParent(ptr);
		Opponent2Status.setFont(StatusFont);
		Opponent2Status.move(1140, 60);

		Opponent2Bet.setParent(ptr);
		Opponent2Bet.setFont(CashFont);
		Opponent2Bet.setStyleSheet("background: transparent;");
		Opponent2Bet.move(1085, 150);

		Opponent2SelfToken.setParent(ptr);
		Opponent2SelfToken.setScaledContents(true);
		Opponent2SelfToken.setStyleSheet("background: transparent;");
		Opponent2SelfToken.setFixedSize(20, 20);
		Opponent2SelfToken.move(1140, 29);
		Opponent2SelfToken.setPixmap(token);

		Opponent2TableToken.setParent(ptr);
		Opponent2TableToken.setScaledContents(true);
		Opponent2TableToken.setStyleSheet("background: transparent;");
		Opponent2TableToken.setFixedSize(20, 20);
		Opponent2TableToken.move(1060, 149);
		Opponent2TableToken.setPixmap(token);

		Opponent1Cash.setText(initial_money);
		Opponent2Cash.setText(initial_money);

		//
		Opponent1Name.setText("Opponent 1");
		Opponent1Status.setText("CALL");
		Opponent1Bet.setText("100$");
		Opponent2Name.setText("Opponent 2");
		Opponent2Status.setText("CALL");
		Opponent2Bet.setText("100$");
		//
	}
	if (opponents == 3 || opponents == 5)
	{
		//Opponent 2
		Opponent2Name.setParent(ptr);
		Opponent2Name.setFont(NameFont);
		Opponent2Name.setStyleSheet("background: transparent;");
		Opponent2Name.move(5, 110);

		Opponent2Cash.setParent(ptr);
		Opponent2Cash.setFont(CashFont);
		Opponent2Cash.move(30, 135);

		Opponent2Status.setParent(ptr);
		Opponent2Status.setFont(StatusFont);
		Opponent2Status.move(5, 165);

		Opponent2Bet.setParent(ptr);
		Opponent2Bet.setFont(CashFont);
		Opponent2Bet.setStyleSheet("background: transparent;");
		Opponent2Bet.move(205, 285);

		Opponent2SelfToken.setParent(ptr);
		Opponent2SelfToken.setScaledContents(true);
		Opponent2SelfToken.setStyleSheet("background: transparent;");
		Opponent2SelfToken.setFixedSize(20, 20);
		Opponent2SelfToken.move(5, 134);
		Opponent2SelfToken.setPixmap(token);

		Opponent2TableToken.setParent(ptr);
		Opponent2TableToken.setScaledContents(true);
		Opponent2TableToken.setStyleSheet("background: transparent;");
		Opponent2TableToken.setFixedSize(20, 20);
		Opponent2TableToken.move(180, 284);
		Opponent2TableToken.setPixmap(token);

		//Opponent 3
		Opponent3Name.setParent(ptr);
		Opponent3Name.setFont(NameFont);
		Opponent3Name.setStyleSheet("background: transparent;");
		Opponent3Name.move(1320, 110);

		Opponent3Cash.setParent(ptr);
		Opponent3Cash.setFont(CashFont);
		Opponent3Cash.move(1345, 135);

		Opponent3Status.setParent(ptr);
		Opponent3Status.setFont(StatusFont);
		Opponent3Status.move(1320, 165);

		Opponent3Bet.setParent(ptr);
		Opponent3Bet.setFont(CashFont);
		Opponent3Bet.setStyleSheet("background: transparent;");
		Opponent3Bet.move(1225, 285);

		Opponent3SelfToken.setParent(ptr);
		Opponent3SelfToken.setScaledContents(true);
		Opponent3SelfToken.setStyleSheet("background: transparent;");
		Opponent3SelfToken.setFixedSize(20, 20);
		Opponent3SelfToken.move(1320, 134);
		Opponent3SelfToken.setPixmap(token);

		Opponent3TableToken.setParent(ptr);
		Opponent3TableToken.setScaledContents(true);
		Opponent3TableToken.setStyleSheet("background: transparent;");
		Opponent3TableToken.setFixedSize(20, 20);
		Opponent3TableToken.move(1205, 284);
		Opponent3TableToken.setPixmap(token);

		Opponent2Cash.setText(initial_money);
		Opponent3Cash.setText(initial_money);

		//
		Opponent2Name.setText("Opponent 2");
		Opponent2Status.setText("CALL");
		Opponent2Bet.setText("100$");
		Opponent3Name.setText("Opponent 3");
		Opponent3Status.setText("CALL");
		Opponent3Bet.setText("100$");	
		//
	}
	if (opponents == 4)
	{
		//Opponent 3
		Opponent3Name.setParent(ptr);
		Opponent3Name.setFont(NameFont);
		Opponent3Name.setStyleSheet("background: transparent;");
		Opponent3Name.move(1320, 110);

		Opponent3Cash.setParent(ptr);
		Opponent3Cash.setFont(CashFont);
		Opponent3Cash.move(1345, 135);

		Opponent3Status.setParent(ptr);
		Opponent3Status.setFont(StatusFont);
		Opponent3Status.move(1320, 165);

		Opponent3Bet.setParent(ptr);
		Opponent3Bet.setFont(CashFont);
		Opponent3Bet.setStyleSheet("background: transparent;");
		Opponent3Bet.move(1225, 285);

		Opponent3SelfToken.setParent(ptr);
		Opponent3SelfToken.setScaledContents(true);
		Opponent3SelfToken.setStyleSheet("background: transparent;");
		Opponent3SelfToken.setFixedSize(20, 20);
		Opponent3SelfToken.move(1320, 134);
		Opponent3SelfToken.setPixmap(token);

		Opponent3TableToken.setParent(ptr);
		Opponent3TableToken.setScaledContents(true);
		Opponent3TableToken.setStyleSheet("background: transparent;");
		Opponent3TableToken.setFixedSize(20, 20);
		Opponent3TableToken.move(1205, 284);
		Opponent3TableToken.setPixmap(token);

		//Opponent 4
		Opponent4Name.setParent(ptr);
		Opponent4Name.setFont(NameFont);
		Opponent4Name.setStyleSheet("background: transparent;");
		Opponent4Name.move(5, 110);

		Opponent4Cash.setParent(ptr);
		Opponent4Cash.setFont(CashFont);
		Opponent4Cash.move(30, 135);

		Opponent4Status.setParent(ptr);
		Opponent4Status.setFont(StatusFont);
		Opponent4Status.move(5, 165);

		Opponent4Bet.setParent(ptr);
		Opponent4Bet.setFont(CashFont);
		Opponent4Bet.setStyleSheet("background: transparent;");
		Opponent4Bet.move(205, 285);

		Opponent4SelfToken.setParent(ptr);
		Opponent4SelfToken.setScaledContents(true);
		Opponent4SelfToken.setStyleSheet("background: transparent;");
		Opponent4SelfToken.setFixedSize(20, 20);
		Opponent4SelfToken.move(5, 134);
		Opponent4SelfToken.setPixmap(token);

		Opponent4TableToken.setParent(ptr);
		Opponent4TableToken.setScaledContents(true);
		Opponent4TableToken.setStyleSheet("background: transparent;");
		Opponent4TableToken.setFixedSize(20, 20);
		Opponent4TableToken.move(180, 284);
		Opponent4TableToken.setPixmap(token);

		Opponent4Cash.setText(initial_money);
		Opponent3Cash.setText(initial_money);

		//
		Opponent4Name.setText("Opponent 4");
		Opponent4Status.setText("CALL");
		Opponent4Bet.setText("100$");
		Opponent3Name.setText("Opponent 3");
		Opponent3Status.setText("CALL");
		Opponent3Bet.setText("100$");
		//
	}
	if (opponents == 5)
	{
		//Opponent 4
		Opponent4Name.setParent(ptr);
		Opponent4Name.setFont(NameFont);
		Opponent4Name.setStyleSheet("background: transparent;");
		Opponent4Name.move(430, 5);

		Opponent4Cash.setParent(ptr);
		Opponent4Cash.setFont(CashFont);
		Opponent4Cash.move(455, 30);

		Opponent4Status.setParent(ptr);
		Opponent4Status.setFont(StatusFont);
		Opponent4Status.move(430, 60);

		Opponent4Bet.setParent(ptr);
		Opponent4Bet.setFont(CashFont);
		Opponent4Bet.setStyleSheet("background: transparent;");
		Opponent4Bet.move(335, 150);

		Opponent4SelfToken.setParent(ptr);
		Opponent4SelfToken.setScaledContents(true);
		Opponent4SelfToken.setStyleSheet("background: transparent;");
		Opponent4SelfToken.setFixedSize(20, 20);
		Opponent4SelfToken.move(430, 29);
		Opponent4SelfToken.setPixmap(token);

		Opponent4TableToken.setParent(ptr);
		Opponent4TableToken.setScaledContents(true);
		Opponent4TableToken.setStyleSheet("background: transparent;");
		Opponent4TableToken.setFixedSize(20, 20);
		Opponent4TableToken.move(310, 149);
		Opponent4TableToken.setPixmap(token);

		//Opponent 5
		Opponent5Name.setParent(ptr);
		Opponent5Name.setFont(NameFont);
		Opponent5Name.setStyleSheet("background: transparent;");
		Opponent5Name.move(1140, 5);

		Opponent5Cash.setParent(ptr);
		Opponent5Cash.setFont(CashFont);
		Opponent5Cash.move(1165, 30);

		Opponent5Status.setParent(ptr);
		Opponent5Status.setFont(StatusFont);
		Opponent5Status.move(1140, 60);

		Opponent5Bet.setParent(ptr);
		Opponent5Bet.setFont(CashFont);
		Opponent5Bet.setStyleSheet("background: transparent;");
		Opponent5Bet.move(1085, 150);

		Opponent5SelfToken.setParent(ptr);
		Opponent5SelfToken.setScaledContents(true);
		Opponent5SelfToken.setStyleSheet("background: transparent;");
		Opponent5SelfToken.setFixedSize(20, 20);
		Opponent5SelfToken.move(1140, 29);
		Opponent5SelfToken.setPixmap(token);

		Opponent5TableToken.setParent(ptr);
		Opponent5TableToken.setScaledContents(true);
		Opponent5TableToken.setStyleSheet("background: transparent;");
		Opponent5TableToken.setFixedSize(20, 20);
		Opponent5TableToken.move(1060, 149);
		Opponent5TableToken.setPixmap(token);

		Opponent4Cash.setText(initial_money);
		Opponent5Cash.setText(initial_money);

		//
		Opponent4Name.setText("Opponent 4");
		Opponent4Status.setText("CALL");
		Opponent4Bet.setText("100$");
		Opponent5Name.setText("Opponent 5");
		Opponent5Status.setText("CALL");
		Opponent5Bet.setText("100$");
		//
	}
}
void MainWindow::createPlayerLabels(MainWindow* ptr, QString name, const char* initial_money)
{
	QFont NameFont("Arial", 20, QFont::Bold);
	QFont CashFont("Arial", 17, QFont::Bold);
	QFont StatusFont("Arial", 26, QFont::Bold);
	QPixmap token(":/resources/token.png");

	PlayerName.setParent(ptr);
	PlayerName.setFont(NameFont);
	PlayerName.setStyleSheet("background: transparent;");
	PlayerName.move(280, 520);

	PlayerCash.setParent(ptr);
	PlayerCash.setFont(CashFont);
	PlayerCash.move(315, 555);

	PlayerStatus.setParent(ptr);
	PlayerStatus.setFont(StatusFont);
	PlayerStatus.move(280, 600);

	PlayerBet.setParent(ptr);
	PlayerBet.setFont(CashFont);
	PlayerBet.setStyleSheet("background: transparent;");
	PlayerBet.move(495, 415);

	PlayerSelfToken.setParent(ptr);
	PlayerSelfToken.setScaledContents(true);
	PlayerSelfToken.setStyleSheet("background: transparent;");
	PlayerSelfToken.setFixedSize(30, 30);
	PlayerSelfToken.move(280, 554);
	PlayerSelfToken.setPixmap(token);

	PlayerTableToken.setParent(ptr);
	PlayerTableToken.setScaledContents(true);
	PlayerTableToken.setStyleSheet("background: transparent;");
	PlayerTableToken.setFixedSize(30, 30);
	PlayerTableToken.move(460, 415);
	PlayerTableToken.setPixmap(token);

	//
	PlayerName.setText("Player");
	PlayerCash.setText("1000$");
	PlayerStatus.setText("CALL");
	PlayerBet.setText("100$");
}
void MainWindow::createTableLabels(MainWindow* ptr)
{
	QFont PotFont("Arial", 17, QFont::Bold);
	QPixmap token(":/resources/token.png");

	Pot.setParent(ptr);
	Pot.setFont(PotFont);
	Pot.setStyleSheet("background: transparent;");
	Pot.move(1035, 415);

	CurrentPotDecsription.setParent(ptr);
	CurrentPotDecsription.setFont(PotFont);
	CurrentPotDecsription.setStyleSheet("background: transparent;");
	CurrentPotDecsription.move(860, 415);
	CurrentPotDecsription.setText("Current pot:");

	PotToken.setParent(ptr);
	PotToken.setScaledContents(true);
	PotToken.setStyleSheet("background: transparent;");
	PotToken.setFixedSize(30, 30);
	PotToken.move(1000, 414);
	PotToken.setPixmap(token);

	//
	Pot.setText("600$");
	//
}




void MainWindow::showPlayerCards(bool visible)
{
	if (visible == false)
	{
		PlayerCard1.hide();
		PlayerCard2.hide();
	}
	else
	{
		PlayerCard1.show();
		PlayerCard2.show();
	}
}

void MainWindow::InputNames(std::vector<std::string> names)
{
	//TODO
}
