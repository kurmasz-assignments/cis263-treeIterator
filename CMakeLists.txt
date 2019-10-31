cmake_minimum_required(VERSION 3.14)
project(Lists)

set(CMAKE_CXX_STANDARD 14)

add_executable(studentTest testMain.cpp treeIteratorTest.cpp)
add_executable(treeMain treeMain.cpp)
