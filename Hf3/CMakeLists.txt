cmake_minimum_required(VERSION 3.26)
project(Hf3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Hf3 main.c
        functions.h
        functions.c)
