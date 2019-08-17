/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkfig_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:57:08 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/11 02:15:23 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	drop_mkfigarr(int **figures, int numfig)
{
	int i;

	i = 0;
	while (i < numfig)
	{
		move_to_zero(figures[i]);
		i++;
	}
}

int		*mkfig(const char *line)
{
	int		*figure;
	int		i;
	int		j;

	if (!(figure = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	j = 1;
	while (j < 5)
	{
		i = 1;
		while (i < 6)
		{
			if (*line == '#')
				*(figure++) = j * LEAD_DIGT + i;
			if (i * j == 20)
				break ;
			line++;
			i++;
		}
		j++;
	}
	return (figure - 4);
}

int		**mkfig_arr(const char *line, int numfig)
{
	int		**figures;
	int		i;

	if (!(figures = (int**)malloc(sizeof(int*) * numfig)))
		ft_mkerr();
	i = 0;
	while (i < numfig)
	{
		if (!((figures[i]) = mkfig(line)))
		{
			free_arrfig(NULL);
			ft_mkerr();
		}
		move_to_zero(figures[i]);
		line += 21;
		i++;
	}
	return (figures);
}
