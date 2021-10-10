/*****************************************
File name:      main.cpp
Author:         luolewin
Version:        v1.0
Description:    Qt自生产的main.cpp，实现事件循环
Date:           2020.12.17
*****************************************/

#include "mainwindow.h"
#include "mystruct.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* 引入自定义结构体 */
    qRegisterMetaType<arcell>("arcell");
    qRegisterMetaType<vexsinfo>("vexsinfo");
    qRegisterMetaType<mgraph>("mgraph");

    MainWindow w;
    w.show();

    return a.exec();
}
