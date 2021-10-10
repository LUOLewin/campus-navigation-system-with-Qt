/*****************************************
File name:      mainwindow.cpp
Author:         luolewin
Version:        v1.0
Description:    实现校园导航主窗口的主要功能
Date:           2020.12.17
*****************************************/

/* 自定义头文件 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"

/* Qt头文件 */
#include <QPainter>
#include <QMessageBox>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QDialog>
#include <QRegExpValidator>
#include <QDebug>

#define Infinity 2000
#define MAX 40
#define key 22

mgraph initgraph();
int locatevex(mgraph c,int v);
int allpath(mgraph c, int start, int end);
void path(mgraph c,int m,int n,int k);
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
    QRegExp regx("\\d{2}");
    QValidator* validator = new QRegExpValidator(regx, this);

    ui->setupUi(this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit2->setValidator(validator);

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
 * @brief 主界面绘图事件
 * @param event
 */
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QRect target1(0, 0, 200, 600);                  // 设置菜单图片绘制位置
    QPixmap menu(":/images/menu.jpg");              // 读取菜单图片

    QRect target2(200, 0, 600, 600);                // 设置校园地图绘制位置
    QPixmap umap(":/images/university_map.jpg");    // 读取校园地图图片

    painter.drawPixmap(target1, menu);              // 绘制menu
    painter.drawPixmap(target2, umap);              // 绘制umap
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

        /* 1行政楼 */
        if ((x > 326 && x < 332) && (y > 442 && y < 448)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser"); // 获取子窗口textBrowser部件

            QPixmap *img = new QPixmap;
            img->load(":/images/administration_building.jpeg");                             // 加载照片
            QLabel *label = messageWindow->findChild<QLabel *>("label");                    // 获取子窗口label部件

            label->setPixmap(*img);                                                         // 设置介绍图片
            textBrowser->setText(tr("行政楼，是机关、事业单位等用于行政办公需要的业务用房。"));    // 设置介绍文字

            messageWindow->exec();
        }
        /* 2第二行政 */
        else if ((x > 373 && x < 379) && (y > 441 && y < 447)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/second_administration_building.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img); // 设置介绍图片
            textBrowser->setText(tr("第二行政办公区，是行政楼的补充业务用房。"));

            messageWindow->exec();
        }
        /* 3第一教学楼 */
        else if ((x > 385 && x < 391) && (y > 390 && y < 396)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.1_teaching_building.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第一教学楼。这是最早修建的教学楼之一，也是马克思主义学院所在地。"));

            messageWindow->exec();
        }
        /* 4第二教学楼 */
        else if ((x > 353 && x < 359) && (y > 379 && y < 385)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.2_teaching_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第二教学楼。第二教学楼A区是大学科技园，A区一楼为易班工作室，B区是理学院所在地。"));

            messageWindow->exec();
        }
        /* 5第三教学楼 */
        else if ((x > 384 && x < 390) && (y > 420 && y < 426)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.3_teaching_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第三教学楼。第三教学楼是经济学院，管理学院所在地。"));

            messageWindow->exec();
        }
        /* 6第四教学楼 */
        else if ((x > 360 && x < 366) && (y > 338 && y < 344)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.4_teaching_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第四教学楼。第四教学楼是使用最频繁的教学楼之一，也是外国语学院的所在地。"));

            messageWindow->exec();
        }
        /* 7第五教学楼 */
        else if ((x > 458 && x < 464) && (y > 215 && y < 221)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.5_teaching_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第五教学楼。其是机械工程学院、材料科学与工程学院、食品与生物工程学院和汽车与交通学院所在地。"));

            messageWindow->exec();
        }
        /* 8第六教学楼 */
        else if ((x > 503 && x < 509) && (y > 274 && y < 280)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/no.6_teaching_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("第六教学楼。是计算机与软件工程学院、电气与电子信息学院、土木建筑与环境学院以及知识产权学院所在地。"));

            messageWindow->exec();
        }
        /* 9艺术大楼 */
        else if ((x > 668 && x < 674) && (y > 235 && y < 241)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/arts_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("艺术大楼，又称七教，是美术与设计学院、音乐与舞蹈学院所在地。在这里的大剧场经常举办大型文艺活动。"));

            messageWindow->exec();
        }
        /* 10实训大楼 */
        else if ((x > 719 && x < 725) && (y > 217 && y < 223)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/training_building.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("实训大楼，又称八教，许多学院的实验室都在此处。在这里学校会进行计算机等级考试和雅思考试。"));

            messageWindow->exec();
        }
        /* 11红砖楼 */
        else if ((x > 415 && x < 421) && (y > 373 && y < 379)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/red_brick_building.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("红砖楼。其应该是学校最有历史的建筑，现在作为一般办公楼使用。"));

            messageWindow->exec();
        }
        /* 12体育馆 */
        else if ((x > 442 && x < 448) && (y > 422 && y < 428)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/stadium.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("体育馆。有室内环境要求的体育课会在此进行教学。"));

            messageWindow->exec();
        }
        /* 13图书馆 */
        else if ((x > 548 && x < 554) && (y > 164 && y < 170)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/library.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("图书馆。除了1楼外，其他楼层都开放给学校所有师生。"));

            messageWindow->exec();
        }
        /* 14校史馆 */
        else if ((x > 427 && x < 433) && (y > 357 && y < 363)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/university_history_museum.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("校史馆，也是档案馆，能参观学校历史，也能查询学生自己的档案。"));

            messageWindow->exec();
        }
        /* 15学术交流中心 */
        else if ((x > 436 && x < 442) && (y > 337 && y < 343)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/academic_center.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("学术交流中心。来学校进行学术交流的学者会在此住宿。"));

            messageWindow->exec();
        }
        /* 16高水平运动中心 */
        else if ((x > 291 && x < 297) && (y > 337 && y < 343)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/high-level_sports_center.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("高水平运动中心。"));

            messageWindow->exec();
        }
        /* 17通用实验厂房 */
        else if ((x > 597 && x < 603) && (y > 84 && y < 90)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/laboratory_workshops.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("通用实验厂房。"));

            messageWindow->exec();
        }
        /* 18附属实验学校 */
        else if ((x > 323 && x < 329) && (y > 338 && y < 344)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/experimental_primary_school.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("大学附属实验学校。"));

            messageWindow->exec();
        }
        /* 19xx苑 */
        else if ((x > 280 && x < 286) && (y > 380 && y < 386)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/jindi_student_hall.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("是离三食堂和西侧门最近的宿舍区，除了七教、八教外，离其他教学楼距离适中，唯一不足就是洗澡不大方便。"));

            messageWindow->exec();
        }
        /* 20xx苑 */
        else if ((x > 537 && x < 543) && (y > 372 && y < 378)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/linjiang_student_hall.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("该宿舍区的地理位置较好，离所有教学楼都近，其他条件中规中矩。"));

            messageWindow->exec();
        }
        /* 21xx苑 */
        else if ((x > 458 && x < 464) && (y > 72 && y < 78)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/dexin_student_hall.jpeg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("该宿舍区离主要教学楼都比较远，唯一优势就是洗澡方便。"));

            messageWindow->exec();
        }
        /* 22xx苑 */
        else if ((x > 349 && x < 355) && (y > 182 && y < 188)) {
            QDialog *messageWindow = new myDialog(this);
            QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

            QPixmap *img = new QPixmap;
            img->load(":/images/xihua_faculty_hall.jpg");
            QLabel *label = messageWindow->findChild<QLabel *>("label");

            label->setPixmap(*img);
            textBrowser->setText(tr("学校教师及其家属居住地。"));

            messageWindow->exec();
        }
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
 * @brief 校园简介按钮实现
 */
void MainWindow::on_pushButton3_clicked()
{
    QDialog *messageWindow = new myDialog(this);
    QTextBrowser *textBrowser = messageWindow->findChild<QTextBrowser *>("textBrowser");

    QPixmap *img = new QPixmap;
    img->load(":/images/XHU.jpg");
    QLabel *label = messageWindow->findChild<QLabel *>("label");

    label->setPixmap(*img);
    textBrowser->setText(tr("xx大学，简称xx，位于xx省xx市，是国家中西部高校基础能力建设工程重点支持高校"
                            "，入选教育部首批\"新工科\"研究与实践项目、教育部本科教学工作水平评估优秀高校"
                            ",xx省首批深化创新创业教育改革示范高校"
                            "；xx省卓越工程师教育培养计划、xx省卓越农林人才教育培养计划、xx2011计划、xx省\"双一流\"建设计划"
                            "，xx地区双城经济圈高校联盟成员，是一所多学科协调发展的xx省属综合性大学。"));

    messageWindow->exec();
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

    for(i=1; i<=key; i++)   // 依次设置顶点编号
    {
      c.vexs[i].position = i;
    }

    /* 依次输入顶点信息 */
    strcpy(c.vexs[1].name,"行政楼");
    strcpy(c.vexs[2].name,"第二行政办公区");
    strcpy(c.vexs[3].name,"第一教学楼");
    strcpy(c.vexs[4].name,"第二教学楼");
    strcpy(c.vexs[5].name,"第三教学楼");
    strcpy(c.vexs[6].name,"第四教学楼");
    strcpy(c.vexs[7].name,"第五教学楼");
    strcpy(c.vexs[8].name,"第六教学楼");
    strcpy(c.vexs[9].name,"艺术大楼");
    strcpy(c.vexs[10].name,"实训大楼");
    strcpy(c.vexs[11].name,"红砖楼");
    strcpy(c.vexs[12].name,"体育馆");
    strcpy(c.vexs[13].name,"图书馆");
    strcpy(c.vexs[14].name,"校史馆");
    strcpy(c.vexs[15].name,"学术交流中心");
    strcpy(c.vexs[16].name,"高水平运动中心");
    strcpy(c.vexs[17].name,"通用实验厂房");
    strcpy(c.vexs[18].name,"附属实验学校");
    strcpy(c.vexs[19].name,"xx苑");
    strcpy(c.vexs[20].name,"xx苑");
    strcpy(c.vexs[21].name,"xx苑");
    strcpy(c.vexs[22].name,"xx苑");

    for (i=1; i<=key; i++) {
      for (j=1;j<=key;j++) {
        c.arcs[i][j].adj=Infinity;  // 先初始化图的邻接矩阵
      }

      c.arcs[1][2].adj=30;c.arcs[1][4].adj=30;c.arcs[1][19].adj=35;c.arcs[2][5].adj=5;c.arcs[3][5].adj=10;
      c.arcs[3][4].adj=10;c.arcs[3][11].adj=10;c.arcs[4][6].adj=15;c.arcs[5][12].adj=30;c.arcs[6][7].adj=55;
      c.arcs[6][15].adj=30;c.arcs[6][18].adj=15;c.arcs[6][22].adj=60;c.arcs[7][8].adj=30;c.arcs[7][13].adj=35;
      c.arcs[7][22].adj=40;c.arcs[8][13].adj=40;c.arcs[8][15].adj=35;c.arcs[8][20].adj=30;c.arcs[9][10].adj=20;
      c.arcs[9][13].adj=45;c.arcs[9][20].adj=60;c.arcs[10][17].adj=70;c.arcs[11][14].adj=10;c.arcs[12][20].adj=45;
      c.arcs[13][17].adj=35;c.arcs[14][15].adj=10;c.arcs[16][18].adj=10;c.arcs[16][19].adj=15;c.arcs[17][21].adj=55;
      c.arcs[21][22].adj=50;
    }

    /* 邻接矩阵是对称矩阵，对称赋值(无向图需要对称赋值) */
    for(i=1;i<=key;i++)
    {
      for(j=1;j<=key;j++)
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

    for (k=0; k<key; k++) {    // 全部顶点访问标志初值设为0
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
    for (i=1; i<=key; i++) {   // 将图的邻接矩阵赋值给 shortest二维数组，将矩阵pathh全部初始化为-1
        for (j=1; j<=key; j++) {
            shortest[i][j] = c.arcs[i][j].adj;
            pathh[i][j] = j;
        }
    }

    for (k=1; k<=key; k++) {   // 核心操作，完成了以k为中间点对所有的顶点对（i,j）进行检测和修改
        for (i=1; i<=key; i++) {
            for (j=1; j<=key; j++) {
                if (shortest[i][j] > shortest[i][k]+shortest[k][j]) {
                    shortest[i][j] = shortest[i][k]+shortest[k][j];
                    pathh[i][j] = pathh[i][k];  // 记录一下所走的路，P数组用来存放前驱顶点
                }
             }
        }
    }
}

