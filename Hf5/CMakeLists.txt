cmake_minimum_required(VERSION 3.26)
project(Hf5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Hf5 main.c
        functions.h
        functions.c)
