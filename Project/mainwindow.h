/*****************************************
File name:      mainwindow.h
Author:         CHL
Version:        v1.1
Description:    校园导航主窗口cpp的头文件，函数声明
Date:           2022.3.17
*****************************************/
//#include <QLabel>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mystruct.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void path(mgraph c,int m,int n,int k);
    void allpath(mgraph c, int start, int end);
    void shortdistance(mgraph c, int start, int end);
    void floyd(mgraph c);

private:
    Ui::MainWindow *ui;
    //QLabel nanqu;
protected:
    void mousePressEvent(QMouseEvent *event);   // 鼠标左击事件
    void closeEvent(QCloseEvent *event);        // 主窗口退出事件
    void mouseMoveEvent(QMouseEvent *e);
private slots:
    void on_pushButton_clicked();
    void on_pushButton2_clicked();

};
#endif // MAINWINDOW_H
