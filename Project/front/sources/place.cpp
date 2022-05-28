/*****************************************
File name:      place.cpp
Author:         CHL
Version:        v1.1
Description:    从QLabel继承的GUI控件，具有鼠标移动显示以及对应的id
Date:           2022.3.17
*****************************************/
#include "place.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCursor>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QLine>

int place::clicks = 0;
int place::red = 0;

place::place(QWidget *parent): QLabel(parent)
{

    this->setMouseTracking(true);
    this->show();

}
place::~place()
{

}
void place::mousePressEvent(QMouseEvent *e)
{
    if(clicks==0)
    {
        clicks++;
        ui_p->lineEdit->setText(this->text());
        ui_p->label_2->setText("已经第："+QString::number(1)+"个点，正在第"+QString::number(2)+"个点！");
        if (red<3)
        {
            this->setStyleSheet("background-color: rgb(255, 0,0);");
            red++;
        }
        else
        {

        }
    }
    else if(clicks == 1){
        clicks = 0;
        ui_p->lineEdit2->setText(this->text());
        ui_p->label_2->setText("已经第："+QString::number(2)+"个点，正在第"+QString::number(1)+"个点！");
        if (red<3)
        {
            this->setStyleSheet("background-color: rgb(255, 0,0);");
            red++;
        }
        else if(red == 3)
        {

        }
    }
    else {this->setStyleSheet("background-color: rgb(255, 255,255);");}
}
