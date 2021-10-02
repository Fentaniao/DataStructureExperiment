/*
2．采用顺序存储实现栈的初始化、入栈、出栈操作
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

typedef struct {
    elemType *base;
    elemType *top;
    int stackSize;
} stack;

//顺序栈的初始化操作就是为顺序栈动态分配一个预定义大小的数组空间
status initStack(stack &s) {
    s.base = new elemType[MAXSIZE];
    if (!s.base)
        exit(OVERFOLOW);
    s.top = s.base;
    s.stackSize = MAXSIZE;
    return OK;
}

//入栈操作是指在栈顶插入一个新的元素
status push(stack &s, elemType input) {
    if (s.top - s.base == s.stackSize)
        exit(OVERFOLOW);

    *s.top = input;
    s.top++;
    return OK;
}

//出栈操作是将栈顶元素删除
status pop(stack &s) {
    elemType output;
    s.top--;
    output = *s.top;
    return output;
}

//判断是否为空栈
status isEmpty(stack &s) {
    return s.top == s.base;
}


//输出栈
status outputStack(stack s) {
    while (s.top != s.base) {
        cout << *s.base << " ";
        s.base++;
    }
    return OK;
}


//获取栈长
status length(stack &s) {
    return int(s.top - s.base);
}


int main() {
    stack s;

    int flag;
    elemType x;


    initStack(s);

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.输出栈\n"
                "2.入栈\n"
                "3.出栈\n"
                "4.判断是否为空栈\n"
                "5.获取栈长\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;

        switch (flag) {
            case 1:
                cout << "The Stack: ";
                outputStack(s);
                cout << endl;
                break;
            case 2:
                cout << "请输入入栈元素：";
                cin >> x;
                push(s, x);
                cout << endl;
                break;
            case 3:
                cout << "出栈元素：";
                cout << pop(s);
                cout << endl;
                break;
            case 4:
                if (isEmpty(s) == 1)
                    cout << "空栈";
                else
                    cout << "非空栈";
                cout << endl;
                break;
            case 5:
                cout << "栈的长度为：";
                cout << length(s);
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

 4//空栈
 5//栈长为0
 2
 1//入栈
 2
 2//入栈
 2
 3//入栈
 2
 4//入栈
 3//出栈
 1
 3//出栈
 1
 3//出栈
 1
 4
 5

*/