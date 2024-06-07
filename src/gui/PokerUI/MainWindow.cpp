#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <utility>

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
	bot_cooldown = new QTimer(this);
	bot_cooldown->setSingleShot(true);
	connect(ui->CheckButton, &QPushButton::clicked, this, &MainWindow::check);
	connect(ui->BetButton, &QPushButton::clicked, this, &MainWindow::bet);
	connect(ui->FoldButton, &QPushButton::clicked, this, &MainWindow::fold);
	connect(ui->AllInButton, &QPushButton::clicked, this, &MainWindow::all_in);
	connect(ui->ConfirmButton, &QPushButton::clicked, this, &MainWindow::bet_confirmed);
	connect(ui->SmallBlindButton, &QPushButton::clicked, this, &MainWindow::small_blind);
	connect(ui->ConfirmSmallBlindButton, &QPushButton::clicked, this, &MainWindow::small_blind_confirmed);
	connect(bot_cooldown, &QTimer::timeout, this, &MainWindow::bot_timer_ended);
}

MainWindow::~MainWindow()
{
	delete bot_cooldown;
    delete ui;
	for (int i = 0; i < 6; i++)
	{
		delete TableCards[i];
	}
}

void MainWindow::createWidgets(MainWindow* ptr)
{
	std::string str = std::to_string(game_handler->initial_money());
	str.append("$");
	const char* cstr = str.c_str();
    std::string player_name = game_handler->player_name();
	const char* cplayer_name = player_name.c_str();

	createPlayerCards(ptr);
    createTableCards(ptr);
    createOpponentCards(ptr, game_handler->player_count() - 1);
	createOpponentLabels(ptr, game_handler->player_count() - 1, cstr);
	createPlayerLabels(ptr, cplayer_name, cstr);
	createEndLabels(ptr);


	showEndScreen(false);
	ui->lineEdit->hide();
	ui->ConfirmButton->hide();
	ui->ConfirmSmallBlindButton->hide();
}

void MainWindow::createPlayers(MainWindow* ptr, const unsigned int opponents, const char* initial_money)
{
	uiplayers.push_back(std::make_unique<UIPlayer>(ptr));
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

	QPixmap card(":/resources/Deck/card_back.png");
	PlayerCard1.setPixmap(card);
	PlayerCard2.setPixmap(card);
}
void MainWindow::createTableCards(MainWindow* ptr)
{
	for (int i = 0; i < 6; i++)
	{
		TableCards[i] = new QLabel(ptr);
		TableCards[i]->setScaledContents(true);
		TableCards[i]->setFixedSize(107, 150);
		TableCards[i]->move(340 + i * 120, 225);
	}

	TableCards[5]->move(1000, 225);
	TableCards[5]->setPixmap(QPixmap(":/resources/Deck/card_back.png"));
}
void MainWindow::createOpponentCards(MainWindow* ptr, const unsigned int opponents)
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

void MainWindow::createOpponentLabels(MainWindow* ptr, const unsigned int opponents, const char* initial_money)
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
		Opponent1Status.setText("SMALL B");
		Opponent1Cash.setText("10000$");
		Opponent1Bet.setText("10000$");
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
		Opponent1Status.setText("SMALL B");
		Opponent1Cash.setText("10000$");
		Opponent1Bet.setText("10000$");
		Opponent2Status.setText("SMALL B");
		Opponent2Cash.setText("10000$");
		Opponent2Bet.setText("10000$");
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
		Opponent2Status.setText("SMALL B");
		Opponent2Cash.setText("10000$");
		Opponent2Bet.setText("10000$");
		Opponent3Status.setText("SMALL B");
		Opponent3Cash.setText("10000$");
		Opponent3Bet.setText("10000$");
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
		Opponent4Status.setText("SMALL B");
		Opponent4Cash.setText("10000$");
		Opponent4Bet.setText("10000$");
		Opponent3Status.setText("SMALL B");
		Opponent3Cash.setText("10000$");
		Opponent3Bet.setText("10000$");
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
		Opponent4Status.setText("SMALL B");
		Opponent4Cash.setText("10000$");
		Opponent4Bet.setText("10000$");
		Opponent5Status.setText("SMALL B");
		Opponent5Cash.setText("10000$");
		Opponent5Bet.setText("10000$");
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
	PlayerStatus.setText("SMALL B");
	PlayerBet.setText("10000$");
	PlayerCash.setText("10000$");
	//
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

	showEndScreen(false);

	//
	EndWinnerCash.setText("+1000$");
	EndWinnerName.setText("Player 1");
	//
}

void MainWindow::StartGame()
{
	this->show();
	setStatus();
	setCash();
	setButtons();
	setTableCards();
	showButtons();
	setCurrentPlayer();
	if (game_handler->current_player() == 0)
	{
		setButtons();
		showButtons();
		return;
	}
	else
	{
		game_handler->play_turn(Decision(0), 0);
	}
	BigBlind();
}
void MainWindow::PlayGame()
{
	setCurrentPlayer();
	setCash();
	setStatus();
	setButtons();
	setTableCards();
	showButtons();
	showPlayersCards();

	if (game_handler->current_player() == 0) return;

	qDebug() << "Player turn: " << game_handler->current_player();

	//bot delay
	int time = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<unsigned int> dist(1000, 3000);

	time = dist(gen);
	bot_cooldown->start(time);
	qDebug() << "Bot timer started at: " << time << "ms";


	return;
}

void MainWindow::playerMakeDecision(Decision decision, int bet)
{
	game_handler->play_turn(decision, bet);
	PlayGame();
}
void MainWindow::botMakeMove()
{
	game_handler->play_turn(Decision(0), 0);
	PlayGame();
}
void MainWindow::playerMakeSmallBlind(int bet)
{
	game_handler->play_turn(Decision(6), bet);
	BigBlind();
}

void MainWindow::BigBlind()
{
	setCash();
	game_handler->make_big_blind();
	game_handler->start_game();
	setPlayerCards();
	setCurrentPlayer();
	PlayGame();
}

void MainWindow::showButtons()
{
	if (game_handler->player(0)->small_blind() && game_handler->previous_bet() == 0)
	{
		ui->SmallBlindButton->show();
		ui->BetButton->hide();
		ui->CheckButton->hide();
		ui->FoldButton->hide();
		ui->AllInButton->hide();
	}
	else
	{
		ui->SmallBlindButton->hide();
		ui->BetButton->setVisible(game_handler->current_player() == 0);
		ui->CheckButton->setVisible(game_handler->current_player() == 0);
		ui->FoldButton->setVisible(game_handler->current_player() == 0);
		ui->AllInButton->setVisible(game_handler->current_player() == 0);
	}
}
void MainWindow::showEndScreen(bool visible)
{
	EndBackground.setVisible(visible);
	EndWinner.setVisible(visible);
	EndWinnerName.setVisible(visible);
	EndToken.setVisible(visible);
	EndWinnerCash.setVisible(visible);
}
void MainWindow::showPlayersCards()
{
	PlayerCard1.setVisible(!game_handler->player(0)->folded());
	PlayerCard2.setVisible(!game_handler->player(0)->folded());
	Opponent1Card1.setVisible(!game_handler->player(1)->folded());
	Opponent1Card2.setVisible(!game_handler->player(1)->folded());
	if (game_handler->game_info.player_count > 2)
	{
		Opponent2Card1.setVisible(!game_handler->player(2)->folded());
		Opponent2Card2.setVisible(!game_handler->player(2)->folded());
	}
	if (game_handler->game_info.player_count > 3)
	{
		Opponent3Card1.setVisible(!game_handler->player(3)->folded());
		Opponent3Card2.setVisible(!game_handler->player(3)->folded());
	}
	if (game_handler->game_info.player_count > 4)
	{
		Opponent4Card1.setVisible(!game_handler->player(4)->folded());
		Opponent4Card2.setVisible(!game_handler->player(4)->folded());
	}
	if (game_handler->game_info.player_count > 5)
	{
		Opponent5Card1.setVisible(!game_handler->player(5)->folded());
		Opponent5Card2.setVisible(!game_handler->player(5)->folded());
	}
}	

void MainWindow::setPlayerCards()
{
	QPixmap qcard1(game_handler->get_player_hand(0, 0)->get_file_path().c_str());
	QPixmap qcard2(game_handler->get_player_hand(0, 1)->get_file_path().c_str());
	PlayerCard1.setPixmap(qcard1);
	PlayerCard2.setPixmap(qcard2);
}
void MainWindow::setTableCards()
{
	if (game_handler->phase_to_int() == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			TableCards[i]->hide();
		}
	}
	else if (game_handler->phase_to_int() == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			TableCards[i]->setPixmap(QPixmap(game_handler->get_table_card(i)->get_file_path().c_str()));
			TableCards[i]->show();
		}
	}
	else if (game_handler->phase_to_int() == 2)
	{
		TableCards[3]->setPixmap(QPixmap(game_handler->get_table_card(3)->get_file_path().c_str()));
		TableCards[3]->show();
	}
	else if (game_handler->phase_to_int() == 3)
	{
		TableCards[4]->setPixmap(QPixmap(game_handler->get_table_card(4)->get_file_path().c_str()));
		TableCards[4]->show();
	}
}
void MainWindow::setCash()
{
	PlayerCash.setText(game_handler->cash_to_QString(game_handler->player(0)->money()));
	PlayerBet.setText(game_handler->cash_to_QString(game_handler->player(0)->bet()));
	Opponent1Cash.setText(game_handler->cash_to_QString(game_handler->player(1)->money()));
	Opponent1Bet.setText(game_handler->cash_to_QString(game_handler->player(1)->bet()));
	if (game_handler->player_count() > 2)
	{
		Opponent2Cash.setText(game_handler->cash_to_QString(game_handler->player(2)->money()));
		Opponent2Bet.setText(game_handler->cash_to_QString(game_handler->player(2)->bet()));
	}
	if (game_handler->player_count() > 3)
	{
		Opponent3Cash.setText(game_handler->cash_to_QString(game_handler->player(3)->money()));
		Opponent3Bet.setText(game_handler->cash_to_QString(game_handler->player(3)->bet()));
	}
	if (game_handler->player_count() > 4)
	{
		Opponent4Cash.setText(game_handler->cash_to_QString(game_handler->player(4)->money()));
		Opponent4Bet.setText(game_handler->cash_to_QString(game_handler->player(4)->bet()));
	}
	if (game_handler->player_count() > 5)
	{
		Opponent5Cash.setText(game_handler->cash_to_QString(game_handler->player(5)->money()));
		Opponent5Bet.setText(game_handler->cash_to_QString(game_handler->player(5)->bet()));
		//qDebug() << "bet set: " << Opponent5Bet.text();
	}
	ui->Pot->setText(game_handler->cash_to_QString(game_handler->pot()));
}
void MainWindow::setStatus()
{
	PlayerStatus.setText(game_handler->status_to_string(0).c_str());
	Opponent1Status.setText(game_handler->status_to_string(1).c_str());
	if (game_handler->game_info.player_count > 2)
	{
		Opponent2Status.setText(game_handler->status_to_string(2).c_str());
	}
	if (game_handler->player_count() > 3)
	{
		Opponent3Status.setText(game_handler->status_to_string(3).c_str());
	}
	if (game_handler->player_count() > 4)
	{
		Opponent4Status.setText(game_handler->status_to_string(4).c_str());
	}
	if (game_handler->player_count() > 5)
	{
		Opponent5Status.setText(game_handler->status_to_string(5).c_str());
	}
}
void MainWindow::setCurrentPlayer()
{
	ui->CurrentPlayerName->setText(game_handler->name_to_string(game_handler->current_player()).c_str());
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
	if (game_handler->previous_bet() == 0)
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
	EndWinnerCash.setText(game_handler->cash_to_QString(game_handler->pot()));
}
void MainWindow::reverseCards(bool front)
{
	if (front)
	{
		QPixmap pcard1(game_handler->get_player_hand(0, 0)->get_file_path().c_str());
		QPixmap pcard2(game_handler->get_player_hand(0, 1)->get_file_path().c_str());
		PlayerCard1.setPixmap(pcard1);
		PlayerCard2.setPixmap(pcard2);
		QPixmap o1card1(game_handler->get_player_hand(1, 0)->get_file_path().c_str());
		QPixmap o1card2(game_handler->get_player_hand(1, 1)->get_file_path().c_str());
		Opponent1Card1.setPixmap(o1card1);
		Opponent1Card2.setPixmap(o1card2);
		if (game_handler->game_info.player_count > 2)
		{
			QPixmap o2card1(game_handler->get_player_hand(2, 0)->get_file_path().c_str());
			QPixmap o2card2(game_handler->get_player_hand(2, 1)->get_file_path().c_str());
			Opponent2Card1.setPixmap(o2card1);
			Opponent2Card2.setPixmap(o2card2);
		}
		if (game_handler->game_info.player_count > 3)
		{
			QPixmap o3card1(game_handler->get_player_hand(3, 0)->get_file_path().c_str());
			QPixmap o3card2(game_handler->get_player_hand(3, 1)->get_file_path().c_str());
			Opponent3Card1.setPixmap(o3card1);
			Opponent3Card2.setPixmap(o3card2);
		}
		if (game_handler->game_info.player_count > 4)
		{
			QPixmap o4card1(game_handler->get_player_hand(4, 0)->get_file_path().c_str());
			QPixmap o4card2(game_handler->get_player_hand(4, 1)->get_file_path().c_str());
			Opponent4Card1.setPixmap(o4card1);
			Opponent4Card2.setPixmap(o4card2);
		}
		if (game_handler->game_info.player_count > 5)
		{
			QPixmap o5card1(game_handler->get_player_hand(5, 0)->get_file_path().c_str());
			QPixmap o5card2(game_handler->get_player_hand(5, 1)->get_file_path().c_str());
			Opponent5Card1.setPixmap(o5card1);
			Opponent5Card2.setPixmap(o5card2);
		}
	}
	else
	{
		QPixmap cardr(":/resources/Deck/card_back.png");
		PlayerCard1.setPixmap(cardr);
		PlayerCard2.setPixmap(cardr);
		Opponent1Card1.setPixmap(cardr);
		Opponent1Card2.setPixmap(cardr);
		if (game_handler->game_info.player_count > 2)
		{
			Opponent2Card1.setPixmap(cardr);
			Opponent2Card2.setPixmap(cardr);
		}
		if (game_handler->game_info.player_count > 3)
		{
			Opponent3Card1.setPixmap(cardr);
			Opponent3Card2.setPixmap(cardr);
		}
		if (game_handler->game_info.player_count > 4)
		{
			Opponent4Card1.setPixmap(cardr);
			Opponent4Card2.setPixmap(cardr);
		}
		if (game_handler->game_info.player_count > 5)
		{
			Opponent5Card1.setPixmap(cardr);
			Opponent5Card2.setPixmap(cardr);
		}
	}
}


void MainWindow::check()
{
	if (game_handler->pot() == 0)
	{
		emit decisionMade(Decision(2), 0);
	}
	else
	{
		emit decisionMade(Decision(4), 0);
	}
}
void MainWindow::bet()
{
	ui->lineEdit->show();
	ui->ConfirmButton->show();
}
void MainWindow::fold()
{
	emit decisionMade(Decision(3), 0);
}
void MainWindow::all_in()
{
	emit decisionMade(Decision(5), 0);
}
void MainWindow::bet_confirmed()
{
	// int < player money
	try {
		bool ok = true;
		if (ui->lineEdit->text().toInt(&ok) >= game_handler->player(0)->money())
		{
			throw 1;
		}
		if (!ok)
		{
			throw 2;
		}
	}
	catch (int x) {
		QMessageBox::warning(this, "Input Error", "Too much!");
		ui->lineEdit->clear();
		return;
	}

	int a = ui->lineEdit->text().toInt();
	ui->lineEdit->clear();
	ui->lineEdit->hide();
	ui->ConfirmButton->hide();
	if (game_handler->pot() == 0)
	{
		emit decisionMade(Decision(6), a);
	}
	else
	{
		emit decisionMade(Decision(1), a);
	}
}

void MainWindow::small_blind()
{
	ui->lineEdit->show();
	ui->ConfirmSmallBlindButton->show();
}
void MainWindow::small_blind_confirmed()
{
	// 0.02*initial_money < int < 0.1 *initial_money
	try {
		bool ok;
		if (ui->lineEdit->text().toInt(&ok) < 0.02*game_handler->initial_money() ||
			ui->lineEdit->text().toInt(&ok) > 0.1 * game_handler->initial_money())
		{
			throw 1;
		}
		if (!ok)
		{
			throw 2;
		}
	}
	catch (int x) {
		QMessageBox::warning(this, "Input Error", "It must be between 2% and 10% of initial money");
		ui->lineEdit->clear();
		return;
	}
	int a = ui->lineEdit->text().toInt();
	ui->lineEdit->clear();
	ui->lineEdit->hide();
	ui->ConfirmSmallBlindButton->hide();
	ui->SmallBlindButton->hide();
	emit smallBlindMade(a);
}

void MainWindow::bot_timer_ended()
{
	emit botMove();
}



void MainWindow::InputNames(std::vector<std::string> names)
{
	//TODO
}
