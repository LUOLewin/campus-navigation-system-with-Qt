/*****************************************
File name:      mainwindow.cpp
Author:         CHL
Version:        v1.1
Description:    实现校园导航主窗口的主要功能
Date:           2022.3.17
*****************************************/

/* 自定义头文件 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include "place.h"
#include "graph.h"
/* Qt头文件 */
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegExp>
#include <QDebug>
#include <QTextCodec>
#include <QPixmap>
#include <QList>
#include <QLineF>
place * placelist[52];
extern Ui::MainWindow *ui_p;
MainWindow *ui_wind;
place *A;
place* B;
extern int src;
extern int dest;
QList <QLineF> linelist;
int click=0;
//QByteArray conv(QByteArray a)
//{
//    QTextCodec *c=QTextCodec::codecForName("utf8");
//    a=c->toUnicode(a);
//    return a;
//}
void MainWindow::draw_line(place *src, place *dest)
{
    A = src;
    B = dest;
}
void MainWindow::ui_init()
{
    this->adjacencyList.ui_all = ui;
    this->adjacencyList2.ui_all = ui;
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui_wind = this;
    ui->setupUi(this);
    this->setMouseTracking(true);
    ui->map->lower();
    ui_init();
    ui_p = ui;
    A = ui->Node_0;
    B = ui->Node_1;
    placelist[0] = ui->Node_0;
    placelist[1] = ui->Node_1;
    placelist[2] = ui->Node_2;
    placelist[3] = ui->Node_3;
    placelist[4] = ui->Node_4;
    placelist[5] = ui->Node_5;
    placelist[6] = ui->Node_6;
    placelist[7] = ui->Node_7;
    placelist[8] = ui->Node_8;
    placelist[9] = ui->Node_9;
    placelist[10] = ui->Node_10;
    placelist[11] = ui->Node_11;
    placelist[12] = ui->Node_12;
    placelist[13] = ui->Node_13;
    placelist[14] = ui->Node_14;
    placelist[15] = ui->Node_15;
    placelist[16] = ui->Node_16;
    placelist[17] = ui->Node_17;
    placelist[18] = ui->Node_18;
    placelist[19] = ui->Node_19;
    placelist[20] = ui->Node_20;
    placelist[21] = ui->Node_21;
    placelist[22] = ui->Node_22;
    placelist[23] = ui->Node_23;
    placelist[24] = ui->Node_24;
    placelist[25] = ui->Node_25;
    placelist[26] = ui->Node_26;
    placelist[27] = ui->Node_27;
    placelist[28] = ui->Node_28;
    placelist[29] = ui->Node_29;
    placelist[30] = ui->Node_30;
    placelist[31] = ui->Node_31;
    placelist[32] = ui->Node_32;
    placelist[33] = ui->Node_33;
    placelist[34] = ui->Node_34;
    placelist[35] = ui->Node_35;
    placelist[36] = ui->Node_36;
    placelist[37] = ui->Node_37;
    placelist[38] = ui->Node_38;
    placelist[39] = ui->Node_39;
    placelist[40] = ui->Node_40;
    placelist[41] = ui->Node_41;
    placelist[42] = ui->Node_42;
    placelist[43] = ui->Node_43;
    placelist[44] = ui->Node_44;
    placelist[45] = ui->Node_45;
    placelist[46] = ui->Node_46;
    placelist[47] = ui->Node_47;
    placelist[48] = ui->Node_48;
    placelist[49] = ui->Node_49;
    placelist[50] = ui->Node_50;

//    placelist->append(ui->Node_0);
//    placelist->append(ui->Node_1);
//    placelist->append(ui->Node_2);
//    placelist->append(ui->Node_3);
//    placelist->append(ui->Node_4);
//    placelist->append(ui->Node_5);
//    placelist->append(ui->Node_6);
//    placelist->append(ui->Node_7);
//    placelist->append(ui->Node_8);
//    placelist->append(ui->Node_9);
//    placelist->append(ui->Node_10);
//    placelist->append(ui->Node_11);
//    placelist->append(ui->Node_12);
//    placelist->append(ui->Node_13);
//    placelist->append(ui->Node_14);
//    placelist->append(ui->Node_15);
//    placelist->append(ui->Node_16);
//    placelist->append(ui->Node_17);
//    placelist->append(ui->Node_18);
//    placelist->append(ui->Node_19);
//    placelist->append(ui->Node_20);
//    placelist->append(ui->Node_21);
//    placelist->append(ui->Node_22);
//    placelist->append(ui->Node_23);
//    placelist->append(ui->Node_24);
//    placelist->append(ui->Node_25);
//    placelist->append(ui->Node_26);
//    placelist->append(ui->Node_27);
//    placelist->append(ui->Node_28);
//    placelist->append(ui->Node_29);
//    placelist->append(ui->Node_30);
//    placelist->append(ui->Node_31);
//    placelist->append(ui->Node_32);
//    placelist->append(ui->Node_33);
//    placelist->append(ui->Node_34);
//    placelist->append(ui->Node_35);
//    placelist->append(ui->Node_36);
//    placelist->append(ui->Node_37);
//    placelist->append(ui->Node_38);
//    placelist->append(ui->Node_39);
//    placelist->append(ui->Node_40);
//    placelist->append(ui->Node_41);
//    placelist->append(ui->Node_42);
//    placelist->append(ui->Node_43);
//    placelist->append(ui->Node_44);
//    placelist->append(ui->Node_45);
//    placelist->append(ui->Node_46);
//    placelist->append(ui->Node_47);
//    placelist->append(ui->Node_48);
//    placelist->append(ui->Node_49);
//    placelist->append(ui->Node_50);
    //ui->Node_0->draw_line(ui->Node_0,ui->Node_49);
    //QLine* line=new QLine(A->x(),A->y(),B->x(),B->y());
//    QPainter painter(this);
//    QPen pen(QColor(255,0,0));
//    pen.setWidth(10);
//    painter.setPen(pen);
//    painter.translate(0,0);
//    painter.drawLine(ui->Node_0->x(),ui->Node_0->y(),ui->Node_49->x(),ui->Node_49->y());
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief 主界面关闭事件实现
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent * event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "提示", tr("确定退出导航系统？\n")
                                                               , QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event-> ignore();
    } else {
        event-> accept();
    }
}

/**
 * @brief 鼠标左击事件，判断鼠标全局位置，弹出相应子窗口
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {                // 发生鼠标左击事件
        int x = this->mapFromGlobal(QCursor().pos()).x();   // 获取鼠标返回的横坐标
        int y = this->mapFromGlobal(QCursor().pos()).y();   // 获取鼠标返回的纵坐标

//        ui->lineEdit->clear();
//        ui->lineEdit2->clear();
        //click++;
//        ui->label_2->setText("已经点击了第：("+QString::number(1)+"个点，正在点击第"+QString::number(1)+"个点！");
    }
}


/**
 * @brief 可选路径按钮实现，显示从起点到终点的所有可达路径
 */
void MainWindow::on_available_path_button_clicked()
{
    place::red=0;
    for(int i =0;i<=50;i++)
        placelist[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
    linelist.clear();
    QTextCodec *c=QTextCodec::codecForName("utf8");
    QString a="当前为步行模式";
    a=c->toUnicode("当前为步行模式");
    int originPos = ui->lineEdit->text().toInt();
    src = originPos;
    int endPos=ui->lineEdit2->text().toInt();
    ui->textBrowser->append(c->toUnicode("当前为步行模式"));
    GraphAdjList* GA = new GraphAdjList;
    this->adjacencyList.InitMap(GA);
    this->adjacencyList.CreateALGraph(GA);
    this->adjacencyList.ShortestPath_Floyd(GA, this->adjacencyList.ShortestPathmatrix, this->adjacencyList.ShortestPathvalue);

    this->adjacencyList.ShowShortestResult(originPos, endPos);

    delete GA;
}


/**
 * @brief 最短路径按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_shortest_path_button_clicked()
{
    place::red=0;
    for(int i =0;i<=50;i++)
        placelist[i]->setStyleSheet("background-color: rgb(255, 255, 255);");
    linelist.clear();

    QTextCodec *c=QTextCodec::codecForName("utf8");
    QString a="当前为骑行模式";
    a=c->toUnicode("当前为骑行模式");
    int originPos = ui->lineEdit->text().toInt();
    src = originPos;
    int endPos=ui->lineEdit2->text().toInt();
    ui->textBrowser2->append(c->toUnicode("当前为骑行模式"));
    GraphAdjList* GB = new GraphAdjList;
    this->adjacencyList2.InitMap1(GB);
    this->adjacencyList2.CreateALGraph2(GB);
    this->adjacencyList2.ShortestPath_Floyd2(GB, this->adjacencyList2.ShortestPathmatrix, this->adjacencyList2.ShortestPathvalue);

    this->adjacencyList2.ShowShortestResult2(originPos, endPos);

    delete GB;

}



void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    ui->MousePosLabel->setText("位置：("+QString::number(e->x())+","+QString::number(e->y())+")");//显示内容(x,y)
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    //ui->map->lower();

    QPainter *painter1=new QPainter(this);
    QPixmap pix = QPixmap(":/images/image/SchoolMap.png");
    //QLine line = QLine(ui->Node_0->x(),ui->Node_0->y(),ui->Node_49->x(),ui->Node_49->y());
    //QPainter painter(this);
    //QPen pen(QColor(255,0,0));
//    pen.setWidth(10);
//    painter.setPen(pen);
//    painter.translate(0,0);
    painter1->drawPixmap(0,0,1091,681,pix);
    //painter.drawLine(line);
    //QLine line1 = QLine(A->x(),A->y(),B->x(),B->y());
    //ainter1->save();
    QPen pen1(QColor(255,0,0));
    pen1.setWidth(5);
    painter1->setPen(pen1);
    painter1->translate(0,0);
    //painter1->drawLine(line1);
    painter1->drawLines(linelist);
    //painter1->restore();
    delete painter1;
    //ui->map->lower();
    update();
}
