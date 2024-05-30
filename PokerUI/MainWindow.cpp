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
    createOpponentCards(ptr, opponents);
    //createButtons();
}

void MainWindow::createPlayerCards(MainWindow* ptr)
{
	PlayerCard1.setParent(ptr);
	PlayerCard1.setScaledContents(true);
	PlayerCard1.setFixedSize(107, 150);
	PlayerCard1.move(320, 520);

	PlayerCard2.setParent(ptr);
	PlayerCard2.setScaledContents(true);
	PlayerCard2.setFixedSize(107, 150);
	PlayerCard2.move(440, 520);


	//
	QPixmap pcard1(":/resources/Deck/clubs_ace.png");
	PlayerCard1.setPixmap(pcard1);
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

	TableCard2.setParent(ptr);
	TableCard2.setScaledContents(true);
	TableCard2.setFixedSize(107, 150);
	TableCard2.move(460, 225);

	TableCard3.setParent(ptr);
	TableCard3.setScaledContents(true);
	TableCard3.setFixedSize(107, 150);
	TableCard3.move(580, 225);

	TableCardBack.setParent(ptr);
	TableCardBack.setScaledContents(true);
	TableCardBack.setFixedSize(107, 150);
	TableCardBack.move(700, 225);
	QPixmap tcardback(":/resources/Deck/card_back.png");
	TableCardBack.setPixmap(tcardback);



	//
	QPixmap tcard1(":/resources/Deck/clubs_three.png");
	TableCard1.setPixmap(tcard1);
	QPixmap tcard2(":/resources/Deck/clubs_four.png");
	TableCard2.setPixmap(tcard2);
	QPixmap tcard3(":/resources/Deck/clubs_five.png");
	TableCard3.setPixmap(tcard3);
	//
}

void MainWindow::createOpponentCards(MainWindow* ptr, const short opponents)
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
		Opponent1Card1.move(520, -80);

		Opponent1Card2.setParent(ptr);
		Opponent1Card2.setScaledContents(true);
		Opponent1Card2.setFixedSize(80, 110);
		Opponent1Card2.move(550, -80);


		Opponent1Card1.setPixmap(ocard);
		Opponent1Card2.setPixmap(ocard);
	}
	if (opponents == 2 || opponents == 4)
	{
		//Opponent 1
		Opponent1Card1.setParent(ptr);
		Opponent1Card1.setScaledContents(true);
		Opponent1Card1.setFixedSize(80, 110);
		Opponent1Card1.move(200, -80);

		Opponent1Card2.setParent(ptr);
		Opponent1Card2.setScaledContents(true);
		Opponent1Card2.setFixedSize(80, 110);
		Opponent1Card2.move(230, -80);

		Opponent1Card1.setPixmap(ocard);
		Opponent1Card2.setPixmap(ocard);
		

		//Opponent 2
		Opponent2Card1.setParent(ptr);
		Opponent2Card1.setScaledContents(true);
		Opponent2Card1.setFixedSize(80, 110);
		Opponent2Card1.move(810, -80);

		Opponent2Card2.setParent(ptr);
		Opponent2Card2.setScaledContents(true);
		Opponent2Card2.setFixedSize(80, 110);
		Opponent2Card2.move(840, -80);

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
		Opponent3Card1.move(1100, 200);

		Opponent3Card2.setParent(ptr);
		Opponent3Card2.setScaledContents(true);
		Opponent3Card2.setFixedSize(80, 110);
		Opponent3Card2.move(1100, 230);

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
		Opponent4Card1.move(1100, 200);

		Opponent4Card2.setParent(ptr);
		Opponent4Card2.setScaledContents(true);
		Opponent4Card2.setFixedSize(80, 110);
		Opponent4Card2.move(1100, 230);

		Opponent4Card1.setPixmap(ocardr);
		Opponent4Card2.setPixmap(ocardr);
	}

	if (opponents == 5)
	{
		//Opponent 4
		Opponent4Card1.setParent(ptr);
		Opponent4Card1.setScaledContents(true);
		Opponent4Card1.setFixedSize(80, 110);
		Opponent4Card1.move(200, -80);

		Opponent4Card2.setParent(ptr);
		Opponent4Card2.setScaledContents(true);
		Opponent4Card2.setFixedSize(80, 110);
		Opponent4Card2.move(230, -80);

		Opponent4Card1.setPixmap(ocard);
		Opponent4Card2.setPixmap(ocard);


		//Opponent 5
		Opponent5Card1.setParent(ptr);
		Opponent5Card1.setScaledContents(true);
		Opponent5Card1.setFixedSize(80, 110);
		Opponent5Card1.move(810, -80);

		Opponent5Card2.setParent(ptr);
		Opponent5Card2.setScaledContents(true);
		Opponent5Card2.setFixedSize(80, 110);
		Opponent5Card2.move(840, -80);

		Opponent5Card1.setPixmap(ocard);
		Opponent5Card2.setPixmap(ocard);
	}

}

void MainWindow::showPlayerCards()
{
	PlayerCard1.show();
	PlayerCard2.show();
}
