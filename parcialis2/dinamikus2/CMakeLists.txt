cmake_minimum_required(VERSION 3.26)
project(dinamikus2 C)

set(CMAKE_C_STANDARD 11)

add_executable(dinamikus2 main.c
        functions.h
        functions.c)
