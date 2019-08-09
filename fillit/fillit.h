//
// Created by Mort Deanne on 2019-07-16.
//

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 550
# define LEAD_DIGT 100
# include "libft/libft.h" /// wrong (should be only libft.h!!!)
# include "dance.h"

#include <stdio.h>


void	ft_mkerr();
int		ft_readfile(char *filename, char **line);
int		**mkfig_arr(const char *line, int numfig);
void	free_arrfigs(int **figures, int n);
void 	filling_list(int **figures, int numfig, t_dance *head, int side);
int		give_side(int numfig);
//_Bool	solver(t_dance *spacer, int numfig, int counter, int side);
_Bool			solver(t_dance *spacer, int numfig, char **sol_map);
//_Bool filL_opt_sol_map(t_dance *node, char **sol_map);


_Bool	print_solution(t_dance *spacer, int side, int counter);

#endif
