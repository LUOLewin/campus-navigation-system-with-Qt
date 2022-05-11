#ifndef GRAPH_H
#define GRAPH_H
#include <QString>
#include "mystruct.h"
#include "ui_mainwindow.h"
#define Infinity 2000
#define MAX 40
#define KEY 22
class graph
{
public:
    graph();
    ~graph();
    void path(mgraph c,int m,int n,int k);
    void allpath(mgraph c, int start, int end);
    void shortdistance(mgraph c, int start, int end);
    void floyd(mgraph c);
    Ui::MainWindow *ui_all;
private:
    QString transtring;

    mgraph graphhandle;  // 图变量（校园）
    int d[30];
    int visited[30];
    int shortest[MaxVertexNum][MaxVertexNum];   // 定义全局变量存储最小路径
    int pathh[MaxVertexNum][MaxVertexNum];      // 定义存储路径
};

#endif // GRAPH_H
