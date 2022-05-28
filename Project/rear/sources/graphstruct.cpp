#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphstruct.h"
#include <QDebug>

//�������е�ͼ
void AdjacencyList::CreateALGraph(GraphAdjList* G) {
    edgeNode* e;
    //���붥����Ϣ�����������
    for (int i = 0; i < G->numVertexes; i++)
    {
        //���붥����Ϣ
        strcpy_s(G->adjList[i].data, _mapName[i]);
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
    }
    //�����߱���ͷ�巨��
    for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp;
            if (_distance[i][j] != 0 || _distance[j][i] != 0)
            {
                if (_distance[i][j] != 0)
                {
                    temp = _distance[i][j];
                    _distance[j][i] = _distance[i][j];
                }
                else
                {
                    temp = _distance[j][i];
                    _distance[i][j] = _distance[j][i];
                }
                e = new EdgeNode;
                e->adjvex = j;
                e->next = G->adjList[i].firstedge;
                e->weight = temp;
                G->adjList[i].firstedge = e;

                e = new EdgeNode;
                e->adjvex = i;
                e->next = G->adjList[j].firstedge;
                e->weight = temp;
                G->adjList[j].firstedge = e;
            }

        }
    }
}

//�������е�ͼ
void AdjacencyList::CreateALGraph2(GraphAdjList* G) {
    edgeNode* e;
    //���붥����Ϣ�����������
    for (int i = 0; i < G->numVertexes; i++)
    {
        //���붥����Ϣ
        strcpy_s(G->adjList[i].data, _mapName[i]);
        //���߱���Ϊ�ձ�
        G->adjList[i].firstedge = NULL;
    }
    //�����߱���ͷ�巨��
    for (int i = 0; i < G->numVertexes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp;
            if (_distance2[i][j] != 0 || _distance2[j][i] != 0)
            {
                if (_distance2[i][j] != 0)
                {
                    temp = _distance2[i][j];
                    _distance2[j][i] = _distance2[i][j];
                }
                else
                {
                    temp = _distance2[j][i];
                    _distance2[i][j] = _distance2[j][i];
                }
                e = new EdgeNode;
                e->adjvex = j;
                e->next = G->adjList[i].firstedge;
                e->weight = temp;
                G->adjList[i].firstedge = e;

                e = new EdgeNode;
                e->adjvex = i;
                e->next = G->adjList[j].firstedge;
                e->weight = temp;
                G->adjList[j].firstedge = e;
            }

        }
    }
}

void AdjacencyList::ShowALGraph(GraphAdjList* G) {
    for (int i = 0; i < G->numVertexes; i++)
    {
        ui_all->textBrowser_2->append("地点:"+QString::number(i)+G->adjList[i].data+"--链表开始--");
        edgeNode* p = new edgeNode;
        p = G->adjList[i].firstedge;

        while (p)
        {
            ui_all->textBrowser_2->append(QString::number(p->adjvex)+"--权重: "+QString::number(p->weight)+"-->");
            p = p->next;
        }
        ui_all->textBrowser_2->append("当前地点结束");
        delete p;
    }

}

//��ʼ�����е�ͼ��������
void AdjacencyList::init_walking_map(GraphAdjList* G) {
    G->numVertexes = 51;
    G->numEdges = 83;
    _distance[0][1] = 32;
    _distance[0][2] = 65;
    _distance[2][3] = 59;
    _distance[2][4] = 103;
    _distance[2][8] = 69;
    _distance[2][5] = 195;
    _distance[2][9] = 218;
    _distance[5][6] = 22;
    _distance[5][7] = 56;
    _distance[5][9] = 174;
    _distance[6][7] = 44;
    _distance[7][11] = 180;
    _distance[9][10] = 221;
    _distance[9][12] = 307;
    _distance[9][36] = 322;
    _distance[10][11] = 156;
    _distance[10][35] = 336;
    _distance[10][36] = 400;
    _distance[11][12] = 70;
    _distance[11][16] = 160;
    _distance[11][35] = 480;
    _distance[12][13] = 99;
    _distance[13][14] = 98;
    _distance[13][15] = 53;
    _distance[13][16] = 109;
    _distance[13][19] = 350;
    _distance[13][20] = 64;
    _distance[14][15] = 70;
    _distance[14][20] = 56;
    _distance[15][18] = 224;
    _distance[16][31] = 300;
    _distance[16][17] = 328;
    _distance[17][18] = 205;
    _distance[17][23] = 206;
    _distance[17][31] = 227;
    _distance[18][19] = 177;
    _distance[19][21] = 233;
    _distance[19][23] = 300;
    _distance[21][22] = 66;
    _distance[21][23] = 280;
    _distance[21][50] = 187;
    _distance[23][24] = 85;
    _distance[24][25] = 179;
    _distance[24][29] = 242;
    _distance[24][31] = 466;
    _distance[24][50] = 284;
    _distance[26][49] = 230;
    _distance[26][27] = 67;
    _distance[27][28] = 61;
    _distance[27][30] = 170;
    _distance[28][43] = 201;
    _distance[29][30] = 179;
    _distance[30][32] = 169;
    _distance[30][42] = 197;
    _distance[30][43] = 217;
    _distance[31][32] = 202;
    _distance[31][33] = 167;
    _distance[31][35] = 104;
    _distance[32][33] = 204;
    _distance[32][42] = 127;
    _distance[33][34] = 299;
    _distance[33][35] = 86;
    _distance[33][41] = 228;
    _distance[34][36] = 375;
    _distance[34][37] = 131;
    _distance[34][40] = 153;
    _distance[34][41] = 186;
    _distance[35][36] = 449;
    _distance[36][37] = 354;
    _distance[36][38] = 225;
    _distance[37][39] = 49;
    _distance[37][40] = 207;
    _distance[38][39] = 93;
    _distance[39][40] = 243;
    _distance[40][41] = 249;
    _distance[40][43] = 494;
    _distance[40][45] = 125;
    _distance[41][42] = 74;
    _distance[43][46] = 284;
    _distance[43][48] = 442;
    _distance[44][45] = 64;
    _distance[44][46] = 255;
    _distance[46][48] = 448;
    _distance[47][48] = 131;
}

//��ʼ�����еĵ�ͼ����
void AdjacencyList::init_riding_map(GraphAdjList* G) {
    G->numVertexes = 51;
    G->numEdges = 83;
    _distance2[0][1] = 32;
    _distance2[0][2] = 65;
    _distance2[2][3] = 59;
    _distance2[2][4] = 103;
    _distance2[2][8] = 69;
    _distance2[2][5] = 195;
    _distance2[2][9] = 218;
    _distance2[5][6] = 22;
    _distance2[5][7] = 56;
    _distance2[5][9] = 174;
    _distance2[6][7] = 44;
    _distance2[7][11] = 180;
    _distance2[9][10] = 2000;
    _distance2[9][12] = 307;
    _distance2[9][36] = 322;
    _distance2[10][11] = 2000;
    _distance2[10][35] = 2000;
    _distance2[10][36] = 2000;
    _distance2[11][12] = 70;
    _distance2[11][16] = 160;
    _distance2[11][35] = 480;
    _distance2[12][13] = 99;
    _distance2[13][14] = 98;
    _distance2[13][15] = 53;
    _distance2[13][16] = 109;
    _distance2[13][19] = 350;
    _distance2[13][20] = 64;
    _distance2[14][15] = 70;
    _distance2[14][20] = 56;
    _distance2[15][18] = 224;
    _distance2[16][31] = 300;
    _distance2[16][17] = 328;
    _distance2[17][18] = 205;
    _distance2[17][23] = 206;
    _distance2[17][31] = 227;
    _distance2[18][19] = 177;
    _distance2[19][21] = 233;
    _distance2[19][23] = 300;
    _distance2[21][22] = 66;
    _distance2[21][23] = 280;
    _distance2[21][50] = 187;
    _distance2[23][24] = 85;
    _distance2[24][25] = 179;
    _distance2[24][29] = 242;
    _distance2[24][31] = 466;
    _distance2[24][50] = 284;
    _distance2[26][49] = 230;
    _distance2[26][27] = 67;
    _distance2[27][28] = 61;
    _distance2[27][30] = 170;
    _distance2[28][43] = 201;
    _distance2[29][30] = 179;
    _distance2[30][32] = 169;
    _distance2[30][42] = 197;
    _distance2[30][43] = 217;
    _distance2[31][32] = 202;
    _distance2[31][33] = 167;
    _distance2[31][35] = 104;
    _distance2[32][33] = 204;
    _distance2[32][42] = 127;
    _distance2[33][34] = 299;
    _distance2[33][35] = 86;
    _distance2[33][41] = 228;
    _distance2[34][36] = 375;
    _distance2[34][37] = 131;
    _distance2[34][40] = 153;
    _distance2[34][41] = 186;
    _distance2[35][36] = 449;
    _distance2[36][37] = 354;
    _distance2[36][38] = 225;
    _distance2[37][39] = 49;
    _distance2[37][40] = 207;
    _distance2[38][39] = 93;
    _distance2[39][40] = 243;
    _distance2[40][41] = 249;
    _distance2[40][43] = 494;
    _distance2[40][45] = 125;
    _distance2[41][42] = 74;
    _distance2[43][46] = 284;
    _distance2[43][48] = 442;
    _distance2[44][45] = 64;
    _distance2[44][46] = 255;
    _distance2[46][48] = 448;
    _distance2[47][48] = 131;
}
//���и��������㷨
void AdjacencyList::shortest_path_floyd_walking(GraphAdjList* G, int P[51][51], int D[51][51]) {
    //��ʼ��D��P
    for (int v = 0; v < G->numVertexes; ++v)
    {
        for (int w = 0; w < G->numVertexes; ++w)
        {
            if (_distance[v][w] == 0 && v != w) {
                _distance[v][w] = 10000;
            }
            D[v][w] = _distance[v][w];
            P[v][w] = w;
        }
    }
    for (int k = 0; k < G->numVertexes; ++k)
    {
        for (int v = 0; v < G->numVertexes; ++v)
        {
            for (int w = 0; w < G->numVertexes; ++w)
            {
                if (D[v][w] > D[v][k] + D[k][w])
                {
                    D[v][w] = D[v][k] + D[k][w];
                    P[v][w] = P[v][k];
                }
            }
        }
    }

}
//���и��������㷨
void AdjacencyList::shortest_path_floyd_riding(GraphAdjList* G, int P[51][51], int D[51][51]) {
    //��ʼ��D��P
    for (int v = 0; v < G->numVertexes; ++v)
    {
        for (int w = 0; w < G->numVertexes; ++w)
        {
            if (_distance2[v][w] == 0 && v != w) {
                _distance2[v][w] = 10000;
            }
            D[v][w] = _distance2[v][w];
            P[v][w] = w;
        }
    }
    for (int k = 0; k < G->numVertexes; ++k)
    {
        for (int v = 0; v < G->numVertexes; ++v)
        {
            for (int w = 0; w < G->numVertexes; ++w)
            {
                if (D[v][w] > D[v][k] + D[k][w])
                {
                    D[v][w] = D[v][k] + D[k][w];
                    P[v][w] = P[v][k];
                }
            }
        }
    }

}
//���н��
void AdjacencyList::ShowShortestResult(int originPos, int endPos) {
    int temp;
    ui_all->textBrowser->append("From place:");
    ui_all->textBrowser->append(_mapName[originPos]);
    ui_all->textBrowser->append("To place:");
    ui_all->textBrowser->append(_mapName[endPos]);
    ui_all->textBrowser->append("Shortest Distance:");
    ui_all->textBrowser->append(QString::number(ShortestPathvalue[originPos][endPos])+"m"+"差不多需要"+QString::number(ShortestPathvalue[originPos][endPos]/1.5)+"秒,"+"即"+QString::number(ShortestPathvalue[originPos][endPos]/1.5/60)+"分钟");
    temp = ShortestPathmatrix[originPos][endPos];
    QLineF lcc= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[temp]->x()+8,placelist[temp]->y()+10);
    linelist.append(lcc);
    dest = temp;
    ui_all->textBrowser->append(_mapName[originPos]);
    ui_all->textBrowser->append(QString::fromStdString("-->"));
    while (temp != endPos) {
        src = temp;//��������Դͷ
        ui_all->textBrowser->append(_mapName[temp]);
        ui_all->textBrowser->append("-->");
        temp = ShortestPathmatrix[temp][endPos];
        dest = temp;//�������߽�����
        QLineF ll= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[dest]->x()+8,placelist[dest]->y()+10);
        linelist.append(ll);
    }
    dest = temp;
    QLineF laa= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[dest]->x()+8,placelist[dest]->y()+10);
    linelist.append(laa);
    ui_wind->paintEvent(nullptr);
    ui_all->textBrowser->append(_mapName[endPos]);
}
//���н��
void AdjacencyList::ShowShortestResult2(int originPos, int endPos) {
    int temp;

    ui_all->textBrowser2->append("From place:");
    ui_all->textBrowser2->append(_mapName[originPos]);
    ui_all->textBrowser2->append("To place:");
    ui_all->textBrowser2->append(_mapName[endPos]);
    ui_all->textBrowser2->append("Shortest Distance:");
    ui_all->textBrowser2->append(QString::number(ShortestPathvalue[originPos][endPos])+"m"+"差不多需要"+QString::number(ShortestPathvalue[originPos][endPos]/5)+"秒,"+"即"+QString::number(ShortestPathvalue[originPos][endPos]/5/60)+"分钟");

    temp = ShortestPathmatrix[originPos][endPos];
    QLineF lcc= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[temp]->x()+8,placelist[temp]->y()+10);
    linelist.append(lcc);
    dest = temp;
    ui_all->textBrowser2->append(_mapName[originPos]);
    ui_all->textBrowser2->append(QString::fromStdString("-->"));
    while (temp != endPos) {
        src = temp;//��������Դͷ
        ui_all->textBrowser2->append(_mapName[temp]);
        ui_all->textBrowser2->append("-->");
        temp = ShortestPathmatrix[temp][endPos];
        dest = temp;//���ý���
        QLineF ll= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[dest]->x()+8,placelist[dest]->y()+10);
        linelist.append(ll);
    }
    dest = temp;
    QLineF laa= QLineF(placelist[src]->x()+8,placelist[src]->y()+10,placelist[dest]->x()+8,placelist[dest]->y()+10);
    linelist.append(laa);
    ui_wind->paintEvent(nullptr);
    ui_all->textBrowser2->append(_mapName[endPos]);
}
