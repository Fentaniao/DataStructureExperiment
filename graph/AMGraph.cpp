/*6.1 无（有）向图的邻接矩阵和邻接表表示及遍历
【实验目的】
掌握图的邻接矩阵和邻接表表示方法及实现技术
        掌握在图的邻接矩阵和邻接表表示方式下的图的遍历操作
【实验内容】
从键盘输入无（有）向图G的顶点个数v、边的个数e。建立由v个顶点、e条边构成的无（有）向图G，采用邻接矩阵或邻接表表示。V个顶点的值由键盘输入，元素类型为字符型，e条边的信息亦由键盘输入
        调用图的深度优先搜索遍历图或广度优先搜索遍历图算法，并输出相应的遍历序列
【测试数据】
以教材P149 图G1或图G2进行测试，注意顶点若设为字符型，输入时V1,V2…可改为a b ……
【实验要点及说明】
注意：对于给定的图，由于输入顶点或边的顺序不同，可以造成对应的邻接表结构不唯一。另外，对给定图按DFS遍历的结果亦不唯一。
以上能实现一个即可，建议邻接矩阵和邻接表都完成*/


//#include "PowerTrace.h"
#include <iostream>

using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

const int MAXINT = 32767;

typedef int Status;
typedef char VerTexType;
typedef double ArcType;

typedef struct AMGraph {
    VerTexType vexes[MAXSIZE]{};
    ArcType arcs[MAXSIZE][MAXSIZE]{};
    int vexNum{}, arcNum{};
} AMGraph;

int locateIndex(const VerTexType *arr, VerTexType &elem, int MaxIndex) {
    int j;
    for (j = 0; j < MaxIndex; j++) {
        if (arr[j] == elem)
            return j;
    }
}

Status buildAMGraph(AMGraph &G) {
    int i, j;

    int indexV1, indexV2;

    double weight;
    VerTexType v1, v2;

    cout << ">> Please input total vexes: ";
    cin >> G.vexNum;
    cout << ">> Please input total arcs: ";
    cin >> G.arcNum;

    cout << ">> Please input data of every vexes: ";
    for (i = 0; i < G.vexNum; ++i) {
        cin >> G.vexes[i];
    }

    //    初始化邻接矩阵
    for (i = 0; i < G.vexNum; ++i)
        for (j = 0; j < G.vexNum; ++j)
            G.arcs[i][j] = MAXINT;

    //for循环输入权重，节点1和节点2
    cout << ">> Please input weight between one vex and another: ";
    for (i = 0; i < G.arcNum; i++) {
        cin >> weight >> v1 >> v2;

        indexV1 = locateIndex(G.vexes, v1, G.vexNum);
        indexV2 = locateIndex(G.vexes, v2, G.vexNum);

        G.arcs[indexV1][indexV2] = weight;
        G.arcs[indexV2][indexV1] = weight;


    }


    return OK;
}

Status printAMGraph(AMGraph &G) {
    int i, j;

    cout << "Print AMGraph: " << endl;
    cout << "G  ";
    for (i = 0; i < G.vexNum; ++i) {
        cout << G.vexes[i] << "  ";
    }
    cout << endl;

    for (i = 0; i < G.vexNum; ++i) {
        cout << G.vexes[i] << "  ";
        for (j = 0; j < G.vexNum; ++j) {
            if (G.arcs[i][j] == MAXINT)
                cout << 0 << "  ";
            else
                cout << G.arcs[i][j] << "  ";
        }
        cout << endl;
    }

    return OK;
}


static int visited[10];


Status DFS(AMGraph &G, int index) {
    int i;
    visited[index] = 1;
    cout << G.vexes[index] << " ";
    for (i = 0; i < G.vexNum; i++)
        if (!visited[i])
            if (G.arcs[index][i] != MAXINT)
                DFS(G, i);

    return OK;
}

int main() {
    AMGraph G;
    int i;

    buildAMGraph(G);

    printAMGraph(G);

    cout << "DFS" << endl;
    for (i = 0; i < G.vexNum; i++)
        if (!visited[i]) {
            //traceArr(visited, { i });
            cout << "连通分量: ";
            DFS(G, i);
            cout << endl;
        }


    return 0;
}