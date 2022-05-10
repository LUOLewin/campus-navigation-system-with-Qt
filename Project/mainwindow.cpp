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
/* Qt头文件 */
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegExp>
#include <QDebug>
#include <QValidator>
#define Infinity 2000
#define MAX 40
#define KEY 22

mgraph initgraph();
int locatevex(mgraph c,int v);
QString transtring;

mgraph campus;  // 图变量（校园）
int d[30];
int visited[30];
int shortest[MaxVertexNum][MaxVertexNum];   // 定义全局变量存储最小路径
int pathh[MaxVertexNum][MaxVertexNum];      // 定义存储路径


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    campus = initgraph();

    /* 使用正则表达式，限制用户输入 */
    //QRegExp regx("\\d{2}");


    //QValidator* validator = new QValidator(regx, this);
    //QValidator validator=regx;
    ui->setupUi(this);
    this->setMouseTracking(true);
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
        ui->label_2->setText("点击：("+QString::number(x)+","+QString::number(y)+")");
    }
}


/**
 * @brief 可选路径按钮实现，显示从起点到终点的所有可达路径
 */
void MainWindow::on_pushButton_clicked()
{
    int start = ui->lineEdit->text().toInt();   // 获取起点位置
    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

    ui->textBrowser->clear();                   // 清除浏览框里的文本

    if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
        allpath(campus, start, end);    // 可选路径搜索
    }
}


/**
 * @brief 最短路径按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_pushButton2_clicked()
{
    int start = ui->lineEdit->text().toInt();   // 获取起点位置
    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

    ui->textBrowser2->clear();                  // 清除浏览框里的文本

    if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
        shortdistance(campus, start, end);
    }
}
/**
 * @brief 图初始化函数
 * @return mgraph 地图数据结构
 */
mgraph initgraph()
{
    int i,j;
    mgraph c;
    c.vexnum=22;            // 顶点个数，即地点个数
    c.arcnum=31;            // 边的个数，即路径个数

    for(i=1; i<=KEY; i++)   // 依次设置顶点编号
    {
      c.vexs[i].position = i;
    }

    /* 依次输入顶点信息 */
//    strcpy(c.vexs[1].name,"");
//    strcpy(c.vexs[2].name,"");
//    strcpy(c.vexs[3].name,"");
//    strcpy(c.vexs[4].name,"");
//    strcpy(c.vexs[5].name,"");
//    strcpy(c.vexs[6].name,"");
//    strcpy(c.vexs[7].name,"");
//    strcpy(c.vexs[8].name,"");
//    strcpy(c.vexs[9].name,"");
//    strcpy(c.vexs[10].name,"");
//    strcpy(c.vexs[11].name,"");
//    strcpy(c.vexs[12].name,"");
//    strcpy(c.vexs[13].name,"");
//    strcpy(c.vexs[14].name,"");
//    strcpy(c.vexs[15].name,"");
//    strcpy(c.vexs[16].name,"");
//    strcpy(c.vexs[17].name,"");
//    strcpy(c.vexs[18].name,"");
//    strcpy(c.vexs[19].name,"");
//    strcpy(c.vexs[20].name,"");
//    strcpy(c.vexs[21].name,"");
//    strcpy(c.vexs[22].name,"");

    for (i=1; i<=KEY; i++) {
      for (j=1;j<=KEY;j++) {
        c.arcs[i][j].adj=Infinity;  // 先初始化图的邻接矩阵
      }

//      c.arcs[1][2].adj=30;c.arcs[1][4].adj=30;c.arcs[1][19].adj=35;c.arcs[2][5].adj=5;c.arcs[3][5].adj=10;
//      c.arcs[3][4].adj=10;c.arcs[3][11].adj=10;c.arcs[4][6].adj=15;c.arcs[5][12].adj=30;c.arcs[6][7].adj=55;
//      c.arcs[6][15].adj=30;c.arcs[6][18].adj=15;c.arcs[6][22].adj=60;c.arcs[7][8].adj=30;c.arcs[7][13].adj=35;
//      c.arcs[7][22].adj=40;c.arcs[8][13].adj=40;c.arcs[8][15].adj=35;c.arcs[8][20].adj=30;c.arcs[9][10].adj=20;
//      c.arcs[9][13].adj=45;c.arcs[9][20].adj=60;c.arcs[10][17].adj=70;c.arcs[11][14].adj=10;c.arcs[12][20].adj=45;
//      c.arcs[13][17].adj=35;c.arcs[14][15].adj=10;c.arcs[16][18].adj=10;c.arcs[16][19].adj=15;c.arcs[17][21].adj=55;
//      c.arcs[21][22].adj=50;
    }

    /* 邻接矩阵是对称矩阵，对称赋值(无向图需要对称赋值) */
    for(i=1;i<=KEY;i++)
    {
      for(j=1;j<=KEY;j++)
      {
        c.arcs[j][i].adj=c.arcs[i][j].adj;
      }
    }

    return c;
}


/**
 * @brief 查找景点在图中的序号
 * @param c
 * @param v
 * @return i 顶点序号; -1 没有找到该顶点
 */
int locatevex(mgraph c,int v)
{
    int i;
    for (i=1;i<=c.vexnum;i++)
      if (v==c.vexs[i].position)  return i;  // 找到，返回顶点序号i
    return -1;  // 没有找到该顶点
}


/**
 * @brief 查找并输出序号为m,n景点间的长度不超过8个景点的路径
 * @param c
 * @param m
 * @param n
 * @param k
 */
void MainWindow::path(mgraph c, int m, int n, int k)
{
    int s, t=k+1, length=0;      // t用于存放路径上下一个顶点对应的d[]数组元素的下标

    if (d[k] == n && k<8) {      // 若d[k]是终点n且景点个数<=8,则输出该路径
        for (s=0; s<k; s++) {    // 计算路径长度
            length = length+c.arcs[d[s]][d[s+1]].adj;
        }

        if (length <= 250) {        // 打印路径长度小于定长的路径
            for (s=0; s<k; s++) {   // 输出该路径。s=0时为起点m
                transtring.append(QString::number(c.vexs[d[s]].position) + "-->");
            }

            transtring.append(QString::number(c.vexs[d[s]].position));  // 输出最后一个景点名（即顶点n的名字，此时s==k）
            ui->textBrowser->append(transtring);
            ui->textBrowser->append("总路线长为" + QString::number(length));
        }

        transtring.clear();

    } else {
        s = 1;

        while (s <= c.vexnum) {                                       // 从第m个顶点，试探所有顶点是否有路径
            if ((c.arcs[d[k]][s].adj<Infinity) && (visited[s]==0)) {  // 顶点m到顶点s有边(权值不为无穷大)，且未被访问
                visited[s]=1;
                d[k+1]=s;       // 存储顶点编号
                path(c,m,n,t);
                visited[s]=0;   // 将找到的路径上顶点的访问标志重新设置为0，以用于试探新的路径
            }

            s++;    // 试探从下一个顶点s开始是否有到终点的路径
        }
    }
}


/**
 * @brief 查找两景点间的所有路径
 * @param c     地图数据结构
 * @param start 起点序号
 * @param end   终点序号
 */
void MainWindow::allpath(mgraph c, int start, int end)
{
    int k, m, n;
    m=locatevex(c, start);   // locatevex 确定该顶点是否存在。若存在，返回该顶点编号。
    n=locatevex(c, end);
    d[0] = m;                 // 存储路径起点m（int d[]数组是全局变量）

    for (k=0; k<KEY; k++) {    // 全部顶点访问标志初值设为0
      visited[k] = 0;
    }

    visited[m] = 1;           // 第m个顶点访问标志设置为1
    path(c, m, n, 0);          // 调用程序。k=1，对应起点d[1]==m。k为d[]数组下标
}


/**
 * @brief 任意两点间最短距离
 * @param c     地图数据结构
 * @param start 起点序号
 * @param end   终点序号
 */
void MainWindow::shortdistance(mgraph c, int start, int end)
{
    int i, j;
    i = start;
    j = end;

    floyd(c);   // 调用floyd算法

    transtring.append(QString::number(start) + "-->");

    while (pathh[start][end] != end) {
        transtring.append(QString::number(pathh[start][end]) + "-->");
        start = pathh[start][end];
    }

    transtring.append(QString::number(end));
    ui->textBrowser2->append(transtring);
    ui->textBrowser2->append("最短路线长为" + QString::number(shortest[i][j]));

    transtring.clear();
}


/**
 * @brief 弗洛伊德算法
 * @param c 地图数据结构
 */
void MainWindow::floyd(mgraph c)
{
    int i, j, k;
    for (i=1; i<=KEY; i++) {   // 将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1
        for (j=1; j<=KEY; j++) {
            shortest[i][j] = c.arcs[i][j].adj;
            pathh[i][j] = j;
        }
    }

    for (k=1; k<=KEY; k++) {   // 核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改
        for (i=1; i<=KEY; i++) {
            for (j=1; j<=KEY; j++) {
                if (shortest[i][j] > shortest[i][k]+shortest[k][j]) {
                    shortest[i][j] = shortest[i][k]+shortest[k][j];
                    pathh[i][j] = pathh[i][k];  // 记录一下所走的路，P数组用来存放前驱顶点
                }
             }
        }
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    ui->MousePosLabel->setText("位置：("+QString::number(e->x())+","+QString::number(e->y())+")");//显示内容(x,y)
}
