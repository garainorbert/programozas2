cmake_minimum_required(VERSION 3.26)
project(sikbacktrack2 C)

set(CMAKE_C_STANDARD 11)

add_executable(sikbacktrack2 main.c
        functions.c
        functions.h)
