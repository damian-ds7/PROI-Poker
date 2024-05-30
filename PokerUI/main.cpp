#include "MainWindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Main_Window;
    //
    MainWindow* ptr = &Main_Window;
    Main_Window.createWidgets(ptr, 1);

    Main_Window.show();

    return a.exec();
}
