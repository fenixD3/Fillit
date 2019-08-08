/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:56:22 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/03 22:56:29 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	increment_down_rownum(t_dance *curr)
{
	while (curr->coord != 0)
	{
		curr->coord++;
		curr = curr->down;
	}
}

t_dance	*set_step_for_increase(t_dance *curr,int step)
{
	int i = 0;

	while (i++ < step)
		curr = curr->right;
	return (curr);
}

int 	add_increase_row(t_dance *left_sp, int step)
{
	t_dance *n_sp;
	t_dance *curr;
	t_dance *prev;

	if (!(n_sp = create_connct(left_sp->down->left, left_sp->down, left_sp,
			left_sp->down)))
		return (0);
	node_set_params(n_sp, 's', left_sp->coord + 1, n_sp);
	n_sp->home = n_sp->up->home;
	prev = n_sp;
	while (left_sp->right != n_sp)
	{
		left_sp = left_sp->right;
		curr = set_step_for_increase(left_sp->home, step)->down;
		while (curr->spacer->coord < n_sp->coord - 1)
			curr = curr->down;
		if (!(curr = create_connct(prev, n_sp->down, curr->up, curr)))
			return (0);
		node_set_params(curr, left_sp->name, curr->up->coord, n_sp);
		curr->home = set_step_for_increase(left_sp->home, step);
		curr->spacer = n_sp;
		prev = prev->right;
	}
	increment_down_rownum(n_sp->down);
	return (1);
}

int 	increment_row_n_lines(t_dance *left_sp, int *lines, int side)
{
	int 	flag;
	t_dance	*curr;

	if (!add_increase_row(left_sp, 1))
		return (0);
	flag = 0;
	curr = left_sp->down;
/*	while (curr != left_sp->down->down)
	{
		if (curr->coord % LEAD_DIGT == side - 1)
			flag++;
		curr = curr->right;
	}
	lines[left_sp->right->name - 'A'] =
			(flag ? left_sp->down->coord : left_sp->coord);*/
	lines[left_sp->right->name - 'A'] = left_sp->down->coord;
	return (1);
}

int		lst_find_max_low_dgtnum(t_dance *spacer)
{
	int lowdn;
	int i;

	lowdn = 0;
	i = 0;
	while (i < 4)
	{
		spacer = spacer->right;
		if (spacer->coord % LEAD_DIGT > lowdn)
			lowdn = spacer->coord % LEAD_DIGT;
		i++;
	}
	return (lowdn);
}
