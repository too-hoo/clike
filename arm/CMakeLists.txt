# 限定了CMake的版本
cmake_minimum_required(VERSION 3.16)
# 该命令表示的项目名称是arm
project(arm)
# 设置（变量 值）
set(CMAKE_CXX_STANDARD 14)
# add_executable 表示把变量 SOURCE_FILES 编译成为一个名称为arm的可执行文件
add_executable(arm main.cpp)