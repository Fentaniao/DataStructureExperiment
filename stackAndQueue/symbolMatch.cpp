/*
2、括号匹配的检验
【实验目的】
加深对栈结构的理解,提高分析问题和解决问题的能力。
【问题描述】
在数学中，如果有一个带括号的式子，则要求这些括号必须成对并且匹配。现在假设只考虑小括号“（”、“）”和中括号“[”、“]”。例如[（]）,或(]),括号都是不匹配的，而（[[]()]）是匹配的。【参考教材P55、76】
【基本要求】
输入一行含有[、]、(、) 这4种字符的字符串，例如([（）])，要编程利用栈来检查括号是否匹配，如果字符串中所含的括号是匹配的，则输出Yes,否则输出No。
【测试数据】
如[（]）,或(]),不匹配输出No，（[[]()]）匹配,输出Yes.
【实现提示】
1、通过结构体定义一个顺序栈和一个char类型的数组，用来存储字符串。
2、每读入一个括号，则对括号进行判断：
如果是左括号，则直接进栈，如果是右括号）或中括号]，则检查栈顶元素是否为相应的（或[，如果是则出栈，如果不是，则说明括号不匹配，输出 No。如果一直到处理完所有字符都没发现不匹配的括号，则输出Yes。
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

typedef class Stack {
private:
    elemType *base;
    elemType *top;
    int stackSize;

public:
    //顺序栈的初始化操作就是为顺序栈动态分配一个预定义大小的数组空间
    status initStack() {
        base = new elemType[MAXSIZE];
        top = base;
        stackSize = MAXSIZE;
        return OK;
    }

    //入栈操作是指在栈顶插入一个新的元素
    status push(elemType input) {
        if (top - base == stackSize)
            exit(OVERFOLOW);

        *top = input;
        top++;
        return OK;
    }

    //出栈操作是将栈顶元素删除
    status pop() {
        elemType output;
        top--;
        output = *top;
        return output;
    }

    //判断是否为空栈
    status isEmpty() {
        return top == base;
    }

    //输出栈
    status outputStack() {
        while (top != base) {
            cout << *base << " ";
            base++;
        }
        return OK;
    }

    //获取栈长
    status length() {
        return int(top - base);
    }
} Stack;


//符号检查
int symbolCheck(string &expression) {
    string leftSymbol = "({[<";
    string rightSymbol = ")}]>";

    Stack s;
    s.initStack();

    //通过for循环，ch依次取的是expression里面的字符,直到取完为止
    for (auto ch: expression) {
        if (leftSymbol.find(ch))
            s.push(ch);
        else if (rightSymbol.find(ch))
            if (leftSymbol[rightSymbol.find(ch)] != s.pop())
                return 0;
    }
    return 1;
}


int main() {
    int flag;
    string expression;

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.检查表达式的括号是否匹配\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                cout << "请输入表达式：";
                cin >> expression;
                cout << "检查结果: ";
                if (symbolCheck(expression))
                    cout << "Yes";
                else
                    cout << "No";
                cout << endl;
                break;
            case -1:
                return OK;
            default:
                cout << "无效" << endl;
                break;
        }
    }
}



/*测试数据
 1
 [(])
 1
 (])
 1
 ([[2*3]()])
 -1

*/

/*测试结果
 1
 [(])//No
 1
 (])//No
 1
 ([[]()])//Yes
 -1//结束

*/