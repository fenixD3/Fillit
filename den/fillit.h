/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:52:29 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/11 03:14:34 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 550
# define LEAD_DIGT 100
# include "libft/libft.h"
# include "dance.h"
# include "free_manager.h"

#include <stdio.h>


void	ft_mkerr();
int 	ft_readfile(char *filename, char **line, int *side);
int		**mkfig_arr(const char *line, int numfig);
void	move_to_zero(int *figure);
void	free_arrfig(int ***figures, int n);
void	free_sol_map(char ***sol_map, int n);
void filling_list(t_freem *mem);
int		give_side(int numfig);
<<<<<<< HEAD:den/fillit/fillit.h
_Bool	solver(t_dance *spacer, int numfig, char **sol_map);
_Bool	backtrack(t_dance *spacer, int *counter);
_Bool	fill_opt_sol_map(t_dance *node, char **sol_map);
void	open_row_opt(t_dance *spacer);
_Bool	print_solution(t_dance *spacer, int side);

void	drop_mkfigarr(int **figures, int numfig);

char **create_init_sol_map(t_freem *mem);
_Bool	knuth_solver(t_dance *spacer, int numfig, char **sol_map);
_Bool			solver(t_dance *spacer, int numfig, char **sol_map);
_Bool	print_solution(t_dance *spacer, int side, int counter);

#endif
