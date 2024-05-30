#ifndef WIDGET_H
#define WIDGET_H

#include <QPixmap>
#include <QPalette>
#include <QBrush>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    
    void showPlayerCards();
    void createWidgets(MainWindow* ptr, const short opponents);

private:
    void createPlayerCards(MainWindow* ptr);
    void createTableCards(MainWindow* ptr);
    //void createButtons();
    //void createOpponentCards(const short opponents);



    QLabel PlayerCard1;
    QLabel PlayerCard2;
    QLabel TableCard1;
    QLabel TableCard2;
    QLabel TableCard3;
    QLabel TableCardBack;
    Ui::Widget* ui;
};
#endif // WIDGET_H

