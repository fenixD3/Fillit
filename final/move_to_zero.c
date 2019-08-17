/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:00:02 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/17 21:00:04 by mdeanne          ###   ########.fr       */
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

void	increase_arrfig(int *figure)
{
	int i;

	i = 0;
	while (i != 4)
		figure[i++] += LEAD_DIGT;
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
		if (figure[i++] < 0)
			flag = 1;
	if (flag == 1)
		increase_arrfig(figure);
	flag = 0;
	i = 0;
	while (i != 4)
		if (figure[i++] / LEAD_DIGT == 0)
			flag = 1;
	if (flag == 1)
		increase_arrfig(figure);
}
