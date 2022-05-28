#include "mainwindow.h"
#include "mystruct.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/image/icon.png"));
    MainWindow w;
    w.show();
    return a.exec();
}
