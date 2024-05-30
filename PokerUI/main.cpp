#include "MainWindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Main_Window;
    //
    MainWindow* ptr = &Main_Window;
    Main_Window.createWidgets(ptr, 1);
    //QLabel card1;
    //card1.setParent(ptr);
    //card1.setScaledContents(true);
    //card1.setFixedSize(107, 150);
    //card1.move(120, 320);
    ////
    //QPixmap pcard1(":/resources/Deck/clubs_ace.png");
    //card1.setPixmap(pcard1);
    ////
    //Main_Window.showPlayerCards();

    Main_Window.show();

    return a.exec();
}
