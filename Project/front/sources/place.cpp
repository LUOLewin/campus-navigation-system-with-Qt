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
Ui::MainWindow *ui_p;
extern place * placelist[52];
place::place(QWidget *parent): QLabel(parent)
{

    this->setMouseTracking(true);
    this->show();
    //qDebug() << this->text();

}
place::~place()
{

}
void place::set_place_id(const size_t id)
{
    this->place_id=id;
}
const size_t place::get_place_id()
{
    return this->place_id;
}
void place::enterEvent(QEnterEvent *e)
{
    this->setStyleSheet("color: rgba(0, 0, 0,1);background-color: rgba(255, 255, 255,1);");//设为不透明
}
void place::leaveEvent(QEvent *e)
{
    //this->setStyleSheet("color: rgba(0, 0, 0,0);background-color: rgba(255, 255, 255,0);");//设为透明
}
void place::mousePressEvent(QMouseEvent *e)
{
    place_id = this->text().toShort();

    //qDebug() << place_id;
    if(clicks==0)
    {
        clicks++;
        ui_p->lineEdit->setText(QString::number(get_place_id()));
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
        ui_p->lineEdit2->setText(QString::number(get_place_id()));
        ui_p->label_2->setText("已经第："+QString::number(2)+"个点，正在第"+QString::number(1)+"个点！");
        if (red<3)
        {
            this->setStyleSheet("background-color: rgb(255, 0,0);");
            red++;
        }
        else
        {

        }
    }
    else {this->setStyleSheet("background-color: rgb(255, 255,255);");}
}
void place::draw_line(place *A,place *B)
{
//    QLine* line=new QLine(A->x(),A->y(),B->x(),B->y());
//    QPainter painter(this);
//    QPen pen(QColor(255,0,0));
//    painter.setPen(pen);
//    painter.drawLine(A->x(),A->y(),B->x(),B->y());
}
