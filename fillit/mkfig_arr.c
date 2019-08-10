/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkfig_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:57:08 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/10 07:19:45 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_indx_of_min_low_order(const int *figure)
{
	int i;
	int minloworder;
	int imin;

	i = 1;
	minloworder = figure[0] % LEAD_DIGT;
	imin = 0;
	while (i != 4)
	{
		if (minloworder > figure[i] % LEAD_DIGT)
		{
			minloworder = figure[i] % LEAD_DIGT;
			imin = i;
		}
		i++;
	}
	return (imin);
}

void	move_to_zero(int *figure)
{
	int i;
	int difference;
	int flag;

	difference = figure[find_indx_of_min_low_order(figure)] - (LEAD_DIGT + 1);
	i = 0;
	while (i != 4)
		figure[i++] -= difference;
	flag = 0;
	i = 0;
	while (i != 4)
		if (figure[i++] / LEAD_DIGT == 0)
			flag = 1;
	if (flag == 1)
	{
		i = 0;
		while (i != 4)
			figure[i++] += LEAD_DIGT;
	}
}

void	drop_mkfigarr(int **figures, int numfig)
{
	int i = 0;
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
	//move_to_zero(figure - 4); /// зачем это здесь?
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
			free_arrfig(&figures, i);
			ft_mkerr();
		}
		move_to_zero(figures[i]);
		line += 21;
		i++;
	}
	return (figures);
}
