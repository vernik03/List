#include "mainwindow.h"

#include <QApplication>

bool show_fav=0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
