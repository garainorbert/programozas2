cmake_minimum_required(VERSION 3.26)
project(backtrack3 C)

set(CMAKE_C_STANDARD 11)

add_executable(backtrack3 main.c
        functions.c
        functions.h)
