//二 、  线性表的链式存储结构（一）----单链表的有关操作
//实验学时  ２学时
//背景知识：单链表的插入、删除及应用。
//目的要求
//1．掌握单链表的存储特点及其实现。
//2．掌握单链表的插入、删除算法及其应用算法的程序实现。
//实验内容
////1、2、3、4为基础必选，5、6、7、8为提高，自选完成
//1．键盘输入一组元素，建立一个带头结点的单链表（无序）。
//2．遍历单链表（即输出单链表中各结点元素）。
//3．实现插入操作，在第i个元素前插入一个元素。
//4. 实现删除算法，删除表中第i个元素。
//5．建立一个非递减有序单链表，并实现在非递减有序链表中插入一个元素使链表元素仍有序的插入运算。
//6．利用算法5建立两个非递减有序单链表，然后合并成一个非递减有序单链表。
//7．删除上述有序表中所有值大于mink且小于maxk的元素（mink、maxk自定）
//8. 把单链表中元素逆置。


#include <iostream>
#include <cstring>

using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFOLOW = -2;
const int MAXSIZE = 100;

typedef int status;
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
};

//通过键盘流生成表数据
status creatList(LinkList &L) {
    elemType input;
    LNode *p = L;
    LNode *q;

    while (true) {
        cin >> input;
        if (input != -1) {
            q = new LNode;
            q->data = input;
            q->next = nullptr;//要写明

            p->next = q;
            p = p->next;
        } else
            return OK;
    };
}

//输出表
status outputList(LinkList &L) {
    LNode *p = L;

    cout << "The list: ";
    while (p->next) {
        p = p->next;
        cout << p->data << " ";
    }
    cout << endl;
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


////查找操作，查找第i个元素，并返回其值
//status findIndex(LinkList &L, int i) {
//    cout << "The NO." << i << " element: " << L.elem[i - 1] << endl;
//    return OK;
//}


////按值查找，查找数据域为x的元素，存在返回其位置
//status searchElem(LinkList &L, elemType x) {
//    int i = 0;
//    while ((L.elem[i] != x) && (i <= L.length - 1))
//        i++;
//    if (i == L.length)
//        return ERROR;
//    else {
//        cout << "Location is NO." << i + 1 << endl;
//        return OK;
//    }
//}


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
    LNode *q;
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


int main() {
    LinkList L;
    int flag;
    int i;
    elemType x;

    initList(L);
    cout << "请输入单链表数据（输入-1以终止输入）：";
    creatList(L);
    cout << "\n";

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.输出表数据\n"
//                "2.按位查找\n"
//                "3.按值查找\n"
                "4.插入元素\n"
                "5.按位删除\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                outputList(L);
                break;
//            case 2:
//                cout << "查找第i个元素，并返回其值。输入i：";
//                cin >> i;
//                findIndex(L, i);
//                break;
//            case 3:
//                cout << "查找数据域为x的元素，存在返回其位置。输入数据x：";
//                cin >> i;
//                searchElem(L, i);
//                break;
            case 4:
                cout << "在第i个元素前插入一个元素。输入i和x：";
                cin >> i >> x;
                insertElem(L, i, x);
                break;
            case 5:
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