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
