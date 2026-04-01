cmake_minimum_required(VERSION 3.26)
project(parc2 C)

set(CMAKE_C_STANDARD 11)

add_executable(parc2 main.c
        functions.c
        functions.h)
