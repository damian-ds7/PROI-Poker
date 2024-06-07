#include <UIPlayer/UIPlayer.h>

UIPlayer::UIPlayer(MainWindow* ptr) {
	Name = new QLabel(ptr);
	Cash = new QLabel(ptr);
	Bet = new QLabel(ptr);
	Cards[0] = new QLabel(ptr);
	Cards[1] = new QLabel(ptr);
	Status = new QLabel(ptr);
	SelfToken = new QLabel(ptr);
	TableToken = new QLabel(ptr);


	QFont NameFont("Arial", 20, QFont::Bold);
	QFont CashFont("Arial", 17, QFont::Bold);
	QFont StatusFont("Arial", 26, QFont::Bold);
	QPixmap token(":/resources/token.png");
	QPixmap card(":/resources/Deck/card_back.png");

	Name->setFont(NameFont);
	Cash->setFont(CashFont);
	Bet->setFont(CashFont);
	Status->setFont(StatusFont);

	SelfToken->setPixmap(token);
	TableToken->setPixmap(token);

	Cards[0]->setPixmap(card);
	Cards[1]->setPixmap(card);

	Name->setStyleSheet("background: transparent;");
	Cash->setStyleSheet("background: transparent;");
	Bet->setStyleSheet("background: transparent;");
	Status->setStyleSheet("background: transparent;");
	SelfToken->setStyleSheet("background: transparent;");
	TableToken->setStyleSheet("background: transparent;");
	Cards[0]->setStyleSheet("background: transparent;");
	Cards[1]->setStyleSheet("background: transparent;");

	SelfToken->setFixedSize(30, 30);
	TableToken->setFixedSize(30, 30);
	Cards[0]->setFixedSize(107, 150);
	Cards[1]->setFixedSize(107, 150);

	SelfToken->setScaledContents(true);
	TableToken->setScaledContents(true);
	Cards[0]->setScaledContents(true);
	Cards[1]->setScaledContents(true);

	Name->setText("Long Initial Name");
	Cash->setText("100000$");
	Bet->setText("100000$");
	Status->setText("SMALL B");
}

UIPlayer::~UIPlayer() {
	delete Name;
	delete Cash;
	delete Bet;
	delete Cards[0];
	delete Cards[1];
	delete Status;
	delete SelfToken;
	delete TableToken;
}