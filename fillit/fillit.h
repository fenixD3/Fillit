/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:52:29 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/07 18:52:35 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 550
# define LEAD_DIGT 100
# include "libft/libft.h"
# include "dance.h"

#include <stdio.h>


void	ft_mkerr();
int		ft_readfile(char *filename, char **line);
int		**mkfig_arr(const char *line, int numfig);
void	free_array(int **figures, int n);
void 	filling_list(int **figures, int numfig, t_dance *head, int side);
int		give_side(int numfig);


char	**create_init_sol_map(int side);
_Bool	knuth_solver(t_dance *spacer, int numfig, char **sol_map);

#endif
