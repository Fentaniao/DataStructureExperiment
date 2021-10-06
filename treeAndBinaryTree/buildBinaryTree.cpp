/*
 5.1以二叉链表方式建立二叉树，并输出结点的值。
【实验目的】
了解二叉树的结构特点及有关概念，掌握二叉树建立的基本算法
        了解二叉树遍历的概念，掌握遍历二叉树的算法
【实验内容】
按某种次序依次输入元素值，以二叉链表方式建立该二叉树，然后可依据先序、中序、后序中的任一种遍历方法遍历二叉树的方式输出结点的值。
【实验要点及说明】
对二叉树的不同定义可得不同的建二叉链表的算法。为简化问题，设二叉树中结点的元素均为一个单字符，并以"#"表示空树。假设二叉树以由"根"、"左子树串"和"右子树串" 联接而成的字符串表示，则建立二叉链表的算法应该是一个"先序遍历"的过程，并且遍历过程中"访问"的操作应是"识别输入的字符并作相应操作"。
【测试数据】
教材P121 图5.10所示二叉树，读入字符的顺序为：ABC##DE#G##F###（按先序构建）
 */



#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>


using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFOLOW = -2;
const int MAXSIZE = 100;

typedef int status;
typedef string elemType;

typedef struct biTNode {
    elemType data;
    biTNode *lChild{}, *rChild{};
} biTNode, *biTree;


//生成二叉树
status createBiTree(biTree &T) {
    char ch;
    cin >> ch;
    if (ch == '#')
        T = nullptr;
    else {
        T = new biTNode;
        T->data = ch;
        createBiTree(T->lChild);
        createBiTree(T->rChild);
    }
    return OK;
}

//先序遍历输出结点的值
status preOrderTraverse(biTree &T) {
    if (T) {
        cout << T->data;
        preOrderTraverse(T->lChild);
        preOrderTraverse(T->rChild);
    }
    return OK;
}

//中序遍历输出结点的值
status inOrderTraverse(biTree &T) {
    if (T) {
        inOrderTraverse(T->lChild);
        cout << T->data;
        inOrderTraverse(T->rChild);
    }
    return OK;
}

//后序遍历输出结点的值
status postOrderTraverse(biTree &T) {
    if (T) {
        postOrderTraverse(T->lChild);
        postOrderTraverse(T->rChild);
        cout << T->data;
    }
    return OK;
}


int main() {
    biTree T;

    cout << "读入字符：" << endl;
    createBiTree(T);

    cout << "先序遍历输出结点的值：";
    preOrderTraverse(T);
    cout << endl;

    cout << "中序遍历输出结点的值：";
    inOrderTraverse(T);
    cout << endl;

    cout << "后序遍历输出结点的值：";
    postOrderTraverse(T);
    cout << endl;
}

//ABC##DE#G##F###