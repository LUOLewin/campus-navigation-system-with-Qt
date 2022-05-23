#ifndef GRAPHSTRUCT_H
#define GRAPHSTRUCT_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ui_mainwindow.h"
//边表结点
typedef struct EdgeNode {
    //顶点对应的下标
    int adjvex;
    //权值
    int weight;
    //指向下一个邻接点
    struct EdgeNode* next;
} edgeNode;

//顶点表结点
typedef struct _VertexNode {
    //顶点数据
    char data[51];
    //边表头指针
    edgeNode* firstedge;
} VertexNode, AdjList[100];

//集合
typedef struct _GraphAdjList{
    AdjList adjList;
    //顶点数和边数
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList {
public:


    void ShowALGraph(GraphAdjList* G);

    //初始化地图(步行或地图)
    void InitMap(GraphAdjList* G);
    void InitMap1(GraphAdjList* G);
    //创建地图
    void CreateALGraph(GraphAdjList* G);
    void CreateALGraph2(GraphAdjList* G);

    //计算各个顶点之间最短路径
    void ShortestPath_Floyd(GraphAdjList* G, int P[51][51], int D[51][51]);
    void ShortestPath_Floyd2(GraphAdjList* G, int P[51][51], int D[51][51]);

    //输出路径长度和具体路径
    void ShowShortestResult(int originPos, int endPos);
    void ShowShortestResult2(int originPos, int endPos);
    int ShortestPathvalue[51][51] = { 0 };
    int ShortestPathvalue2[51][51] = { 0 };
    //存储具体路径
    int ShortestPathmatrix[51][51] = { 0 };
    int ShortestPathmatrix2[51][51] = { 0 };
    char _mapName[51][51] = {"南区宿舍正门", "吾馨食堂", "学校西南门", "学校西南车库", "后勤基建大楼", "高尔夫练习场", "篮球场入口", "西南足球场入口", "苗圃入口", "西南三岔路口", "荷花池", "校内2号楼",
                             "老旧篮球场", "商店区", "快递点", "上大浴室", "益新食堂", "梅园", "山明食堂", "网球场", "西门", "北门", "校医院",
                             "尔美食堂","风雨操场入口","游泳馆","训练场","体育场","运动场","音乐学院","伟长楼","图书馆","F教学楼","J楼","B教学楼","音乐广场","美院大楼","行政楼","正门","溯园","东2门","HD","水秀食堂","东1门","东区食堂","钱伟长图书馆","翔英大楼","博士后公寓","专家公寓","北1门","乐乎楼" };
    //距离信息,_distance[0][1] = 50;代表从下标为0到下表为1地点距离为50
    int _distance[51][51] = { 0 };
    int _distance2[51][51] = { 0 };
   Ui::MainWindow *ui_all=nullptr;
    //Ui::MainWindow *ui;
};


#endif // GRAPHSTRUCT_H
