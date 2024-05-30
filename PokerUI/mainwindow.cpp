#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QLabel* label = new QLabel();
    QPixmap background(":/resources/Deck/clubs_ace.png");
    label->setPixmap(background);
    label->setScaledContents(true);
    //label->show();

    ui->verticalLayout->addWidget(label);

    label->raise();


    //QPixmap background(":/background/background_table.png"); // <- path to image file
    //background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    //QPalette palette; 
    //palette.setBrush(QPalette::Window, background);
    //this->setPalette(palette);
    //ui->label_2->setPixmap(pm);
    //ui->label_2->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
