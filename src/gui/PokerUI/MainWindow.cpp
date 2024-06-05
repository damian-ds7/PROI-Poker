#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <utility>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //label.hide();
    //label.show();
	//label.raise();
	connect(ui->CheckButton, &QPushButton::clicked, this, &MainWindow::check);
	connect(ui->BetButton, &QPushButton::clicked, this, &MainWindow::bet);
	connect(ui->FoldButton, &QPushButton::clicked, this, &MainWindow::fold);
	connect(ui->AllInButton, &QPushButton::clicked, this, &MainWindow::all_in);
	connect(ui->ConfirmButton, &QPushButton::clicked, this, &MainWindow::bet_confirmed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createWidgets(MainWindow* ptr)
{
	std::string str = std::to_string(game_handler->game_info.initial_money);
	str.append("$");
	const char* cstr = str.c_str();
	const char* cplayer_name = game_handler->game_info.player_name.c_str();

	createPlayerCards(ptr);
    createTableCards(ptr);
    createOpponentCards(ptr, game_handler->game_info.player_count - 1);
	createOpponentLabels(ptr, game_handler->game_info.player_count - 1, cstr);
	createPlayerLabels(ptr, cplayer_name, cstr);
	createTableLabels(ptr);
	createEndLabels(ptr);


	//showEndScreen(false);
	ui->lineEdit->hide();
	ui->ConfirmButton->hide();
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
void MainWindow::createOpponentCards(MainWindow* ptr, const int opponents)
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

void MainWindow::createOpponentLabels(MainWindow* ptr, const int opponents, const char* initial_money)
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
		Opponent1Name.setText(game_handler->name_to_string(1).c_str());

		
		//
		Opponent1Status.setText("CALL");
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
		Opponent1Name.setText(game_handler->name_to_string(1).c_str());
		Opponent2Name.setText(game_handler->name_to_string(2).c_str());

		//
		Opponent1Status.setText("CALL");
		Opponent2Status.setText("CALL");
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
		Opponent2Name.setText(game_handler->name_to_string(2).c_str());
		Opponent3Name.setText(game_handler->name_to_string(3).c_str());

		//
		Opponent2Status.setText("CALL");
		Opponent3Status.setText("CALL");
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
		Opponent3Name.setText(game_handler->name_to_string(3).c_str());
		Opponent4Name.setText(game_handler->name_to_string(4).c_str());

		//
		Opponent4Status.setText("CALL");
		Opponent3Status.setText("CALL");
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
		Opponent4Name.setText(game_handler->name_to_string(4).c_str());
		Opponent5Name.setText(game_handler->name_to_string(5).c_str());

		//
		Opponent4Status.setText("CALL");
		Opponent5Status.setText("CALL");
		//
	}
}
void MainWindow::createPlayerLabels(MainWindow* ptr, const char* name, const char* initial_money)
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

	PlayerName.setText(name);
	PlayerCash.setText(initial_money);

	//
	PlayerStatus.setText("CALL");
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
}

void MainWindow::createEndLabels(MainWindow* ptr)
{
	QFont WinnerFont("Arial", 20, QFont::Bold);
	QFont WinnerNameFont("Arial", 30, QFont::Bold);
	QFont CashFont("Arial", 20, QFont::Bold);
	QPixmap token(":/resources/token.png");

	EndBackground.setParent(ptr);
	EndBackground.setFixedSize(400, 250);
	EndBackground.move(518, 144);
	EndBackground.setFrameStyle(QFrame::Panel | QFrame::Raised);
	EndBackground.setLineWidth(4);

	EndWinner.setParent(ptr);
	EndWinner.setFont(WinnerFont);
	EndWinner.setFixedWidth(400);
	EndWinner.setAlignment(Qt::AlignCenter);
	EndWinner.move(518, 185);
	EndWinner.setText("WINNER");

	EndWinnerName.setParent(ptr);
	EndWinnerName.setFont(WinnerNameFont);
	EndWinnerName.move(518, 230);
	EndWinnerName.setFixedWidth(400);
	EndWinnerName.setAlignment(Qt::AlignCenter);
	
	EndToken.setParent(ptr);
	EndToken.setScaledContents(true);
	EndToken.setFixedSize(30, 30);
	EndToken.move(660, 300);
	EndToken.setPixmap(token);

	EndWinnerCash.setParent(ptr);
	EndWinnerCash.setFont(CashFont);
	EndWinnerCash.move(695, 300);

	//
	EndWinnerCash.setText("+1000$");
	EndWinnerName.setText("Player 1");
	//
}

void MainWindow::PlayGame()
{
	setInitialStatus();
	game_handler->start_game();
	if (game_handler->game->players[0]->small_blind())
	{
		PlayerBlind();
	}
	else
	{
		game_handler->play_round("", 0);
	}
	setCash();
	setPlayerCards();
	setButtons();
	//setTableCards();
	showButtons();
	

	//if player turn
	//showButtons(true)

	//round end
	//showEndScreen(true);
}

void MainWindow::showButtons()
{
	ui->BetButton->setVisible(game_handler->game->current_player == 0);
	ui->CheckButton->setVisible(game_handler->game->current_player == 0);
	ui->FoldButton->setVisible(game_handler->game->current_player == 0);
	ui->AllInButton->setVisible(game_handler->game->current_player == 0);
}
void MainWindow::showEndScreen(bool visible)
{
	EndBackground.setVisible(visible);
	EndWinner.setVisible(visible);
	EndWinnerName.setVisible(visible);
	EndToken.setVisible(visible);
	EndWinnerCash.setVisible(visible);
}

void MainWindow::setPlayerCards()
{
	QPixmap qcard1(game_handler->game->players[0]->m_hand->at(0)->get_file_path().c_str());
	QPixmap qcard2(game_handler->game->players[0]->m_hand->at(1)->get_file_path().c_str());
	PlayerCard1.setPixmap(qcard1);
	PlayerCard2.setPixmap(qcard2);
}
void MainWindow::setTableCards()
{
	if (game_handler->phase_to_int() == 0)
	{
		TableCard1.hide();
		TableCard2.hide();
		TableCard3.hide();
		TableCard4.hide();
		TableCard5.hide();
	}
	else if (game_handler->phase_to_int() == 1)
	{
		QPixmap qcard1(game_handler->game->table->at(0)->get_file_path().c_str());
		QPixmap qcard2(game_handler->game->table->at(1)->get_file_path().c_str());
		QPixmap qcard3(game_handler->game->table->at(2)->get_file_path().c_str());
		TableCard1.setPixmap(qcard1);
		TableCard2.setPixmap(qcard2);
		TableCard3.setPixmap(qcard3);
		TableCard1.show();
		TableCard2.show();
		TableCard3.show();
	}
	else if (game_handler->phase_to_int() == 2)
	{
		QPixmap qcard4(game_handler->game->table->at(3)->get_file_path().c_str());
		TableCard4.setPixmap(qcard4);
		TableCard4.show();
	}
	else if (game_handler->phase_to_int() == 3)
	{
		QPixmap qcard5(game_handler->game->table->at(4)->get_file_path().c_str());
		TableCard5.setPixmap(qcard5);
		TableCard5.show();
	}
}
void MainWindow::setCash()
{
	PlayerCash.setText(game_handler->cash_to_QString(game_handler->game->players[0]->m_money));
	PlayerBet.setText(game_handler->cash_to_QString(game_handler->game->players[0]->m_bet));
	Opponent1Cash.setText(game_handler->cash_to_QString(game_handler->game->players[1]->m_money));
	Opponent1Bet.setText(game_handler->cash_to_QString(game_handler->game->players[1]->m_bet));
	if (game_handler->game_info.player_count > 2)
	{
		Opponent2Cash.setText(game_handler->cash_to_QString(game_handler->game->players[2]->m_money));
		Opponent2Bet.setText(game_handler->cash_to_QString(game_handler->game->players[2]->m_bet));
	}
	if (game_handler->game_info.player_count > 3)
	{
		Opponent3Cash.setText(game_handler->cash_to_QString(game_handler->game->players[3]->m_money));
		Opponent3Bet.setText(game_handler->cash_to_QString(game_handler->game->players[3]->m_bet));
	}
	if (game_handler->game_info.player_count > 4)
	{
		Opponent4Cash.setText(game_handler->cash_to_QString(game_handler->game->players[4]->m_money));
		Opponent4Bet.setText(game_handler->cash_to_QString(game_handler->game->players[4]->m_bet));
	}
	if (game_handler->game_info.player_count > 5)
	{
		Opponent5Cash.setText(game_handler->cash_to_QString(game_handler->game->players[5]->m_money));
		Opponent5Bet.setText(game_handler->cash_to_QString(game_handler->game->players[5]->m_bet));
	}
	Pot.setText(game_handler->cash_to_QString(game_handler->game->pot));
}
void MainWindow::setStatus()
{
	//TODO
}
void MainWindow::setInitialStatus()
{
	PlayerStatus.setText(game_handler->begin_status_to_string(0).c_str());
	Opponent1Status.setText(game_handler->begin_status_to_string(1).c_str());
	if (game_handler->game_info.player_count > 2)
	{
		Opponent2Status.setText(game_handler->begin_status_to_string(2).c_str());
	}
	if (game_handler->game_info.player_count > 3)
	{
		Opponent3Status.setText(game_handler->begin_status_to_string(3).c_str());
	}
	if (game_handler->game_info.player_count > 4)
	{
		Opponent4Status.setText(game_handler->begin_status_to_string(4).c_str());
	}
	if (game_handler->game_info.player_count > 5)
	{
		Opponent5Status.setText(game_handler->begin_status_to_string(5).c_str());
	}
}

void MainWindow::setBetButton(bool bet)
{
	if (bet)
	{
		ui->BetButton->setText("Bet");
	}
	else
	{
		ui->BetButton->setText("Raise");
	}
}
void MainWindow::setCheckButton(bool check)
{
	if (check)
	{
		ui->CheckButton->setText("Check");
	}
	else
	{
		ui->CheckButton->setText("Call");
	}
}
void MainWindow::setButtons()
{
	if (game_handler->game->pot == 0)
	{
		setBetButton(true);
		setCheckButton(true);
	}
	else
	{
		setBetButton(false);
		setCheckButton(false);
	}
}

void MainWindow::setWinnerScreen()
{
	//set winner name
	EndWinnerCash.setText(game_handler->cash_to_QString(game_handler->game->pot));
}

void MainWindow::PlayerBlind()
{
	if (game_handler->game->players[0]->small_blind())
	{
		ui->CheckButton->hide();
		ui->FoldButton->hide();
		ui->AllInButton->hide();
	}
}

void MainWindow::check()
{
	if (game_handler->game->pot == 0)
	{
		game_handler->play_round("CHECK", 0);
	}
	else
	{
		game_handler->play_round("CALL", 0);
	}
}
void MainWindow::bet()
{
	ui->lineEdit->show();
	ui->ConfirmButton->show();
}
void MainWindow::fold()
{
	game_handler->play_round("FOLD", 0);
}
void MainWindow::all_in()
{
	game_handler->play_round("ALL IN", 0);
}
void MainWindow::bet_confirmed()
{
	if (game_handler->game->pot == 0)
	{
		game_handler->play_round("BET", ui->lineEdit->text().toInt());
	}
	else
	{
		game_handler->play_round("RAISE", ui->lineEdit->text().toInt());
	}
	ui->lineEdit->clear();
	ui->lineEdit->hide();
	ui->ConfirmButton->hide();
}



void MainWindow::InputNames(std::vector<std::string> names)
{
	//TODO
}
