#pragma once
#include <QLabel>
#include <MainWindow.h>
#include <QFont>
#include <QPixmap>
#include <QTransform>

class UIPlayer
{
public:
	UIPlayer(MainWindow* ptr);
	~UIPlayer();

	void set_name(std::string name);
	void set_cash(unsigned int cash);
	void set_bet(unsigned int bet);
	void set_cards(std::string path1, std::string path2);
	void set_status(std::string status);
	void set_cards_visibility(bool visibility);
	void move_to_position(int pos);
private:
	QLabel* Name;
	QLabel* Cash;
	QLabel* Bet;
	QLabel* Cards[2];
	QLabel* Status;
	QLabel* SelfToken;
	QLabel* TableToken;

	friend class MainWindow;
};