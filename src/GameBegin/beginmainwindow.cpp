#include "beginmainwindow.h"
#include "ui_beginmainwindow.h"
#include <QMessageBox>
#include <QFile>

BeginMainWindow::BeginMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the background image
    QFile file(":/resources/background.jpg");
    if (!file.exists()) {
        qDebug() << "Unable to set stylesheet, file not found";
    } else {
        this->setStyleSheet("QMainWindow { background-image: url(:/resources/background.jpg); background-position: center; background-repeat: no-repeat; }");
    }

    connect(ui->startButton, &QPushButton::clicked, this, &BeginMainWindow::startGame);
    connect(ui->playerSlider, &QSlider::valueChanged, this, &BeginMainWindow::updatePlayerCount);
    connect(ui->moneySlider, &QSlider::valueChanged, this, &BeginMainWindow::updateStartMoney);

    // Set the initial value
    updatePlayerCount(ui->playerSlider->value());
    updateStartMoney(ui->moneySlider->value());
}

BeginMainWindow::~BeginMainWindow()
{
    delete ui;
}

void BeginMainWindow::startGame() {
    QString playerName = ui->nameField->text();
    int numberOfPlayers = ui->playerSlider->value();
    int initialMoney = ui->moneySlider->value();

    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Player name cannot be empty.");
        return;
    }

    // Create the GameInfo object
    GameInfo gameInfo(playerName.toStdString(), numberOfPlayers, initialMoney);

    // Emit the signal with the game info
    emit gameInfoReady(gameInfo);

    // Close the window
    this->close();
}

void BeginMainWindow::updatePlayerCount(int count){
    ui->playerCountLabel->setText(QString::number(count));
}

void BeginMainWindow::updateStartMoney(int count){
    ui->startMoneyLabel->setText(QString::number(count));
}
