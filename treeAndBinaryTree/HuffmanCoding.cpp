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

using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFOLOW = -2;
const int MAXSIZE = 100;

typedef int status;
typedef float elemType;

//二叉树类
typedef struct biTNode {
    elemType weight;
    biTNode *parent, *lChild, *rChild;
} biTNode, *biTree;

typedef biTNode linkListElemType;

//链表类
typedef struct LNode {
    linkListElemType *data;
    struct LNode *next;
} LNode, *LinkList;

//初始化链表
status initList(LinkList &L) {
    L = new LNode;
    L->next = nullptr;
    return OK;
}

//在链表的末尾添加元素
status append(LinkList &L, linkListElemType *input) {
    LNode *p = L;

    while (p->next)
        p = p->next;

    LNode *q;
    q = new LNode;
    q->data = input;
    q->next = nullptr;

    p->next = q;
    return OK;
}

//获取链表的表长
status length(LinkList &L) {
    LNode *p = L;
    int len = 0;

    while (p->next) {
        p = p->next;
        len = len + 1;
    }
    return len;
}

//链表的删除操作，删除表中第i个元素
status deleteElem(LinkList &L, int i) {
    LNode *p = L;
    int j = 1;


    if (i < 1 || length(L) < i)
        return ERROR;
    while (j < i) {
        p = p->next;
        j++;
    }

    p->next = p->next->next;

    return OK;
}

//生成哈夫曼树
void createBiTree(int &set_size, LinkList &L) {
    int i;
    LNode *p;
    float min1, min2;
    int index_min1, index_min2;
    biTNode *t, *t1, *t2;

    while (length(L) > 1) {
//        查找链表中最小值的下标
        p = L->next;
        min1 = min2 = 999;
        index_min1 = index_min2 = 0;
        t1 = t2 = p->data;

        for (i = 0; i < length(L); i++) {

            if (p->data->weight < min1) {
                min1 = p->data->weight;
                index_min1 = i;
                t1 = p->data;
            }
            p = p->next;
        }
//        查找链表中次小值的下标
        p = L->next;
        for (i = 0; i < length(L); i++) {

            if ((p->data->weight < min2) && (i != index_min1)) {
                min2 = p->data->weight;
                index_min2 = i;
                t2 = p->data;
            }
            p = p->next;
        }

//        组成新结点
        t = new biTNode;
        t->weight = min1 + min2;
        t->parent = nullptr;
        t->lChild = t2;
        t->rChild = t1;
        t2->parent = t;
        t1->parent = t;

//        从链表中移除两个用过的结点
        deleteElem(L, index_min2 + 1);
        deleteElem(L, index_min1 + 1);

//        添加新结点到链表的末尾
        append(L, t);
    }
}

//求某个结点的哈夫曼编码
string singleHuffmanCoding(biTNode *T) {
    string code;
    while (T->parent) {
        if (T->parent->lChild == T)
            code += "0";
        else
            code += "1";
        T = T->parent;
    }
    reverse(code.begin(), code.end());
    return code;
}

int main() {
    int i;
    int set_size;

    cout << "读入字符集大小：";
    cin >> set_size;

    string arrayChar;
    biTNode *arrayBiTNode[set_size];
    string arrayCode[set_size];
    LinkList L;
    initList(L);

    cout << "读入字符集：";
    cin >> arrayChar;

//    读入权值构建结点
    cout << "读入权值：";
    for (i = 0; i < set_size; i++) {
        biTNode *t;
        t = new biTNode;
        cin >> t->weight;
        t->parent = t->lChild = t->rChild = nullptr;
        arrayBiTNode[i] = t;
        append(L, t);
    }

    cout << "正在建立哈夫曼树" << endl;
    createBiTree(set_size, L);
    cout << "哈夫曼树创建成功！" << endl;

    cout << "正在建立编码" << endl;
    for (i = 0; i < set_size; i++) {
        arrayCode[i] = singleHuffmanCoding(arrayBiTNode[i]);
    }

    for (i = 0; i < set_size; i++) {
        cout << arrayChar[i] << " " << arrayCode[i] << endl;
    }
    cout << "编码创建成功！" << endl;

    cout << "读入报文：";
    string telegraph;
    cin >> telegraph;

    cout << "输出编码：";
    for (i = 0; i < telegraph.length(); i++) {
        auto index = arrayChar.find(telegraph[i]);
        if (index != string::npos)
            cout << arrayCode[index];
        else
            cout << telegraph[i];
    }
}
// 5
// CAST;
// 2 4 2 3 3
// CAST;CA;SAT;AT
// 00101000111000101100000111100111
