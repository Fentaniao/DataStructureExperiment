/*
 3．采用链式存储实现队列的初始化、入队、出队操作
 */



#include <iostream>
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
typedef int elemType;

typedef struct QNode {
    elemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

//初始化
status initQueue(LinkQueue &Q) {
    Q.front = Q.rear = new QNode;
    Q.rear->next = nullptr;
    return OK;
}

//入队
status enQueue(LinkQueue &Q, elemType input) {
    QNode *p;
    p = new QNode;
    p->data = input;
    p->next = nullptr;

    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

//出队
status deQueue(LinkQueue &Q) {
    elemType output;
    output = Q.front->next->data;
    Q.front->next = Q.front->next->next;
    return output;
}

//判断是否为空队列
status isEmpty(LinkQueue &Q) {
    return Q.front->next == nullptr;
}


//输出队列
status outputQueue(LinkQueue &Q) {
    QueuePtr p = Q.front;
    while (p->next != nullptr) {
        p = p->next;
        cout << p->data << " ";
    }
    return OK;
}


//获取队列长
status length(LinkQueue &Q) {
    int i = 0;
    QueuePtr p = Q.front;
    while (p->next != nullptr) {
        i++;
        p = p->next;
    }
    return i;
}


int main() {
    LinkQueue Q;

    int flag;
    elemType x;


    initQueue(Q);

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.输出队列\n"
                "2.入队列\n"
                "3.出队列\n"
                "4.判断是否为空队列\n"
                "5.获取队列长\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                cout << "The LinkQueue: ";
                outputQueue(Q);
                cout << endl;
                break;
            case 2:
                cout << "请输入入队列元素：";
                cin >> x;
                enQueue(Q, x);
                break;
            case 3:
                cout << "出队列元素：";
                cout << deQueue(Q);
                cout << endl;
                break;
            case 4:
                if (isEmpty(Q) == 1)
                    cout << "空队列";
                else
                    cout << "非空队列";
                cout << endl;
                break;
            case 5:
                cout << "队列的长度为：";
                cout << length(Q);
                cout << endl;
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


/*
 * 测试数据

 4
 5
 2
 1
 2
 2
 2
 3
 2
 4
 3
 1
 3
 1
 3
 1
 4
 5

*/

/*
 * 测试结果

 4//空队列
 5//队列长为0
 2
 1//入队列
 2
 2//入队列
 2
 3//入队列
 2
 4//入队列
 3//出队列
 1
 3//出队列
 1
 3//出队列
 1
 4//非空队列
 5//队列长为1

*/
