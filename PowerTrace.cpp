
#include <iostream>
#include "PowerTrace.h"


using namespace std;

void Fun(int i, const list<int> &a) {
    if (!a.empty()) {
        cout << ", Cycle=(";
        for (int it: a) {
            cout << it << " ";
        }
        cout << "ok" << endl;
    }
}

int main() {
    int i = 0;
    int j = 0;


    Fun(i, {i, j});

    int indexV1 = 3;
    int weight[58] = {2, 5, 4, 9};

    cout << "INFO 1变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1);
        traceArr(weight);
    }
    cout << endl;

    cout << "INFO 2变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1, { i, 2 });
        traceArr(weight, { i });
    }
    cout << endl;

    cout << "INFO 3变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1, { i, i }, "这是一段关于数值变量的描述");
        traceArr(weight, { i, 3, 3, 3, 5, 7 }, "这是一段关于数组变量的描述");
    }
    cout << endl;


    cout << "INFO trace 代码生成" << endl;
    for (i = 1; i < 9; i++) {
        cout << "#define TRACE_" << i << "(v";
        for (j = 1; j < i; j++) {
            cout << ", opt" << j;
        }
        cout << ") Trace(v, #v, __LINE__, __FUNCTION__";
        for (j = 1; j < i; j++) {
            cout << ", " << "opt" << j;
        }
        cout << ")" << endl;
    }

    cout << "INFO traceArr 代码生成" << endl;;
    for (i = 1; i < 9; i++) {
        cout << "#define TRACEARR_" << i << "(v";
        for (j = 1; j < i; j++) {
            cout << ", opt" << j;
        }
        cout << ") TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__";
        for (j = 1; j < i; ++j) {
            cout << ", " << "opt" << j;
        }
        cout << ")" << endl;
    }

    return 0;
}