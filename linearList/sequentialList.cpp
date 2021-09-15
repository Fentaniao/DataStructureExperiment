//一、  线性表的顺序存储结构及其基本操作算法的实现
//实验学时 2学时
//背景知识:顺序表的插入、删除及应用。
//目的要求：
//1．掌握顺序存储结构的特点。
//2．掌握顺序存储结构的常见算法。
//实验内容
//1．建立含n个数据元素的顺序表并输出该表各元素的值。元素的个数及n个元素的值由键盘输入，元素类型为整型。
//2．实现查找操作，查找第i个元素，并返回其值。
//3.实现按值查找，查找数据域为x的元素，存在返回其位置
//4.实现插入操作，在第i个元素前插入一个元素。
//5.实现删除操作，删除表中第i个元素。


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

typedef struct {
    elemType *elem;
    int length;
} SqList;


//初始化
status initList(SqList &L) {
    L.elem = new elemType[MAXSIZE];
    if (!L.elem)
        exit(OVERFOLOW);
    L.length = 0;
    return OK;
}


//通过键盘流生成表数据
status creatList(SqList &L) {
    elemType input;
    while (L.length <= MAXSIZE - 1) {
        cin >> input;
        if (input != -1) {
            L.elem[L.length] = input;
            L.length++;
        } else
            return OK;
    }
}


//输出表
status outputList(SqList &L) {
    int i = 0;
    cout << "The list: ";
    while (i <= L.length - 1) {
        cout << L.elem[i] << " ";
        i++;
    }
    cout << endl;
    return OK;
}


//获取表长
status length(SqList &L) {
    if (L.elem)
        return L.length;
    else
        return -1;
}


//查找操作，查找第i个元素，并返回其值
status findIndex(SqList &L, int i) {
    cout << "The NO." << i << " element: " << L.elem[i - 1] << endl;
    return OK;
}


//按值查找，查找数据域为x的元素，存在返回其位置
status searchElem(SqList &L, elemType x) {
    int i = 0;
    while ((L.elem[i] != x) && (i <= L.length - 1))
        i++;
    if (i == L.length)
        return ERROR;
    else {
        cout << "Location is NO." << i + 1 << endl;
        return OK;
    }
}


//插入操作，在第i个元素前插入一个元素
status insertElem(SqList &L, int i, elemType x) {
    int index = L.length;
    if (L.length == MAXSIZE || i - 1 > L.length - 1)
        return OVERFOLOW;
    while (index >= i - 1) {
        L.elem[index] = L.elem[index - 1];
        index--;
    }
    L.elem[i - 1] = x;
    L.length++;
    return OK;
}


//删除操作，删除表中第i个元素
status deleteElem(SqList &L, int i) {
    int index = i - 1;
    if (i - 1 > L.length - 1)
        return ERROR;
    while (index <= L.length - 1 - 1) {
        L.elem[index] = L.elem[index + 1];
        index++;
    }
    L.length--;
    return OK;
}


int main() {
    SqList L;
    int flag;
    int i;
    elemType x;

    initList(L);
    cout << "请输入顺序表数据（输入-1以终止输入）：";
    creatList(L);
    cout << "\n";

//    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.输出表数据\n"
                "2.按位查找\n"
                "3.按值查找\n"
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
            case 2:
                cout << "查找第i个元素，并返回其值。输入i：";
                cin >> i;
                findIndex(L, i);
                break;
            case 3:
                cout << "查找数据域为x的元素，存在返回其位置。输入数据x：";
                cin >> i;
                searchElem(L, i);
                break;
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
}
