#ifndef GRAPHSTRUCT_H
#define GRAPHSTRUCT_H
#include <string.h>
#include <stdlib.h>
#include "ui_mainwindow.h"

typedef struct EdgeNode {

    int adjvex;

    int weight;

    struct EdgeNode* next;
} edgeNode;


typedef struct _VertexNode {

    char data[51];

    edgeNode* firstedge;
} VertexNode, AdjList[100];


typedef struct _GraphAdjList{
    AdjList adjList;
    int numVertexes, numEdges;
} GraphAdjList;

class AdjacencyList {
public:


    void ShowALGraph(GraphAdjList* G);

    //初始化地图(步行或地图)
    void init_walking_map(GraphAdjList* G);
    void init_riding_map(GraphAdjList* G);
    //创建地图
    void CreateALGraph(GraphAdjList* G);
    void CreateALGraph2(GraphAdjList* G);

    //计算各个顶点之间最短路径
    void shortest_path_floyd_walking(GraphAdjList* G, int P[51][51], int D[51][51]);
    void shortest_path_floyd_riding(GraphAdjList* G, int P[51][51], int D[51][51]);

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
};


#endif // GRAPHSTRUCT_H

