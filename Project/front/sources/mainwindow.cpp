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
//界面操作指针
Ui::MainWindow *ui_p;//用于给地点控件子类提供访问
MainWindow *ui_wind;//给图数据结构提供访问

//地点控件和连接线线性表管理
place * placelist[52];
QList <QLineF> linelist;

//存储画线的地点id
int src;
int dest;

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
    this->ui->map->lower();
    this->ui_init();
    ui_p = ui;
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_show_walking_button_clicked()
{
    this->ui->textBrowser_2->clear();
    GraphAdjList* GA = new GraphAdjList;
    this->adjacencyList.init_walking_map(GA);
    this->adjacencyList.CreateALGraph(GA);
    this->adjacencyList.ShowALGraph(GA);
    delete GA;
}
void MainWindow::on_show_riding_button_clicked()
{
    this->ui->textBrowser_2->clear();
    GraphAdjList* GB = new GraphAdjList;
    this->adjacencyList.init_riding_map(GB);
    this->adjacencyList.CreateALGraph2(GB);
    this->adjacencyList.ShowALGraph(GB);
    delete GB;
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
    }
}


/**
 * @brief 步行按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_walking_button_clicked()
{
    this->ui->textBrowser->clear();
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
    this->adjacencyList.init_walking_map(GA);
    this->adjacencyList.CreateALGraph(GA);
    this->adjacencyList.shortest_path_floyd_walking(GA, this->adjacencyList.ShortestPathmatrix, this->adjacencyList.ShortestPathvalue);

    this->adjacencyList.ShowShortestResult(originPos, endPos);

    delete GA;
}


/**
 * @brief 骑行按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_riding_button_clicked()
{
    this->ui->textBrowser2->clear();
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
    this->adjacencyList2.init_riding_map(GB);
    this->adjacencyList2.CreateALGraph2(GB);
    this->adjacencyList2.shortest_path_floyd_riding(GB, this->adjacencyList2.ShortestPathmatrix, this->adjacencyList2.ShortestPathvalue);

    this->adjacencyList2.ShowShortestResult2(originPos, endPos);

    delete GB;

}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    ui->MousePosLabel->setText("位置：("+QString::number(e->x())+","+QString::number(e->y())+")");//显示内容(x,y)
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter *painter1=new QPainter(this);
    QPixmap pix = QPixmap(":/images/image/SchoolMap.png");
    painter1->drawPixmap(0,0,1091,681,pix);
    QPen pen1(QColor(255,0,0));
    pen1.setWidth(5);
    painter1->setPen(pen1);
    painter1->translate(0,0);
    painter1->drawLines(linelist);
    delete painter1;
    update();
}
