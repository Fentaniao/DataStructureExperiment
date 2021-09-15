//实验内容
//1．建立含n个数据元素的顺序表并输出该表各元素的值。元素的个数及n个元素的值由键盘输入，元素类型为整型。
//2．实现查找操作，查找第i个元素，并返回其值。
//3.实现按值查找，查找数据域为x的元素，存在返回其位置
//4.实现插入操作，在第i个元素前插入一个元素。
//5.实现删除操作，删除表中第i个元素。


#include <iostream>
#include <cstring>

using namespace std;

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

status initList(SqList &L) {
    L.elem = new elemType[MAXSIZE];
    if (!L.elem)
        exit(OVERFOLOW);
    L.length = 0;
    return OK;
}


status creatList(SqList &L) {
    elemType input;
    cout << "Please input data: " << endl;
    while (L.length <= MAXSIZE - 1) {
        cin >> input;
        if (input != -1) {
            L.elem[L.length] = input;
            L.length++;
        } else
            return OK;
    }
}


status outputList(SqList &L) {
    int i = 0;
    elemType input;
    cout << "The list: ";
    while (i <= L.length - 1) {
        cout << L.elem[i] << " ";
        i++;
    }
    cout << endl;
    return OK;
}


status length(SqList &L) {
    if (L.elem)
        return L.length;
    else
        return -1;
}


status findIndex(SqList &L, int index) {
    cout << "The NO." << index << " element: " << L.elem[index] << endl;
    return OK;
}


status searchElem(SqList &L, elemType x) {
    int i = 0;
    while ((L.elem[i] != x) && (i <= L.length - 1))
        i++;
    if (i == L.length)
        return ERROR;
    else {
        cout << "Location is NO." << i << endl;
        return OK;
    }
}


status insertElem(SqList &L, int index) {

    return OK;
}


status deletetElem(SqList &L, int index) {

    return OK;
}


int main() {
    SqList L;
    int flag;
    int index;

    initList(L);
    creatList(L);

//    Menu
    while (true) {
        cout << "输入";
        cin >> flag;
        if (flag == -1)
            break;
        else {
            switch (flag) {
                case 1:
                    outputList(L);
                    break;
                case 2:
                    cin >> index;
                    findIndex(L, index);
                    break;
                case 3:
                    cin >> index;
                    insertElem(L, index);
                    break;
                case 4:
                    cin >> index;
                    deletetElem(L, index);
                    break;
                default:
                    cout << "无效";
                    break;
            }
        }
    }

    getchar();
    return 0;
}
