
#include <iostream>
#include "PowerTrace.h"

using namespace std;

int main() {
    int i;
    int j;

    int indexV1 = 3;
    int weight[58] = {2, 5, 4, 9};

    cout << "INFO 1变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1);
        traceArr(weight);
    }
    cout<<endl;

    cout << "INFO 2变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1, i);
        traceArr(weight, i);
    }
    cout<<endl;

    cout << "INFO 3变量" << endl;
    for (i = 0; i < 3; ++i) {
        trace(indexV1, i, "这是一段关于数值变量的描述");
        traceArr(weight, i, "这是一段关于数组变量的描述");
    }
    cout<<endl;

    return 0;
}