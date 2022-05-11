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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    campus = new graph();
    campus->ui_all=ui;
    ui->setupUi(this);
    this->setMouseTracking(true);
    //设置控件ID
    ui->Nan_Qu->set_place_id(1);
    ui->Xin_Shi_Ji->set_place_id(2);
    ui->Hou_Qin->set_place_id(3);
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
void MainWindow::on_available_path_button_clicked()
{
//    int start = ui->lineEdit->text().toInt();   // 获取起点位置
//    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

//    ui->textBrowser->clear();                   // 清除浏览框里的文本

//    if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
//        allpath(campus, start, end);    // 可选路径搜索
//    }
}


/**
 * @brief 最短路径按钮实现，显示从起点到终点的最短路径
 */
void MainWindow::on_shortest_path_button_clicked()
{
//    int start = ui->lineEdit->text().toInt();   // 获取起点位置
//    int end = ui->lineEdit2->text().toInt();    // 获取终点位置

//    ui->textBrowser2->clear();                  // 清除浏览框里的文本

//    if ((start > 0 and start < 23) and (end > 0 and end < 23)) {
//        shortdistance(campus, start, end);
//    }
}



void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    ui->MousePosLabel->setText("位置：("+QString::number(e->x())+","+QString::number(e->y())+")");//显示内容(x,y)
}
