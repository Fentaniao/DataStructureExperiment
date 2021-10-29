cmake_minimum_required(VERSION 3.20)
project(Experiment)

set(CMAKE_CXX_STANDARD 14)

#支持多个单文件编译运行
message("<< Add exe: ")
#遍历项目根目录下所有的 .cpp 文件
#要求所有cpp文件命名不重复，不能含有中文，不能含有‘/’等字符
file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    #获取文件名
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    #添加
    add_executable(${exe} ${file})
    #发送完成消息
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()


include_directories(.)


#支持googletest
message("<< Enable GTest: ")
set(googleTestDir ./googletest)

#Add the google test subdirectory
add_subdirectory(${googleTestDir})
#include googletest/include dir
include_directories(${googleTestDir}/googletest/include)
#include the googlemock/include dir
include_directories(${googleTestDir}/googlemock/include)

#搜索路径下的文件并添加至列表list，列表名为SOURCE_FILE
file(GLOB_RECURSE files *.cpp)
#遍历项目根目录下所有的 .cpp 文件
#要求所有cpp文件命名不重复，不能含有中文，不能含有‘/’等字符
foreach (file ${files})
    #从绝对路径中获取相对路径
    file(RELATIVE_PATH path "${CMAKE_BINARY_DIR}" "${file}")
    #获取文件名
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${path})
    if (exe MATCHES "CMakeCXXCompilerId")
        #排除CMakeCXXCompilerId文件
    else (true)
        #添加
        add_executable(GTest_${exe} ${path})
        target_link_libraries(GTest_${exe} gtest gtest_main)
        target_link_libraries(GTest_${exe} gmock gmock_main)
        #发送完成消息
        message("\ \ \ \ ~~\ Connected to GTest: ${path}")
    endif ()
endforeach ()

#仅连接list中的 .cpp 文件
#list(APPEND SOURCE_FILE
#        test.cpp
#        search/hashSearch.cpp
#        )
#add_executable(GTest ${SOURCE_FILE})

## Link with GoogleTest
#target_link_libraries(GTest gtest gtest_main)
##Link with GoogleMock
#target_link_libraries(GTest gmock gmock_main)