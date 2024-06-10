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
	Cards[0]->setFixedSize(80, 110);
	Cards[1]->setFixedSize(80, 110);

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
    Name->adjustSize();
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

void UIPlayer::move_to_position(int pos)
{
	QTransform transform;
	transform.rotate(90);
	QPixmap ocardr = QPixmap(":/resources/Deck/card_back.png").transformed(transform);

	switch (pos)
	{
	case 1:
		Cards[0]->move(-50, 200);
		Cards[1]->move(-50, 230);
		Cards[0]->setPixmap(ocardr);
		Cards[1]->setPixmap(ocardr);
		Name->move(5, 110);
		Cash->move(30, 135);
		Status->move(5, 165);
		Bet->move(205, 285);
		SelfToken->move(5, 134);
		TableToken->move(180, 284);
		break;
	case 2:
		Cards[0]->move(300, -80);
		Cards[1]->move(330, -80);
		Name->move(430, 5);
		Cash->move(455, 30);
		Status->move(430, 60);
		Bet->move(335, 150);
		SelfToken->move(430, 29);
		TableToken->move(310, 149);
		break;
	case 3:
		Cards[0]->move(670, -80);
		Cards[1]->move(700, -80);
		Name->move(800, 5);
		Cash->move(825, 30);
		Status->move(800, 60);
		Bet->move(735, 150);
		SelfToken->move(800, 29);
		TableToken->move(710, 149);
		break;
	case 4:
		Cards[0]->move(1010, -80);
		Cards[1]->move(1040, -80);
		Name->move(1140, 5);
		Cash->move(1165, 30);
		Status->move(1140, 60);
		Bet->move(1085, 150);
		SelfToken->move(1140, 29);
		TableToken->move(1060, 149);
		break;
	case 5:
		Cards[0]->move(1400, 200);
		Cards[1]->move(1400, 230);
		Cards[0]->setPixmap(ocardr);
		Cards[1]->setPixmap(ocardr);
		Name->move(1320, 110);
		Cash->move(1345, 135);
		Status->move(1320, 165);
		Bet->move(1225, 285);
		SelfToken->move(1320, 134);
		TableToken->move(1205, 284);
		break;
	}
}