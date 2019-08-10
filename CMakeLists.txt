cmake_minimum_required(VERSION 3.14)
project(fill C)

file (GLOB SRC fillit/libft/*.c)

set(CMAKE_C_STANDARD 99)

add_executable(fill ${SRC} fillit/main.c fillit/validation.c
        fillit/fillit.h fillit/mkfig_arr.c fillit/filling_list.c
        fillit/dance_cage.c fillit/dance_create.c tests/funcs_for_tests.c
        tests/func_for_tests.h
        fillit/bad_options.c fillit/free_funcs.c fillit/knuth_solver.c
        fillit/solver.c fillit/free_manager.c fillit/free_manager.h)