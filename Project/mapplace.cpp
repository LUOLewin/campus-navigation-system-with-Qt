#include "mapplace.h"
#include <QDebug>
mapplace::mapplace(QWidget *parent):QAbstractButton(parent)
{

}
mapplace::~mapplace()
{

}
void mapplace::click()
{
    qDebug()<<"1";
}
//void mapplace::paintEvent(QPaintEvent *e)
//{
//    QPainter mappainter;
//}
