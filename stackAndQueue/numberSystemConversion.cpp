/*
1、数制转换
【实验目的】
加深对栈结构的理解,提高分析问题和解决问题的能力。
【问题描述】
将一个十进制数n转换为其他进制d，如十六进制、八进制、二进制。【参考教材P55、75】
【基本要求】
利用栈实现对此问题的求解，对输入的任意一个非负的十进制，输出相应的其它进制d（尽量三种进制都实现，至少要完成二种进制的转换）。
【测试数据】

十进制1348的16进制数为：544，二进制数为：10101000100
【实现提示】
（1）将一个十进制数n转换为其他进制d,可采用除d取余法，如十进制数1348转换为八进制数的过程如下：
其转换方法利用辗转相除法，运算过程如下：
N       N/8(整除)   N%8（求余）
1348	    168         4
168	         21        0
21           2         5
2            0         2
由于计算过程是从低位到高位顺序产生八进制数的各个数位，而输出过程应从高位到低位进行，因此，将每次除8的余数进栈，然后再一个一个地从栈中输出，从而得出八进制数
（2）若d为十六进制，需将10—15转换为A—F，可采用简单的选择语句来处理也可参考 C语言学习指导P133 第3题的转换方法来处理。
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
typedef string elemType;

typedef class Stack {
private:
    elemType *base;
    elemType *top;
    int stackSize;

public:
    //顺序栈的初始化操作就是为顺序栈动态分配一个预定义大小的数组空间
    Stack() {
        base = new elemType[MAXSIZE];
        top = base;
        stackSize = MAXSIZE;
    }

    //入栈操作是指在栈顶插入一个新的元素
    status push(char input) {
        if (top - base == stackSize)
            exit(OVERFOLOW);

        *top = input;
        top++;
        return OK;
    }

    //出栈操作是将栈顶元素删除
    string pop() {
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


//有效性检查
//int validityCheck(string &expression) {
//
//    return 1;
//}


//数制转换
string systemConversion(int &decimalNumber, int &aimSystem) {
    Stack s;

    int N = decimalNumber;
    string aimNumber;
    string symbol = "0123456789ABCDEFG";


    //通过for循环，ch依次取的是expression里面的字符,直到取完为止
    while (N) {
        s.push( symbol[N % aimSystem]);
        N = N / aimSystem;
    }
    aimNumber = "";
    while (!s.isEmpty()) {
        aimNumber += s.pop();
    }
    return aimNumber;
}


int main() {
    int flag;
    int aimSystem;
    int decimalNumber;

    //    菜单
    while (true) {
        cout << "输入数字以执行对应操作：\n"
                "1.进行数制转换\n"
                "-1.退出\n";
        cout << "输入：";
        cin >> flag;
        cout << endl;

        switch (flag) {
            case 1:
                cout << "请输入待转换的十进制正数：";
                cin >> decimalNumber;

//                if (!validityCheck(expression)) {
//                    cout << "该数在此数制下无意义";
//                    break;
//                }

                cout << "请输入目标数制：";
                cin >> aimSystem;
                cout << "转换结果: " << systemConversion(decimalNumber, aimSystem) << endl;
                break;
            case -1:
                return OK;
            default:
                cout << "无效" << endl;
                break;
        }
    }
}



/*测试输入
  1
 1348
 8
  1
 1348
 16
  1
 1348
 2
   1
 245
 16


*/

/*测试结果
  1//开始转换
 1348
 8
 //2504
   1//开始转换
 1348
 16
 //544
  1//开始转换
 1348
 2
 //10101000100
   1
 245
 16//f5

*/