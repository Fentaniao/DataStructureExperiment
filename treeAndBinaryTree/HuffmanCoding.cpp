/*
5.3 综合设计----哈夫曼编码    //也可作为最后一次的综合设计型实验
【实验目的】
了解哈夫曼树的结构特点及有关概念，掌握哈夫曼树的建立和哈夫曼编码的设计
【问题描述】
使用二叉树进行哈夫曼编码的设计，要求对输入的一串电文字符实现哈夫曼编码，再对哈夫编码生成的代码串进行译码，输出电文字符串
【实验功能】
1、哈夫曼树的建立   从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树
2、	哈夫曼编码的生成  利用以建好的哈夫曼树，规定左分支为0，右分支为1，则从根结点到每个叶子结点所经过的分支对应的0和1组成的序列便为该结点对应字符的哈夫曼编码
【设计思想】
设计步骤1)
1、从没有父结点的结点集合中，找出2个权值最小的结点，求和后存放到新的链表单元中，并将找到的最小2个权值的结点的父结点地址指向新生成的结点。
2、重复步骤（1），直至循环完成。
3、从叶子结点遍历父结点，并记录遍历路径（当前结点为父结点的左儿子记为0，否则记为1），然后对遍历路径进行倒置处理，便得到该结点的哈夫曼编码。
4、重复步骤（3），直至完成全部叶子结点的哈夫曼编码。
 【测试数据】
用下表给出的字符集和频度的实际统计数据建立哈夫曼树，并实现以下报文的编码和译码：“CAS；CAT；SAT；AT”
字符	C	A	S	T	;
频度	2	4	2	3	3

*/


#include <iostream>
#include <algorithm>

const int INT_M = 214497;

using namespace std;

static string arrayCode[5];

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFOLOW = -2;
const int MAXSIZE = 100;

typedef int status;
typedef int elemType;

typedef struct biTNode {
    elemType weight;
    biTNode *parent, *lChild, *rChild;
} biTNode, *biTree;


//生成二叉树
biTNode *createBiTree(int &set_size, int *arrayWeight, biTNode **arrayBiTNode) {
    int i, j;
    int index_min1;
    int index_min2;
    bool flag = true;
    int temp;

    while (flag) {
//        找
        index_min1 = int(min_element(arrayWeight + 0, arrayWeight + set_size) - arrayWeight);
        temp = arrayWeight[index_min1];
        arrayWeight[index_min1] = INT_M;
        index_min2 = int(min_element(arrayWeight + 0, arrayWeight + set_size) - arrayWeight);
        arrayWeight[index_min1] = temp;

//组
        biTNode *t, *temp_t;

        arrayWeight[index_min1] = arrayWeight[index_min1] + arrayWeight[index_min2];
        t = new biTNode;
        t->weight = arrayWeight[index_min1];

        temp_t = new biTNode;
        temp_t->weight = arrayBiTNode[index_min1]->weight;
        temp_t->parent = arrayBiTNode[index_min1]->parent;
        temp_t->lChild = arrayBiTNode[index_min1]->lChild;
        temp_t->rChild = arrayBiTNode[index_min1]->rChild;
        t->lChild = temp_t;
        temp_t->parent = t;

        temp_t = new biTNode;
        temp_t->weight = arrayBiTNode[index_min2]->weight;
        temp_t->parent = arrayBiTNode[index_min2]->parent;
        temp_t->lChild = arrayBiTNode[index_min2]->lChild;
        temp_t->rChild = arrayBiTNode[index_min2]->rChild;
        t->rChild = temp_t;
        temp_t->parent = t;

        arrayBiTNode[index_min1] = t;

//        删
        arrayWeight[index_min2] = INT_M;

        for (i = 0; i < set_size; i++) {
            cout << arrayWeight[i] << " ";
        }
        cout << endl;

        for (i = j = 0; i < set_size; i++)
            if (arrayWeight[i] == INT_M)
                j++;

        if (j == set_size - 1)
            flag = false;

    }

    for (i = 0; i < set_size; i++)
        if (arrayWeight[i] != INT_M)
            return arrayBiTNode[i];
}


//求某个结点的哈夫曼编码
string singleHuffmanCoding(biTNode *T) {
    static string code;
    if (T->parent) {
        if (T->parent->lChild == T)
            code += '0';
        else
            code += '1';
        singleHuffmanCoding(T->parent);
    }
    return code;
}


//求查找子结点进行编码
status inOrderTraverse(biTree &T) {
    static int i = 0;
    if (T) {
        if (!((T->lChild) || (T->rChild))) {
            arrayCode[i] = singleHuffmanCoding(T);
//            cout << i << ":" << arrayCode[i] << endl;
            reverse(arrayCode[i].begin(), arrayCode[i].end());
            i++;
        } else {
            inOrderTraverse(T->lChild);
            inOrderTraverse(T->rChild);
        }
    }
    return OK;
}

int main() {
    biTree T;
    int i;
    int set_size;

    cout << "读入字符集大小：";
    cin >> set_size;

    string arrayChar;
    int arrayWeight[set_size];
    biTNode *arrayBiTNode[set_size];

    cout << "读入字符集：";
    cin >> arrayChar;

    cout << "读入权值：";
    for (i = 0; i < set_size; i++)
        cin >> arrayWeight[i];

    for (i = 0; i < set_size; i++) {
        biTNode *t;
        t = new biTNode;
        t->weight = arrayWeight[i];
        t->parent = t->lChild = t->rChild = nullptr;
        arrayBiTNode[i] = t;
    }

    cout << "正在建立哈夫曼树" << endl;
    T = createBiTree(set_size, arrayWeight, arrayBiTNode);
    cout << "创建成功！" << endl;

    cout << "正在建立编码" << endl;
    inOrderTraverse(T);
    cout << "创建成功！" << endl;

    cout << "读入报文：";
    string telegraph;
    cin >> telegraph;

    cout << "输出编码：";
    string newTelegraph;
    for (i = 0; i < telegraph.length(); i++) {
        auto index = arrayChar.find(telegraph[i]);
        if (index != string::npos) {
            newTelegraph += arrayCode[index];
        }
    }

    cout << newTelegraph<<endl;
//    cout <<"11010111001101001001111001001001"<<endl;
}