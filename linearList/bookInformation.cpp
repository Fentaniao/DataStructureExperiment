//1．图书信息管理 （参考教材案例2.3相关资料）
//利用链表实现一个图书信息管理，包括数据输入、查找、插入、删除等  [或设计一个班级学生信息管理]
//实验目的：
//1、掌握线性表的定义；
//2、掌握线性表的基本操作，如建立、查找、插入和删除等，提高综合设计能力。
//实验内容：
//定义一个包含图书信息（图书号，图书名，价格）的单链表，使其具有如下功能：
//(1) 根据指定图书个数，逐个输入图书信息；
//(2) 逐个显示图书表中所有图书的相关信息；
//(3) 根据书名进行查找，返回此图书信息；
//(4) 根据指定的位置可返回相应的图书信息；
//(5) 给定一个图书信息，插入到表中指定的位置；
//(6) 删除指定位置的图书记录；


#include "iostream"
#include <cstring>

using namespace std;
//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFOLOW = -2;
const int MAXSIZE = 100;

typedef int status;

typedef struct lNode {
    int bookNumber = 0;
    string bookName = "Null";
    float bookPrice = 0;
    struct lNode *next = nullptr;
} lNode, *LinkList;

//初始化
status initList(LinkList &L) {
    L = new lNode;
    return OK;
}

//通过键盘流添加表数据
status creatList(LinkList &L) {
    int Number;
    string Name;
    float Price;
    lNode *p = L;
    lNode *q;

    while(p->next){
        p=p->next;
    }

    while (true) {
        cin >> Number;
        if (Number == -1)
            break;
        cin >> Name;
        cin >> Price;

        q = new lNode;
        q->bookNumber = Number;
        q->bookName = Name;
        q->bookPrice = Price;

        p->next = q;
        p = p->next;

    }
    return OK;
}

//输出表
status outputList(LinkList &L) {
    lNode *p = L;

    while (p->next) {
        p = p->next;
        cout <<"图书号:"<< p->bookNumber<<"，图书名:" << p->bookName<<"，价格:" << p->bookPrice <<endl;
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


////插入操作，在第i个元素前插入一个元素
//status insertElem(LinkList &L, int i, elemType x) {
//    lNode *p = L;
//    lNode *q;
//    int j = 1;
//
//
//    if (i < 1 || length(L) < i)
//        return ERROR;
//    while (j < i) {
//        p = p->next;
//        j++;
//    }
//
//    q = new lNode;
//    q->data = x;
//    q->next = p->next;
//    p->next = q;
//
//    return OK;
//}


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

    return OK;
}


int main() {
    LinkList L;
    LinkList anotherL;

    int flag;
    int i;


    initList(L);
    cout << "请输入图书数据（输入-1以终止输入）：";
    creatList(L);
    cout << endl;

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.继续输入图书数据\n"
                "2.输出表数据\n"
                "3.插入元素\n"
                "4.按位删除\n"
                "5.按非递减排序\n"
                "6.建立两个非递减有序单链表合并成一个非递减有序单链表\n"
                "7.删除上述有序表中所有值大于mink且小于maxk的元素\n"
                "8.把单链表中元素逆置\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                cout << "继续输入图书数据（输入-1以终止输入）：";
                creatList(L);
                cout << endl;
                break;
            case 2:
                cout << "图书列表: "<<endl;
                outputList(L);
                cout << endl;
                break;
            case 3:
                cout << "在第i个元素前插入一个元素。输入i和x：";
//                cin >> i >> x;
//                insertElem(L, i, x);
                break;
            case 4:
                cout << "删除表中第i个元素。输入i：";
                cin >> i;
                deleteElem(L, i);
                break;
            case -1:
                return OK;
            default:
                cout << "无效" << endl;
                break;
        }
    }
    return 0;
}