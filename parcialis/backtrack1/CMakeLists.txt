cmake_minimum_required(VERSION 3.26)
project(backtrack1 C)

set(CMAKE_C_STANDARD 11)

add_executable(backtrack1 main.c
        functions.c
        functions.h)
