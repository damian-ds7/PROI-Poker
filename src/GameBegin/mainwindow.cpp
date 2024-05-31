#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent, std::shared_ptr<Game> Igame)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), game(std::move(Igame))
{
    ui->setupUi(this);

    // Load the background image
    QFile file(":/resources/background.jpg");
    if (!file.exists()) {
        qDebug() << "Unable to set stylesheet, file not found";
    } else {
        this->setStyleSheet("QMainWindow { background-image: url(:/resources/background.jpg); background-position: center; background-repeat: no-repeat; }");
    }

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->playerSlider, &QSlider::valueChanged, this, &MainWindow::updatePlayerCount);
    connect(ui->moneySlider, &QSlider::valueChanged, this, &MainWindow::updateStartMoney);

    // Set the initial value
    updatePlayerCount(ui->playerSlider->value());
    updateStartMoney(ui->moneySlider->value());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame() {
    QString playerName = ui->nameField->text();
    int numberOfPlayers = ui->playerSlider->value();
    int initialMoney = ui->moneySlider->value();

    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Player name cannot be empty.");
        return;
    }

    // Create the GameInfo object
    GameInfo gameInfo(playerName.toStdString(), numberOfPlayers, initialMoney);
    game->setGameInfo(gameInfo);

    // Emit the signal with the game info
    emit gameInfoReady(gameInfo);

    // Close the window
    this->close();
}

void MainWindow::updatePlayerCount(int count){
    ui->playerCountLabel->setText(QString::number(count));
}

void MainWindow::updateStartMoney(int count){
    ui->startMoneyLabel->setText(QString::number(count));
}
