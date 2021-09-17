/*
1．图书信息管理 （参考教材案例2.3相关资料）
利用链表实现一个图书信息管理，包括数据输入、查找、插入、删除等  [或设计一个班级学生信息管理]
实验目的：
1、掌握线性表的定义；
2、掌握线性表的基本操作，如建立、查找、插入和删除等，提高综合设计能力。
实验内容：
定义一个包含图书信息（图书号，图书名，价格）的单链表，使其具有如下功能：
(1) 根据指定图书个数，逐个输入图书信息；
(2) 逐个显示图书表中所有图书的相关信息；
(3) 根据书名进行查找，返回此图书信息；
(4) 根据指定的位置可返回相应的图书信息；
(5) 给定一个图书信息，插入到表中指定的位置；
(6) 删除指定位置的图书记录；
 */


#include "iostream"
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

typedef struct lNode {
    int bookNumber;
    string bookName;
    double bookPrice;
    struct lNode *next;
} lNode, *LinkList;

//初始化
status initList(LinkList &L) {
    L = new lNode;
    L->next = nullptr;
    return OK;
}


//通过键盘流添加表数据
status creatList(LinkList &L) {
    int number;
    string name;
    double price;
    lNode *p = L;
    lNode *q;

    while (p->next) {
        p = p->next;
    }

    while (true) {
        cout << "请输入图书号（输入-1终止输入）：";
        cin >> number;
        if (number == -1)
            break;
        cout << "请输入图书名：";
        cin >> name;
        cout << "请输入价格：";
        cin >> price;

        q = new lNode;
        q->bookNumber = number;
        q->bookName = name;
        q->bookPrice = price;
        q->next = nullptr;

        p->next = q;
        p = p->next;

    }
    return OK;
}


//输出单条数据
status outputSingle(lNode *p) {
    cout << "图书号:" << p->bookNumber << "，图书名:" << p->bookName << "，价格:" << p->bookPrice << endl;
    return OK;
}


//输出表
status outputList(LinkList &L) {
    lNode *p = L;

    while (p->next) {
        p = p->next;
        outputSingle(p);
    }
    return OK;
}


//获取表长
status length(LinkList &L) {
    lNode *p = L;
    int len = 0;

    while (p->next) {
        p = p->next;
        len = len + 1;
    }
    return len;
}


//根据书名进行查找，查找书名为name的元素，返回此图书信息
status searchElem(LinkList &L, string name) {
    lNode *p = L;
    while (p) {
        if (p->bookName == name)
            break;
        p = p->next;
    }
    if (!p)
        return ERROR;
    else {
        outputSingle(p);
    }
    return OK;
}


//查找操作，查找第i个元素，并返回其值
status findIndex(LinkList &L, int i) {
    lNode *p = L;
    int j = 0;
    while (p) {
        if (i == j)
            break;
        p = p->next;
        j++;
    }
    if (!p || i != j)
        return ERROR;
    else {
        outputSingle(p);
    }
    return OK;
}


//插入操作，在第i个元素前插入一个元素
status insertElem(LinkList &L, int i, int number, string name, double price) {
    lNode *p = L;
    lNode *q;
    int j = 1;


    if (i < 1 || length(L) < i)
        return ERROR;
    while (j < i) {
        p = p->next;
        j++;
    }

    q = new lNode;
    q->bookNumber = number;
    q->bookName = name;
    q->bookPrice = price;
    q->next = p->next;
    p->next = q;

    return OK;
}


//删除操作，删除表中第i个元素
status deleteElem(LinkList &L, int i) {
    lNode *p = L;
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


//将链表排序为非递减有序单链表
status sortAsIncrease(LinkList &L) {
    lNode *p;
    LinkList tempL;
    lNode *q = tempL;
    lNode *x;

    int i;
    int arr[length(L)];

    i = 0;
    p = L;
    while (p->next) {
        p = p->next;
        arr[i] = p->bookNumber;
        i++;
    }

    sort(arr, arr + length(L), less<>());

    for (i = 0; i < length(L); i++) {
        for (p = L; p; p = p->next) {
            if ((p->bookNumber) == arr[i]) {
                x = new lNode;
                x->bookNumber = p->bookNumber;
                x->bookName = p->bookName;
                x->bookPrice = p->bookPrice;
                x->next = nullptr;

                q->next = x;
                q = q->next;
                break;
            }
        }
    }

    L = tempL;

    return OK;
}


int main() {
    LinkList L;

    int flag;
    int i;

    int number;
    string name;
    double price;

    initList(L);
    cout << "请输入图书数据：" << endl;
    creatList(L);
    cout << endl;

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.继续输入图书数据\n"
                "2.逐个显示图书表中所有图书的相关信息\n"
                "3.根据书名进行查找，返回此图书信息\n"
                "4.根据指定的位置返回相应的图书信息\n"
                "5.给定一个图书信息，插入到表中指定的位置\n"
                "6.删除指定位置的图书记录\n"
                "7.根据图书号从小到大整理图书信息\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                cout << "继续输入图书数据：" << endl;
                creatList(L);
                cout << endl;
                break;
            case 2:
                cout << "图书列表: " << endl;
                outputList(L);
                cout << endl;
                break;
            case 3:
                cout << "输入要查找的书名: ";
                cin >> name;
                searchElem(L, name);
                cout << endl;
                break;
            case 4:
                cout << "输入指定的位置：";
                cin >> i;
                findIndex(L, i);
                cout << endl;
                break;
            case 5:
                cout << "输入图书信息：" << endl;
                cout << "请输入图书号：";
                cin >> number;
                cout << "请输入图书名：";
                cin >> name;
                cout << "请输入价格：";
                cin >> price;
                cout << "插入的位置：";
                cin >> i;
                insertElem(L, i, number, name, price);
                break;
            case 6:
                cout << "删除表中第i个元素。输入i：";
                cin >> i;
                deleteElem(L, i);
                break;
            case 7:
                cout << "将链表排序为非递减有序单链表：" << endl;
                sortAsIncrease(L);
                break;
            case -1:
                return OK;
            default:
                cout << "无效" << endl;
                break;
        }
    }
}

/*
测试数据
20 "r4" 30.2
11 "w3" 60.3
32 "w5" 99
12 "w4" 32
10 "w2" 0.6
9 "w1" 99
-1
2

*/
