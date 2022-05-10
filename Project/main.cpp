#include "mainwindow.h"
#include "mystruct.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/image/icon.png"));
    /* 引入自定义结构体 */
    qRegisterMetaType<arcell>("arcell");
    qRegisterMetaType<vexsinfo>("vexsinfo");
    qRegisterMetaType<mgraph>("mgraph");

    MainWindow w;
    w.show();

    return a.exec();
}
