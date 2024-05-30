#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
	, PlayerCard1(new QLabel(this))
	, PlayerCard2(new QLabel(this))
{
    ui->setupUi(this);
    //label.hide();
    //label.show();
	//label.raise();

    
}

MainWindow::~MainWindow()
{
    delete ui;
	//delete PlayerCard1;
	//delete PlayerCard2;
}

void MainWindow::createWidgets(MainWindow* ptr, const short opponents)
{
	createPlayerCards(ptr);
    //createTableCards();
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
	PlayerCard1.raise();

	PlayerCard2.setParent(ptr);
	PlayerCard2.setScaledContents(true);
	PlayerCard2.setFixedSize(107, 150);
	PlayerCard2.move(440, 520);
	//
	QPixmap pcard2(":/resources/Deck/clubs_two.png");
	PlayerCard2.setPixmap(pcard2);
	//
	PlayerCard2.raise();
}

void MainWindow::showPlayerCards()
{
	PlayerCard1.show();
	PlayerCard2.show();
}
