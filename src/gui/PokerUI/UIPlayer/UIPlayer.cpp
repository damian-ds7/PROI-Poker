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


	QFont NameFont("Arial", 14, QFont::Bold);
	QFont CashFont("Arial", 13, QFont::Bold);
	QFont StatusFont("Arial", 18, QFont::Bold);
	QPixmap token(":/resources/token.png");
	QPixmap card(":/resources/Deck/card_back.png");

	Name->setFont(NameFont);
	Cash->setFont(CashFont);
	Bet->setFont(CashFont);
	Status->setFont(StatusFont);

	SelfToken->setFixedSize(20, 20);
	TableToken->setFixedSize(20, 20);
	Cards[0]->setFixedSize(107, 150);
	Cards[1]->setFixedSize(107, 150);

	SelfToken->setScaledContents(true);
	TableToken->setScaledContents(true);
	Cards[0]->setScaledContents(true);
	Cards[1]->setScaledContents(true);

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

void UIPlayer::set_name(std::string name) {
	Name->setText(QString::fromStdString(name));
}

void UIPlayer::set_cash(unsigned int cash) {
	Cash->setText(QString::fromStdString(std::to_string(cash) + "$"));
}

void UIPlayer::set_bet(unsigned int bet) {
	Bet->setText(QString::fromStdString(std::to_string(bet) + "$"));
}

void UIPlayer::set_status(std::string status) {
	Status->setText(QString::fromStdString(status));
}

void UIPlayer::set_cards(std::string path1, std::string path2) {
	Cards[0]->setPixmap(QPixmap(QString::fromStdString(path1)));
	Cards[1]->setPixmap(QPixmap(QString::fromStdString(path2)));
}

void UIPlayer::set_cards_visibility(bool visibility) {
	Cards[0]->setVisible(visibility);
	Cards[1]->setVisible(visibility);
}