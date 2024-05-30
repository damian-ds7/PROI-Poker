#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*MainWindow w;
    w.show();

    QLabel label(&w);
    QPixmap background(":/resources/Deck/clubs_ace.png");
    label.setPixmap(background);
    label.setScaledContents(true);
    label.raise();*/
    Widget Main_Window;
    QLabel label(&Main_Window);
    QPixmap background(":/resources/Deck/clubs_ace.png");
    label.setPixmap(background);
    label.setScaledContents(true);
    label.setBaseSize(background.size());

    //QPushButton Bu_Quit("Quit", &Main_Window);

    //QObject::connect(&Bu_Quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    Main_Window.show();
    return a.exec();
}
