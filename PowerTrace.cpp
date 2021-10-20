#include <iostream>

#define varName(x) #x


//trace simple variable
template<typename T>
void trace(T var, int traceNum = -1, const std::string &description = "") {
    std::cout << "TRACE[VarName=" << varName(var) << "] ";

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
void traceArr(T var, int traceNum = -1, const std::string &description = "") {
    std::cout << "TRACE[ArrName=" << varName(var) << "] ";

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