//
// Created by Mort Deanne on 2019-07-20.
//

#include "fillit.h"

int		find_indx_of_min_low_order(int *figure)
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

void	move2zero(int *figure)
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
	move2zero(figure - 4);
	return (figure - 4);
}

void	clean_arrfigs(int **figures, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(figures[i]);
//		figures[i] = NULL;
		i++;
	}
	free(figures);
	figures = NULL;
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
			clean_arrfigs(figures, i);
			ft_mkerr();
		}
		line += 21;
		i++;
	}
	*figures = mkfig(line);
	return (figures);
}
