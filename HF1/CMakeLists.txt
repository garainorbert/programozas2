cmake_minimum_required(VERSION 3.26)
project(HF1 C)

set(CMAKE_C_STANDARD 11)

add_executable(HF1 main.c
        functions.h
        functions.c)
