/*****************************************
File name:      place.cpp
Author:         CHL
Version:        v1.1
Description:    从QLabel继承的GUI控件，具有鼠标移动显示以及图的邻接矩阵等信息
Date:           2022.3.17
*****************************************/
#include "place.h"
#include "mainwindow.h"
#include <QDebug>
#include <QCursor>
#include <QTimer>
#include <QDebug>
//QTimer* place::disabletimer = new QTimer();
place::place(QWidget *parent): QLabel(parent)
{
    this->setMouseTracking(true);
    this->show();
}
place::~place()
{

}
void place::set_place_id(const size_t id)
{
    this->place_id=id;
}
size_t place::get_place_id()
{
    return this->place_id;
}
void place::enterEvent(QEnterEvent *e)
{
    this->setStyleSheet("color: rgba(0, 0, 0,1);background-color: rgba(255, 255, 255,1);");//设为不透明
}
void place::leaveEvent(QEvent *e)
{
    this->setStyleSheet("color: rgba(0, 0, 0,0);background-color: rgba(255, 255, 255,0);");//设为透明
}
