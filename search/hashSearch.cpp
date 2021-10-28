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
#include <sstream>

using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

typedef int keyType;
typedef int elemType;

class LNode {
public:
    elemType data{};
    LNode *next;
public:
    LNode() {
        next = nullptr;
    }

    explicit LNode(elemType input) {
        data = input;
        next = nullptr;
    }
};

class LinkList {
public:
    LNode *head;
public:
    void addAhead(elemType input);

    void outputList();

    int length();
};


//最前面添加元素
void LinkList::addAhead(elemType input) {
    LNode *p = new LNode(input);
    if (head == nullptr) {
        head = p;
        head->next = nullptr;
    } else {
        p->next = head->next;
        head->next = p;
    }
}

//输出表
void LinkList::outputList() {
    LNode *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
}


//获取表长
int LinkList::length() {
    LNode *p = head;
    int len = 0;

    while (p) {
        len = len + 1;
        p = p->next;
    }
    return len;
}

class hashTable {
public:
    int p;
    LinkList handPoints[MAXSIZE]{};
public:
    explicit hashTable(int p) {
        hashTable::p = p;
    }

    void addElem(keyType key);

    void outHashTable();

    void outputFunction() const;
};

void hashTable::addElem(keyType key) {
    int index;
    index = key % p;
    handPoints[index].addAhead(key);
}

void hashTable::outHashTable() {
    int i;
    for (i = 0; i < p; ++i) {
        cout << "Address " << i << ": ";
        handPoints[i].outputList();
        cout << endl;
    }
}

void hashTable::outputFunction() const {
    cout << "H(key) = key % " << p;
}


int mainFunction(const string &testString) {
    stringstream cin(testString);

    //Enter the parameter p from keyboard
    int p;
    cout << ">> Enter the parameter p: ";
    cin >> p;
    hashTable hT(p);

    //Enter keys from keyboard
    keyType key;
    cout << ">> Enter the keys: ";
    while (cin >> key) {
        hT.addElem(key);
    }

    //Print hash function
    cout << "<< Print hash function: " << endl;
    hT.outputFunction();
    cout << endl;

    //Print hash table
    cout << "<< Print hash table: " << endl;
    hT.outHashTable();

    return 0;
}

#include "gtest/gtest.h"

TEST(test, c1) {
    EXPECT_EQ(0, mainFunction("13\n19 14 23 1 68 20 84 27 55 11 10 79 k"));
}

TEST(test, c2) {
    EXPECT_EQ(0, mainFunction("3\n1 2 3 4 5 6 7 8 9 10 11 12 13 k"));
}

TEST(test, c3) {
    EXPECT_EQ(0, mainFunction("3\n1 2 3 4 5 6 7 8 9 10 11 12 13 k"));
}


//重定向方法
//streambuf *buffer = cin.rdbuf(); //old buffer, STDOUT的缓冲区
//stringstream cin(testString); //覆盖cin，使之重定向到字符串testString
//cin.rdbuf(buffer); // 重置，重新载入STDOUT的缓冲区

/**
测试数据
13
19 14 23 1 68 20 84 27 55 11 10 79 k
 */