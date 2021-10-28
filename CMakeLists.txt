cmake_minimum_required(VERSION 3.20)
project(Experiment)

set(CMAKE_CXX_STANDARD 14)

#遍历项目根目录下所有的 .cpp 文件
#要求所有cpp文件命名不重复，不能含有中文，不能含有‘/’等字符
file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable(${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

include_directories(.)

#支持googletest
set(googleTestDir ./googletest)

#Add the google test subdirectory
add_subdirectory(${googleTestDir})
#include googletest/include dir
include_directories(${googleTestDir}/googletest/include)
#include the googlemock/include dir
include_directories(${googleTestDir}/googlemock/include)

set(SOURCE_FILE
        test.cpp
        search/hashSearch.cpp
        )
add_executable(GTest ${SOURCE_FILE})

# Link with GoogleTest
target_link_libraries(GTest gtest gtest_main)
#Link with GoogleMock
target_link_libraries(GTest gmock gmock_main)
