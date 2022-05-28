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
#include <QMainWindow>
#include <QPainter>
#include "graphstruct.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class AdjacencyList;
class MainWindow;

extern Ui::MainWindow *ui_p;
extern MainWindow *ui_wind;
extern int src;
extern int dest;
extern place * placelist[52];
extern QList <QLineF> linelist;



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void draw_line(place *A,place *B);
     void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    AdjacencyList adjacencyList;
    AdjacencyList adjacencyList2;
    void ui_init();
protected:
    void mousePressEvent(QMouseEvent *event);   // 鼠标左击事件
    void closeEvent(QCloseEvent *event);        // 主窗口退出事件
    void mouseMoveEvent(QMouseEvent *e);
private slots:
    void on_walking_button_clicked();
    void on_riding_button_clicked();
    void on_show_walking_button_clicked();
    void on_show_riding_button_clicked();
};
#endif // MAINWINDOW_H
