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

    void bubbleSort();

    int Partition(int low, int high);

    void QSort(int low, int high);

    void QuickSort();

    void SelectSort();
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

//对顺序表做冒泡排序
void SqList::bubbleSort() {
    int i, m, flag;
    RedType t{};

    cout << "i=" << 1 << " ";
    outputKey();

    m = length - 1;
    flag = 1;
    while ((m > 0) && (flag == 1)) {
        flag = 0;
        for (i = 1; i <= m; i++)
            if (r[i].key > r[i + 1].key) {
                flag = 1;
                t = r[i];
                r[i] = r[i + 1];
                r[i + 1] = t;
            }
        --m;

        cout << "i=" << length - m << " ";
        outputKey();
    }
}

int SqList::Partition(int low, int high) {
    keyType pivotKey;

    r[0] = r[low];
    pivotKey = r[low].key;
    while (low < high) {
        while (low < high && r[high].key >= pivotKey)
            --high;
        r[low] = r[high];
        while (low < high && r[low].key <= pivotKey)
            ++low;
        r[high] = r[low];
    }
    r[low] = r[0];
    return low;
}

void SqList::QSort(int low, int high) {
    keyType pivotLocation;
    static int num = 2;

    if (low < high) {

        pivotLocation = Partition(low, high);

        QSort(low, pivotLocation - 1);
        cout << "i=" << num++ << " ";
        outputKey();

        QSort(pivotLocation + 1, high);
        cout << "i=" << num++ << " ";
        outputKey();
    }
}

//对顺序表做快速排序
void SqList::QuickSort() {
    cout << "i=" << 1 << " ";
    outputKey();

    QSort(1, length);
}

//对顺序表做简单选择排序
void SqList::SelectSort() {
    int i, j, k;
    RedType t{};

    cout << "i=" << 1 << " ";
    outputKey();

    for (i = 1; i < length; ++i) {
        k = i;

        for (j = i + 1; j <= length; ++j)
            if (r[j].key < r[k].key)
                k = j;
        if (k != i) {
            t = r[i];
            r[i] = r[k];
            r[k] = t;
        }

        cout << "i=" << i + 1 << " ";
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
                L.bubbleSort();
                return;
            case 4:
                cout << "快速排序: " << endl;
                L.QuickSort();
                return;
            case 5:
                cout << "简单选择排序: " << endl;
                L.SelectSort();
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
    cout << "<< Print keys of the list: ";
    L.outputKey();

    //通过循环调用菜单函数，一次性展示所有不同的排序算法
    for (i = 1; i <= 5; ++i) {
        menu(L, i);
    }

    return 0;
}