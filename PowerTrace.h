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
 * @version       2021/10/20
 */

// TODO 可以考虑使用修饰符进行控制，如"N2D描述S"表示输出traceNum为2，description为描述，S表示储存为日志

#include <iostream>

/**
 * <h2>Customize</h2>
 * <p>trace customize variable
 */

//#define varName(x) #x


/**
 * <h2>trace</h2>
 * <p>trace simple variable
 */

#define TRACE_1(v) Trace(v, #v)
#define TRACE_2(v, a1) Trace(v, #v, a1)
#define TRACE_3(v, a1, a2) Trace(v, #v, a1, a2)
#define TRACE_NARG(...) TRACE_ARG_N(__VA_ARGS__, 4, 3, 2, 1, 0)
#define TRACE_ARG_N(_1, _2, _3, _4, n, ...) n
#define TRACE_NC(f, ...) f(__VA_ARGS__)
#define TRACE_NB(nargs, ...) TRACE_NC(TRACE_ ## nargs, __VA_ARGS__)
#define TRACE_NA(nargs, ...) TRACE_NB(nargs, __VA_ARGS__)
#define trace(...) TRACE_NA(TRACE_NARG(__VA_ARGS__), __VA_ARGS__)

template<typename T>
void Trace(T var, const std::string &varName, int traceNum = -1, const std::string &description = "") {
    std::cout << "TRACE[VarName=" << varName << "] ";

    if (traceNum != -1)
        std::cout << "[TraceNum=" << traceNum << "] ";

    std::cout << "[Type=" << typeid(var).name() << "] "
              << "[Value=" << var << "]";

    if (!description.empty())
        std::cout << "[Desc: " << description << "] ";

    std::cout << std::endl;
}


/**
 * <h2>traceArr</h2>
 * <p>trace array variable
 */

#define TRACEARR_1(v) TraceArr(v, #v)
#define TRACEARR_2(v, a1) TraceArr(v, #v, a1)
#define TRACEARR_3(v, a1, a2) TraceArr(v, #v, a1, a2)
#define TRACEARR_NARG(...) TRACEARR_ARG_N(__VA_ARGS__, 4, 3, 2, 1, 0)
#define TRACEARR_ARG_N(_1, _2, _3, _4, n, ...) n
#define TRACEARR_NC(f, ...) f(__VA_ARGS__)
#define TRACEARR_NB(nargs, ...) TRACEARR_NC(TRACEARR_ ## nargs, __VA_ARGS__)
#define TRACEARR_NA(nargs, ...) TRACEARR_NB(nargs, __VA_ARGS__)
#define traceArr(...) TRACEARR_NA(TRACEARR_NARG(__VA_ARGS__), __VA_ARGS__)

template<typename T>
void TraceArr(T var, const std::string &varName, int traceNum = -1, const std::string &description = "") {
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
