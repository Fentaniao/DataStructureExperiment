/*7.3  散列查找算法的实现
【实验目的】
1.掌握如何通过散列函数构建散列表
2.了解散列函数的选择方法及冲突解决的常用方法
3. 能根据关键码，用同样的散列函数和冲突处理方法来进行查找
【实验内容】
已知散列函数为H(key)=key%p（p为自定的常数），冲突处理方法为线性探测再散列或链地址法，构造散列表
【实验要点及说明】
注意散列表时相同元素的处理。
*/

//自有库
#include "PowerTrace.h"

//库
#include <iostream>


using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

const int MAXINT = 32767;

typedef int status;
typedef int keyType;
typedef int infoType;
typedef int elemType;

typedef struct LNode {
    elemType data;
    struct LNode *next;
} LNode, *LinkList;

//初始化
status initList(LinkList &L) {
    L = new LNode;
    L->next = nullptr;
    return OK;
}

//最前面添加元素
status addAhead(LinkList &L, elemType input) {
    LNode *p = L;
    LNode *q;

    q = new LNode;
    q->data = input;
    q->next = p->next;
    p->next = q;

    return OK;
}

//输出表
status outputList(LinkList &L) {
    LNode *p = L;

    while (p->next) {
        p = p->next;
        cout << p->data << " ";
    }
    return OK;
}


//获取表长
status length(LinkList &L) {
    LNode *p = L;
    int len = 0;

    while (p->next) {
        p = p->next;
        len = len + 1;
    }
    return len;
}


//插入操作，在第i个元素前插入一个元素
status insertElem(LinkList &L, int i, elemType x) {
    LNode *p = L;
    LNode *q;
    int j = 1;


    if (i < 1 || length(L) < i)
        return ERROR;
    while (j < i) {
        p = p->next;
        j++;
    }

    q = new LNode;
    q->data = x;
    q->next = p->next;
    p->next = q;

    return OK;
}


//删除操作，删除表中第i个元素
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

class hashTable {
public:
    int p;
    LinkList handPoints[MAXSIZE]{};
public:
    explicit hashTable(int p) {
        hashTable::p = p;
        for (int i = 0; i < p; ++i) {
            initList(handPoints[i]);
        }
    }

    void addElem(keyType key);

    void outHashTable();

    void outputFunction() const;
};

void hashTable::addElem(keyType key) {
    int index;
    index = key % p;
    addAhead(handPoints[index], key);

}

void hashTable::outHashTable() {
    int i;
    for (i = 0; i < p; ++i) {
        cout << "Address " << i << ": ";
        outputList(handPoints[i]);
        cout << endl;

    }
}

void hashTable::outputFunction() const {
    cout << "H(key) = key % " << p;
}


int main() {
    int p;
    cout << ">> Enter the parameter p: ";
    cin >> p;
    hashTable hT(p);

    //trace(hT.handPoints);

    //从键盘输入key
    keyType key;
    cout << ">> Enter the keys: ";
    while (cin >> key) {
        //trace(key,{},"输入");
        hT.addElem(key);
    }

    //Print hash function
    cout << "<< Print the hash function: " << endl;
    hT.outputFunction();
    cout << endl;

    //Print hash table
    cout << "<< Print the hash table: " << endl;
    hT.outHashTable();


    return 0;
}


/**
测试数据
13
19 14 23 1 68 20 84 27 55 11 10 79 k
 */