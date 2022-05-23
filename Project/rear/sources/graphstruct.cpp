#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphstruct.h"
#include <QDebug>
using namespace std;
extern place * placelist[52];
extern MainWindow *ui_wind;
extern place *A;
extern place *B;
int src;
int dest;
extern QList <QLineF> linelist;
//extern Ui::MainWindow* ui_all;
//创建步行地图
void AdjacencyList::CreateALGraph(GraphAdjList* G) {
    edgeNode* e;
    //读入顶点信息，建立顶点表
    for (int i = 0; i < G->numVertexes; i++)
    {
        //读入顶点信息
        strcpy_s(G->adjList[i].data, _mapName[i]);
        //将边表置为空表
        G->adjList[i].firstedge = NULL;
    }
    //建立边表（头插法）
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

//创建骑行地图
void AdjacencyList::CreateALGraph2(GraphAdjList* G) {
	edgeNode* e;
	//读入顶点信息，建立顶点表
	for (int i = 0; i < G->numVertexes; i++)
	{
		//读入顶点信息
		strcpy_s(G->adjList[i].data, _mapName[i]);
		//将边表置为空表
		G->adjList[i].firstedge = NULL;
	}
	//建立边表（头插法）
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
		cout << "顶点" << i << ": " << G->adjList[i].data << "--firstedge--";
		edgeNode* p = new edgeNode;
		p = G->adjList[i].firstedge;
		while (p)
		{
			cout << p->adjvex << "--Weight: " << p->weight << "--Next--";
			p = p->next;
		}
		cout << "--NULL" << endl;
	}

}

//初始化步行地图基本数据
void AdjacencyList::InitMap(GraphAdjList* G) {
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

//初始化骑行的地图数据
void AdjacencyList::InitMap1(GraphAdjList* G) {
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
//步行弗洛伊德算法
void AdjacencyList::ShortestPath_Floyd(GraphAdjList* G, int P[51][51], int D[51][51]) {
	//初始化D与P
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
//骑行弗洛伊德算法
void AdjacencyList::ShortestPath_Floyd2(GraphAdjList* G, int P[51][51], int D[51][51]) {
	//初始化D与P
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
//步行结果
void AdjacencyList::ShowShortestResult(int originPos, int endPos) {
    int temp;

    ui_all->textBrowser->append("From place:");
    ui_all->textBrowser->append(_mapName[originPos]);
    ui_all->textBrowser->append("To place:");
    ui_all->textBrowser->append(_mapName[endPos]);
    ui_all->textBrowser->append("Shortest Distance:");
    ui_all->textBrowser->append(QString::number(ShortestPathvalue[originPos][endPos]));

    temp = ShortestPathmatrix[originPos][endPos];
    //src = temp;
    QLineF lcc= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[temp]->x(),placelist[temp]->y());
    linelist.append(lcc);
    //temp = ShortestPathmatrix[temp][endPos];
    //temp = ShortestPathmatrix[temp][endPos];
    dest = temp;
//    QLineF lbb= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
//    linelist.append(lbb);
    ui_all->textBrowser->append(_mapName[originPos]);
    ui_all->textBrowser->append(QString::fromStdString("-->"));
    while (temp != endPos) {
        src = temp;//设置连线源头
        ui_all->textBrowser->append(_mapName[temp]);
        ui_all->textBrowser->append("-->");
        //ui_all->textBrowser->append(QString::fromStdString("135"));
        temp = ShortestPathmatrix[temp][endPos];
        dest = temp;//设置结束
        //QLineF l;
        QLineF ll= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
        linelist.append(ll);
//        A = placelist[src];
//        B = placelist[dest];
        //ui_wind->draw_line(placelist[src],placelist[dest]);

    }
    dest = temp;
    QLineF laa= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
    linelist.append(laa);
    ui_wind->paintEvent(nullptr);
    ui_all->textBrowser->append(_mapName[endPos]);
}
//骑行结果
void AdjacencyList::ShowShortestResult2(int originPos, int endPos) {
    int temp;

    ui_all->textBrowser2->append("From place:");
    ui_all->textBrowser2->append(_mapName[originPos]);
    ui_all->textBrowser2->append("To place:");
    ui_all->textBrowser2->append(_mapName[endPos]);
    ui_all->textBrowser2->append("Shortest Distance:");
    ui_all->textBrowser2->append(QString::number(ShortestPathvalue[originPos][endPos]));

    temp = ShortestPathmatrix[originPos][endPos];
    //src = temp;
    QLineF lcc= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[temp]->x(),placelist[temp]->y());
    linelist.append(lcc);
    //temp = ShortestPathmatrix[temp][endPos];
    //temp = ShortestPathmatrix[temp][endPos];
    dest = temp;
//    QLineF lbb= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
//    linelist.append(lbb);
    ui_all->textBrowser2->append(_mapName[originPos]);
    ui_all->textBrowser2->append(QString::fromStdString("-->"));
    while (temp != endPos) {
        src = temp;//设置连线源头
        ui_all->textBrowser2->append(_mapName[temp]);
        ui_all->textBrowser2->append("-->");
        //ui_all->textBrowser->append(QString::fromStdString("135"));
        temp = ShortestPathmatrix[temp][endPos];
        dest = temp;//设置结束
        //QLineF l;
        QLineF ll= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
        linelist.append(ll);
//        A = placelist[src];
//        B = placelist[dest];
        //ui_wind->draw_line(placelist[src],placelist[dest]);

    }
    dest = temp;
    QLineF laa= QLineF(placelist[src]->x(),placelist[src]->y(),placelist[dest]->x(),placelist[dest]->y());
    linelist.append(laa);
    ui_wind->paintEvent(nullptr);
    ui_all->textBrowser2->append(_mapName[endPos]);
}

//int main() {
//	int moshi = 0;
//	AdjacencyList adjacencyList;
//	AdjacencyList adjacencyList2;
//	int originPos, endPos;

//	while (1) {
//		cout << "请选择步行模式或骑行模式（输入0为步行，输入1为骑行）" << endl;
//		cin >> moshi;
//		if (moshi == 0) {
//			cout << "当前为步行模式"<< endl;
//			GraphAdjList* GA = new GraphAdjList;
//			adjacencyList.InitMap(GA);
//			adjacencyList.CreateALGraph(GA);
//			adjacencyList.ShortestPath_Floyd(GA, ShortestPathmatrix, ShortestPathvalue);
//			cout << "请选择图片上想去的地方，关闭图片后输入起点和终点的序号，以空格间隔。" << endl;
//			cout << "例如 ：关闭图片 0 1 ,回车。即可显示路径" << endl;
//			cin >> originPos >> endPos;
//			adjacencyList.ShowShortestResult(originPos, endPos);
//			cout << "   " << endl;
//			delete GA;
//		}
//		else
//		{
//			cout << "当前为骑行模式"<<endl;
//			GraphAdjList* GB = new GraphAdjList;
//			adjacencyList2.InitMap1(GB);
//			adjacencyList2.CreateALGraph2(GB);;
//			adjacencyList2.ShortestPath_Floyd2(GB, ShortestPathmatrix2, ShortestPathvalue2);
//			cout << "请选择图片上想去的地方，关闭图片后输入起点和终点的序号，以空格间隔。" << endl;
//			cout << "例如 ：关闭图片 0 1 ,回车。即可显示路径" << endl;
//			system("mspaint SchoolMap.png");
//			cin >> originPos >> endPos;
//			adjacencyList2.ShowShortestResult2(originPos, endPos);
//			cout << "   " << endl;
//			delete GB;
//		}
//	}

//	return 0;
//}
