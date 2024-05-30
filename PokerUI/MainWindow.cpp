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

void MainWindow::createWidgets(MainWindow* ptr, const short opponents)
{
	createPlayerCards(ptr);
    createTableCards(ptr);
    //createOpponentCards(opponents);
    //createButtons();
}

void MainWindow::createPlayerCards(MainWindow* ptr)
{
	PlayerCard1.setParent(ptr);
	PlayerCard1.setScaledContents(true);
	PlayerCard1.setFixedSize(107, 150);
	PlayerCard1.move(320, 520);
	//
	QPixmap pcard1(":/resources/Deck/clubs_ace.png");
	PlayerCard1.setPixmap(pcard1);
	//

	PlayerCard2.setParent(ptr);
	PlayerCard2.setScaledContents(true);
	PlayerCard2.setFixedSize(107, 150);
	PlayerCard2.move(440, 520);
	//
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
	//
	QPixmap tcard1(":/resources/Deck/clubs_three.png");
	TableCard1.setPixmap(tcard1);
	//
	TableCard2.setParent(ptr);
	TableCard2.setScaledContents(true);
	TableCard2.setFixedSize(107, 150);
	TableCard2.move(460, 225);
	//
	QPixmap tcard2(":/resources/Deck/clubs_four.png");
	TableCard2.setPixmap(tcard2);
	//
	TableCard3.setParent(ptr);
	TableCard3.setScaledContents(true);
	TableCard3.setFixedSize(107, 150);
	TableCard3.move(580, 225);
	//
	QPixmap tcard3(":/resources/Deck/clubs_five.png");
	TableCard3.setPixmap(tcard3);
	//
	TableCardBack.setParent(ptr);
	TableCardBack.setScaledContents(true);
	TableCardBack.setFixedSize(107, 150);
	TableCardBack.move(700, 225);
	//
	QPixmap tcardback(":/resources/Deck/card_back.png");
	TableCardBack.setPixmap(tcardback);
	//
}

void MainWindow::showPlayerCards()
{
	PlayerCard1.show();
	PlayerCard2.show();
}
