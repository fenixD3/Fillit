//
// Created by Mort Deanne on 2019-07-25.
//

#ifndef FILL_FUNC_FOR_TESTS_H
#define FILL_FUNC_FOR_TESTS_H
#include <stdio.h>
#include "../final/dance.h"
#include "../final/fillit.h"
#include "../final/libft/libft.h"

void	print_cage(t_dance *head);
int		find_max_low_dgtnum(const int *figure);
void 	print_arr(int **arr, int numfig);
void 	print_list(t_dance *head);
void	recursion_test(t_dance *sp);
void 	print_sp2(t_dance *head);
void 	print_sp(t_dance *head);

#endif //FILL_FUNC_FOR_TESTS_H
