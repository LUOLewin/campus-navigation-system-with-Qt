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
#include "graph.h"
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

private:
    Ui::MainWindow *ui;
    graph* campus;
protected:
    void mousePressEvent(QMouseEvent *event);   // 鼠标左击事件
    void closeEvent(QCloseEvent *event);        // 主窗口退出事件
    void mouseMoveEvent(QMouseEvent *e);
private slots:
    void on_available_path_button_clicked();
    void on_shortest_path_button_clicked();

};
#endif // MAINWINDOW_H
