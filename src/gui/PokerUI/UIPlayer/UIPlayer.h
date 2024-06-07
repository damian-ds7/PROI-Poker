#pragma once
#include <QLabel>
#include <MainWindow.h>
#include <QFont>
#include <QPixmap>

class UIPlayer
{
public:
	UIPlayer(MainWindow* ptr);
	~UIPlayer();
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