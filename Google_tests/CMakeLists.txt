# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(Experiment)

set(CMAKE_CXX_STANDARD)


# Add tasks subprojects
#include(cmake/utils.cmake)
#add_subprojects(${CMAKE_SOURCE_DIR})

# adding the Google_Tests_run target
add_executable(Google_Tests_run ConverterTests.cpp)

# linking Google_Tests_run with DateConverter_lib which will be tested
target_link_libraries(Google_Tests_run DateConverter_lib)

target_link_libraries(Google_Tests_run gtest gtest_main)
