/*5.3 综合设计----哈夫曼编码    //也可作为最后一次的综合设计型实验
【实验目的】
了解哈夫曼树的结构特点及有关概念，掌握哈夫曼树的建立和哈夫曼编码的设计
【问题描述】
使用二叉树进行哈夫曼编码的设计，要求对输入的一串电文字符实现哈夫曼编码，再对哈夫编码生成的代码串进行译码，输出电文字符串
【实验功能】
1、	哈夫曼树的建立   从终端读入字符集大小n，以及n个字符和n个权值，建立哈夫曼树
2、	哈夫曼编码的生成  利用以建好的哈夫曼树，规定左分支为0，右分支为1，则从根结点到每个叶子结点所经过的分支对应的0和1组成的序列便为该结点对应字符的哈夫曼编码
【设计思想】
设计步骤
1、从没有父结点的结点集合中，找出2个权值最小的结点，求和后存放到新的链表单元中，并将找到的最小2个权值的结点的父结点地址指向新生成的结点。
2、重复步骤（1），直至循环完成。
3、从叶子结点遍历父结点，并记录遍历路径（当前结点为父结点的左儿子记为0，否则记为1），然后对遍历路径进行倒置处理，便得到该结点的哈夫曼编码。
4、重复步骤（3），直至完成全部叶子结点的哈夫曼编码。
【测试数据】
用下表给出的字符集和频度的实际统计数据建立哈夫曼树，并实现以下报文的编码和译码："CAS；CAT；SAT；AT"
字符	C	A	S	T	;
频度	2	4	2	3	3
【具体参考】
教材 P136--142 5.7节
*/

#include <iostream>
#include <cstring>

typedef int status;
using namespace std;
const int OK = 1;
const int ERROR = 0;
const int OVERFLOW = -2;
const int MAXSIZE = 100;

typedef struct BiTNode {
    float data;
    struct BiTNode *parent, *lchild, *rchild;
} BiTNode, *BiTree;
typedef struct {
    char data;
    float fre;
    BiTNode *password;
    string word;
} charNode;

int Getch(charNode B[], char ch, int &number, int &chnumber) {
    int i = 0;
    for (; i < number; i++)
        if (B[i].data == ch) {
            B[i].fre++;
            chnumber = i;
            return 0;
        }
    return 1;
}

void OUT(charNode A[], int number) {
    int i = 0;
    for (; i < number; i++)
        cout << A[i].data << A[i].fre << endl;
}

void leave(BiTree &X, int i, charNode A) {
    BiTNode *Y;
    Y = new BiTNode;
    X = new BiTNode;
    Y->lchild = NULL;
    Y->rchild = NULL;
    Y->data = i;
    Y->parent = X;
    X->data = A.fre;
    X->lchild = Y;
    X->rchild = NULL;
    X->parent = NULL;
}

void createtree(BiTree &L, BiTree &R) {
    BiTNode *q;
    q = new BiTNode;
    q->lchild = L;
    q->rchild = R;
    q->data = L->data + R->data;
    L->parent = q;
    R->parent = q;
    L = q;
}

//
void password(BiTree &Q, string &str, float &depth) {
    BiTNode *q;
    q = Q;
    str = "";
    int i = 0;
    while (q->parent != NULL) {
        if (q->parent->lchild == q)
            str = "0" + str;
        if (q->parent->rchild == q)
            str = "1" + str;
        i++;
        q = q->parent;
    }
    depth = i;
}

//
void printbtree(BiTree &T) {
    if (T != NULL)
        cout << T->data;
    if (T->lchild != NULL || T->rchild != NULL) {
        cout << "(";
        if (T->lchild != NULL) printbtree(T->lchild);
        if (T->rchild != NULL) {
            cout << ",";
            printbtree(T->rchild);
        }
        cout << ")";
    }
}

//
int getstring(int getint) {
    char ch[MAXSIZE];
    int chnumber[MAXSIZE];
    int length = 0;
    int number = 1;
    int i, j;
    charNode A[MAXSIZE];
    if (getint) {
        cout << "输入字符串：" << endl;
        cin >> ch[++length];
        A[0].data = ch[length];
        A[0].fre = 1;
        for (;;) {
            if ((ch[++length] = cin.get()) != '\n') {
                if (Getch(A, ch[length], number, chnumber[length])) {
                    A[number].data = ch[length];
                    A[number++].fre = 1;
                    chnumber[length] = number - 1;
                }
            } else break;
        }
    }
    if (getint == 0) {
        cout << "输入字符：" << endl;
        number = 0;
        char ch;
        ch = '0';
        while (ch != '\n') {
            cin >> A[length++].data;
            ch = cin.get();
        }
        cout << "输入概率：" << endl;
        ch = '0';
        while (ch != '\n') {
            cin >> A[number++].fre;
            ch = cin.get();
        }
        if (length != number) {
            cout << "个数不匹配";
            return 0;
        }
    }
//建树
    BiTree T[number];
    for (i = 0; i < number; i++) {
        leave(T[i], i, A[i]);
        A[i].password = T[i];
    }
    int inumber = number;
    do {
        for (i = 0; i < inumber; i++)
            for (j = i; j < inumber; j++)
                if (T[i]->data > T[j]->data) {
                    BiTNode *q;
                    q = T[i];
                    T[i] = T[j];
                    T[j] = q;
                }
        createtree(T[0], T[1]);
        T[1] = T[--inumber];
    } while (inumber > 1);
    for (i = 0; i < number; i++)
        password(A[i].password, A[i].word, A[i].password->data);
    if (getint) {
        int sum = 0;
        for (i = 0; i < number; i++)
            sum += A[i].password->data * A[i].fre;
        cout << "带权路径长度" << sum << endl;
        for (i = 0; i < number; i++)
            cout << A[i].data << A[i].word << endl;
        cout << "密码:" << endl;
        for (i = 1; i < length; i++)
            cout << A[chnumber[i]].word;
        cout << endl;
    }
    if (getint == 0) {
        for (i = 0; i < number; i++)
            cout << A[i].data << A[i].word << endl;
        {
            cout << "输入字符串:" << endl;
            int k = 0;
            char ch[MAXSIZE];
            cin >> ch[k++];
            while ((ch[k] = cin.get()) != '\n') k++;
            cout << "密码:" << endl;
            for (i = 0; i < k; i++)
                for (j = 0; j < number; j++)
                    if (ch[i] == A[j].data)
                        cout << A[j].word;
            cout << endl;
        }
    }
    return 1;
}

int main() {
    while (true) {
        string i;
        cout << "0：已知概率求字符串\n"
                "1:直接求字符串\n";
        cin >> i;
        if (i == "0" || i == "1") {
            getstring(i[0] - 48);
            break;
        } else
            cout << "输入错误" << endl;
    }
}
//0
//C A S T ;
//2 4 2 3 3
//CAST;CA;SAT;AT
