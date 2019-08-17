cmake_minimum_required(VERSION 3.14)
project(Fillit_Clion C)

file (GLOB SRC final/libft/*.c final/*.c)

set(CMAKE_C_STANDARD 99)

add_executable(Fillit_Clion ${SRC} tests/funcs_for_tests.c)