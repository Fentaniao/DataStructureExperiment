/*
5.2 二叉树的高度、叶子结点数、总的结点数等算法的实现。
【实验目的】
了解二叉树遍历的概念，掌握二叉树遍历算法的简单应用
 【实验内容】
在上述5.1实现构建的二叉树基础上，完成二叉树遍历算法的简单应用 ，如求二叉树高度、叶子结点数、总的结点数等简单算法的实现。可用遍历算法也可用非遍历算法来实现。
 */



#include <iostream>

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

//中序遍历求二叉树高度
int inOrderHeight(biTree &T) {
    int l, r;
    if (T) {
        l = inOrderHeight(T->lChild);
        r = inOrderHeight(T->rChild);
    } else
        return 0;
    return l > r ? l + 1 : r + 1;
}

//中序遍历求叶子结点数
int inOrderLeaves(biTree &T) {
    static int i = 0;
    if (T) {
        inOrderLeaves(T->lChild);
        if ((T->lChild == nullptr) && (T->rChild == nullptr))
            i++;
        inOrderLeaves(T->rChild);
    }
    return i;
}

//中序遍历求总的结点数
int inOrderNodes(biTree &T) {
    static int i = 0;
    if (T) {
        inOrderNodes(T->lChild);
        i++;
        inOrderNodes(T->rChild);
    }
    return i;
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


    cout << "二叉树高度：" << inOrderHeight(T) << endl;

    cout << "叶子结点数：" << inOrderLeaves(T) << endl;

    cout << "总的结点数：" << inOrderNodes(T) << endl;
}

//ABC##DE#G##F###