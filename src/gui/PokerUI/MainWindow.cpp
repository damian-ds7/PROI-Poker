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
	connect(ui->NextRoundButton, &QPushButton::clicked, this, &MainWindow::next_round);
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
    createTableCards(ptr);
	createPlayers(ptr);
	movePlayerLabels();
	moveOpponentLabels();
	initPlayersInfo();

	showEndScreen(false);
	ui->lineEdit->hide();
	ui->ConfirmButton->hide();
	ui->ConfirmSmallBlindButton->hide();
}

void MainWindow::createPlayers(MainWindow* ptr)
{
	uiplayers.push_back(std::make_unique<UIPlayer>(ptr));
	uiplayers[0]->set_name(game_handler->player_name());
	uiplayers[0]->set_cash(game_handler->initial_money());

	for (unsigned int i = 1; i < game_handler->player_count(); ++i) {
		uiplayers.push_back(std::make_unique<UIPlayer>(ptr));
		uiplayers[i]->set_name(game_handler->name_to_string(i));
		uiplayers[i]->set_cash(game_handler->initial_money());
	}
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
void MainWindow::movePlayerLabels()
{
	QFont NameFont("Arial", 20, QFont::Bold);
	QFont CashFont("Arial", 17, QFont::Bold);
	QFont StatusFont("Arial", 26, QFont::Bold);

	uiplayers[0]->Cards[0]->move(440, 520);
	uiplayers[0]->Cards[1]->move(560, 520);
	uiplayers[0]->Cards[0]->setFixedSize(107, 150);
	uiplayers[0]->Cards[1]->setFixedSize(107, 150);

	uiplayers[0]->Name->setFont(NameFont);
	uiplayers[0]->Name->move(280, 520);
	uiplayers[0]->Cash->setFont(CashFont);
	uiplayers[0]->Cash->move(315, 555);
	uiplayers[0]->Status->setFont(StatusFont);
	uiplayers[0]->Status->move(280, 600);
	uiplayers[0]->Bet->setFont(CashFont);
	uiplayers[0]->Bet->move(495, 415);

	uiplayers[0]->SelfToken->setFixedSize(30, 30);
	uiplayers[0]->SelfToken->move(280, 554);

	uiplayers[0]->TableToken->setFixedSize(30, 30);
	uiplayers[0]->TableToken->move(460, 415);
}
void MainWindow::moveOpponentLabels()
{

	if (game_handler->player_count() == 2)
	{
		uiplayers[1]->move_to_position(3);
	}
	if (game_handler->player_count() == 3)
	{
		uiplayers[1]->move_to_position(2);
		uiplayers[2]->move_to_position(4);
	}
	if (game_handler->player_count() == 4)
	{
		uiplayers[1]->move_to_position(1);
		uiplayers[2]->move_to_position(3);
		uiplayers[3]->move_to_position(5);
	}
	if (game_handler->player_count() == 5) 
	{
		uiplayers[1]->move_to_position(1);
		uiplayers[2]->move_to_position(2);
		uiplayers[3]->move_to_position(4);
		uiplayers[4]->move_to_position(5);
	}
	if (game_handler->player_count() == 6)
	{
		uiplayers[1]->move_to_position(1);
		uiplayers[2]->move_to_position(2);
		uiplayers[3]->move_to_position(3);
		uiplayers[4]->move_to_position(4);
		uiplayers[5]->move_to_position(5);
	}
}
void MainWindow::initPlayersInfo()
{
	for (int i = 0; i < game_handler->player_count(); i++)
	{
		uiplayers[i]->set_name(game_handler->name_to_string(i));
		uiplayers[i]->set_cash(game_handler->initial_money());
	}
}

void MainWindow::StartGame()
{
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
	ui->EndBackground->setVisible(visible);
	ui->EndWinnerDescription->setVisible(visible);
	ui->EndWinnerName->setVisible(visible);
	ui->EndToken->setVisible(visible);
	ui->EndWinnerCash->setVisible(visible);
	ui->NextRoundButton->setVisible(visible);
}
void MainWindow::showPlayersCards()
{
	for (int i = 0; i < game_handler->player_count(); i++)
	{
		uiplayers[i]->set_cards_visibility(!game_handler->player(i)->folded());
	}
}	

void MainWindow::setPlayerCards()
{
	uiplayers[0]->set_cards(game_handler->get_player_hand(0, 0)->get_file_path(), game_handler->get_player_hand(0, 1)->get_file_path());
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
	for (unsigned int i = 0; i < game_handler->player_count(); ++i)
	{
		uiplayers[i]->set_cash(game_handler->player(i)->money());
		uiplayers[i]->set_bet(game_handler->player(i)->bet());
	}
	ui->Pot->setText(game_handler->cash_to_QString(game_handler->pot()));
}
void MainWindow::setStatus()
{
	for (unsigned int i = 0; i < game_handler->player_count(); ++i)
	{
		uiplayers[i]->set_status(game_handler->status_to_string(i));
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

void MainWindow::setEndScreen()
{
	//set winner name
	ui->EndWinnerCash->setText(game_handler->cash_to_QString(game_handler->pot()));
}
void MainWindow::reverseCards(bool front)
{
	if (front)
	{
		for (int i = 0; i < game_handler->player_count(); i++)
		{
			uiplayers[i]->set_cards(game_handler->get_player_hand(i, 0)->get_file_path(), game_handler->get_player_hand(i, 1)->get_file_path());
		}
	}
	else
	{
		for (int i = 0; i < game_handler->player_count(); i++)
		{
			uiplayers[i]->set_cards(":/resources/Deck/card_back.png", ":/resources/Deck/card_back.png");
		}
	}
}


void MainWindow::check()
{
	if (game_handler->can_check())
	{
		emit decisionMade(Decision(2), 0);
	}
	else
	{
		emit decisionMade(Decision(4), game_handler->previous_bet());
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

void MainWindow::next_round()
{
	emit nextRound();
}

void MainWindow::bot_timer_ended()
{
	emit botMove();
}



void MainWindow::InputNames(std::vector<std::string> names)
{
	//TODO
}
