#include <iostream>

using namespace std;

//定义
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

typedef int status;
typedef int keyType;
typedef int infoType;

class RedType {
public:
    keyType key;
    infoType otherInfo;
};

class SqList {
public:
    RedType r[MAXSIZE + 1]{};
    int length;

    SqList() {

        length = 0;
    }

    void creatList();

    void outputKey();

    void insertSort();

    void biInsertSort();
};


//通过键盘流生成表数据
void SqList::creatList() {
    keyType input;
    cout << ">> Enter the key elements: ";
    while (cin >> input) {
        if (length <= MAXSIZE - 1) {
            r[length + 1].key = input;
            length++;
        } else {
            cout << "表已满" << endl;
            break;
        }
    }
}


//输出表
void SqList::outputKey() {
    int i;

    for (i = 1; i < length + 1; ++i) {
        cout << r[i].key << " ";
    }

    cout << endl;
}

//对顺序表做直接插入排序
void SqList::insertSort() {
    int i, j;

    cout << "i=" << 1 << " ";
    outputKey();

    for (i = 2; i <= length; ++i) {
        if (r[i].key < r[i - 1].key) {
            r[0] = r[i];
            r[i] = r[i - 1];
            for (j = i - 2; r[0].key < r[j].key; --j)
                r[j + 1] = r[j];
            r[j + 1] = r[0];
        }
        cout << "i=" << i << " ";
        outputKey();
    }
}

//对顺序表做折半插入排序
void SqList::biInsertSort() {
    int i, j, low, high, mid;

    cout << "i=" << 1 << " ";
    outputKey();

    for (i = 2; i <= length; ++i) {
        r[0] = r[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (r[0].key < r[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
            r[j + 1] = r[j];
        r[high + 1] = r[0];

        cout << "i=" << i << " ";
        outputKey();
    }
}


//菜单
void menu(SqList L, int flag) {
    while (true) {
        //cout << "输入数字以执行对应操作：\n"
        //        "1.直接插入排序\n"
        //        "2.折半插入排序\n"
        //        "3.冒泡排序\n"
        //        "4.快速排序\n"
        //        "5.简单选择排序\n"
        //        "-1.退出\n";
        //cout << "输入：";
        //cin >> flag;
        //cout << endl;


        switch (flag) {
            case 1:
                cout << "直接插入排序: " << endl;
                L.insertSort();
                return;
            case 2:
                cout << "折半插入排序: " << endl;
                L.biInsertSort();
                return;
            case 3:
                cout << "冒泡排序: " << endl;

                return;
            case 4:
                cout << "快速排序: " << endl;

                return;
            case 5:
                cout << "简单选择排序: " << endl;

                return;
            case -1:
                return;
            default:
                cout << "无效" << endl;
                break;
        }
    }
}


int main() {
    SqList L;
    int i;

    //输入顺序表数据
    L.creatList();
    cout << "Print keys of the list: ";
    L.outputKey();

    //通过菜单调用不同的排序算法
    for (i = 1; i <= 5; ++i) {
        menu(L, i);
    }

    return 0;
}