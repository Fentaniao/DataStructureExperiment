#ifndef POWERTRACE_H
#define POWERTRACE_H

/**
 * <h1>PowerTrace</h1>
 * <p>A C++ head file designs to trace variable
 * <hr />
 * <h2>Usage</h2>
 * <p>Copy this .h file to your project directory, and include <b><code>#include "PowerTrace.h"</code></b> in your target .cpp file.
 * <h2>Copyright</h2>
 * @author      Fentaniao
 * @version       2021/10/19
 */

// TODO 可以考虑使用修饰符进行控制，如"N2D描述S"表示输出traceNum为2，description为描述，S表示储存为日志

#include <iostream>
#define trace(var,traceNum,description) Trace(var,traceNum,description, #var)
#define traceArr(var,traceNum ,description) TraceArr(var,traceNum,description, #var)

//#define varName(x) #x

//trace simple variable
template<typename T>
void Trace(T var, int traceNum, const std::string &description ,const std::string &varName) {
    std::cout << "TRACE[VarName=" << varName << "] ";

    if (traceNum != -1)
        std::cout << "[TraceNum=" << traceNum << "] ";

    std::cout << "[Type=" << typeid(var).name() << "] "
              << "[Value=" << var << "]";

    if (!description.empty())
        std::cout << "[Desc: " << description << "] ";

    std::cout << std::endl;
}


//trace Array variable
template<typename T>
void TraceArr(T var, int traceNum , const std::string &description ,const std::string &varName ) {
    std::cout << "TRACE[ArrName=" << varName << "] ";

    if (traceNum != -1)
        std::cout << "[TraceNum=" << traceNum << "] ";

    std::cout << "[Type=" << typeid(var[0]).name() << "] "
              << "[Set={";
    for (int i = 0; i < sizeof(var) / sizeof(var[0]); i++)
        std::cout << var[i] << ", ";
    std::cout << "}]";

    if (!description.empty())
        std::cout << "[Desc: " << description << "] ";

    std::cout << std::endl;
}

#endif //POWERTRACE_H
