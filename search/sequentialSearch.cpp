/*7.1 顺序查找、折半查找算法的实现
【实验目的】
熟悉并掌握顺序查找、折半查找的过程和方法
【实验内容】
1、建立一个查找表，采用顺序查找实现某一已知的关键字的查找。
2、建立一个有序表，采用折半查找实现某一已知的关键字的查找。
【实验要点及说明】
 用折半查找法查找到待查找的元素，先从中间开始比较，逐渐缩小范围，直到查找成功或失败
注意问题     注意理解折半查找的适用条件（链表能否实现折半查找？）。
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


typedef struct {
    keyType key;
    infoType otherInfo;
} ElemType;

typedef struct {
    ElemType *R;
    int length;
} SSTable;

//初始化
status initList(SSTable &ST) {
    ST.R = new ElemType[MAXSIZE];
    if (!ST.R)
        exit(OVERFLOW);
    ST.length = 0;
    return OK;
}


//通过键盘流生成表数据
status creatList(SSTable &ST) {
    keyType input;
    while (ST.length <= MAXSIZE - 1) {
        cin >> input;
        if (input != -1) {
            ST.R[ST.length].key = input;
            ST.length++;
        } else
            return OK;
    }
}


//输出表
status outputList(SSTable &ST) {
    int i = 0;
    cout << "The list: ";
    while (i <= ST.length - 1) {
        cout << ST.R[i].key << " ";
        i++;
    }
    cout << endl;
    return OK;
}


//获取表长
status length(SSTable &ST) {
    if (ST.R)
        return ST.length;
    else
        return -1;
}


int searchSeq(SSTable &ST, keyType key) {
    int i;
    ST.R[0].key = key;
    for (i = ST.length; ST.R[i].key != key; --i);
    return i;
}

int searchBin(SSTable &ST, keyType key) {
    int low, mid, high;

    low = 1;
    high = ST.length;

    while (low < high) {
        mid = (low + high) / 2;
        if (ST.R[mid].key > key)
            high = mid - 1;
        else if (ST.R[mid].key < key)
            low = mid + 1;
        else//ST.R[mid].key==key
            return mid;
    }
    return 0;
}

//输出搜索结果
status searchResult(keyType key, int index) {
    if (index != 0)
        cout << "元素" << key << "的位置为" << index;
    else
        cout << "元素" << key << "不在该表中";
    cout << endl;
    return OK;
}

int main() {
    SSTable ST;
    keyType key;
    int index;

    initList(ST);
    cout << "请输入表数据（输入-1以终止输入）: ";
    creatList(ST);
    outputList(ST);
    cout << "请输入待搜索数据: ";
    cin >> key;

    cout << "顺序查找: ";
    index = searchSeq(ST, key);
    searchResult(key, index);

    cout << "折半查找: ";
    index = searchBin(ST, key);
    searchResult(key, index);


    return 0;
}