#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include <QFile>
#include <utility>

MenuWindow::MenuWindow(std::unique_ptr<GameHandler> Igame, MainWindow* main_window, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow), game_handler(std::move(Igame)), main_window(main_window)
{
    ui->setupUi(this);

    this->setWindowTitle("Poker Texas Holdem");
    this->setFixedSize(800, 600);
    QIcon icon(":/resources/app.ico");
    this->setWindowIcon(icon);

    // Load the background image
    QFile file(":/resources/background.jpg");
    if (!file.exists()) {
        qDebug() << "Unable to set stylesheet, file not found";
    } else {
        this->setStyleSheet("QMainWindow { background-image: url(:/resources/background.jpg); background-position: center; background-repeat: no-repeat; }");
    }

    connect(ui->startButton, &QPushButton::clicked, this, &MenuWindow::startGame);
    connect(ui->playerSlider, &QSlider::valueChanged, this, &MenuWindow::updatePlayerCount);
    connect(ui->moneySlider, &QSlider::valueChanged, this, &MenuWindow::updateStartMoney);

    // Set the initial value
    updatePlayerCount(ui->playerSlider->value());
    updateStartMoney(ui->moneySlider->value());
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::startGame() {
    QString playerName = ui->nameField->text();
    int numberOfPlayers = ui->playerSlider->value();
    int initialMoney = ui->moneySlider->value();

    if (playerName.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Player name cannot be empty.");
        return;
    }

    // Create the GameInfo object
    GameInfo gameInfo(playerName.toStdString(), numberOfPlayers, initialMoney);
    game_handler->initialize_game(gameInfo);
    main_window->game_handler = std::move(game_handler);
    // Emit the signal with the game info
    emit gameInfoReady(gameInfo);

    // Close the window
    this->hide();
}

void MenuWindow::updatePlayerCount(int count){
    ui->playerCountLabel->setText(QString::number(count));
}

void MenuWindow::updateStartMoney(int count){
    ui->startMoneyLabel->setText(QString::number(count));
}
