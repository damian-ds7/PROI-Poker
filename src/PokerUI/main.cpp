#include "MainWindow.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow Main_Window(nullptr, 5);
    MainWindow* ptr = &Main_Window;
    //Main_Window.createWidgets(ptr, 1);
    //Main_Window.createWidgets(ptr, 2);
    //Main_Window.createWidgets(ptr, 3);
    //Main_Window.createWidgets(ptr, 4);
    Main_Window.createWidgets(ptr);

    Main_Window.show();

    return a.exec();
}
