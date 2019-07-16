cmake_minimum_required(VERSION 3.14)
project(fill C)

file (GLOB SRC fillit/libft/*.c)

set(CMAKE_C_STANDARD 99)

add_executable(fill ${SRC} fillit/main.c fillit/validation.c
        fillit/fillit.h)