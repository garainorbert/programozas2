cmake_minimum_required(VERSION 3.26)
project(greedy2 C)

set(CMAKE_C_STANDARD 11)

add_executable(greedy2 main.c
        functions.h
        functions.c)
