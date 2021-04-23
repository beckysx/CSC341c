cmake_minimum_required(VERSION 3.19)
project(c___seeContentGithub)

set(CMAKE_CXX_STANDARD 20)

add_executable(project1a
        Project1a/project1a.cc)

add_executable(project1b
        Project1b/Calc.cpp Project1b/IntStack.cpp Project1b/IntStack.hpp)

add_executable(project1c
        Project1c/adj_list.cpp Project1c/adj_list.hpp Project1c/main.cpp)