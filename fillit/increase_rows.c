//
// Created by Mort Deanne on 2019-07-28.
//

#include "fillit.h"

void	increment_down_rownum(t_dance *curr)
{
	while (curr->coord != 0)
	{
		curr->coord++;
		curr = curr->down;
	}
}

int 	add_increase_row(t_dance *left_sp)
{
	t_dance *n_sp;
	t_dance *curr;
	t_dance *prev;

	if (!(n_sp = create_connct(left_sp->down->left, left_sp->down, left_sp,
			left_sp->down)) ||
			!node_set_params(n_sp, "Sp", left_sp->coord + 1, n_sp))
		return (0);
	prev = n_sp;
	while (left_sp->right != n_sp)
	{
		left_sp = left_sp->right;
		curr = left_sp->home->right->down;
		while (curr->spacer->coord < n_sp->coord - 1)
			curr = curr->down;
		if (!(curr = create_connct(prev, n_sp->down, curr->up, curr)) ||
			!node_set_params(curr, left_sp->name, curr->up->coord, n_sp))
			return (0);
		curr->home = left_sp->home->right;
		curr->spacer = n_sp;
		prev = prev->right;
	}
	increment_down_rownum(n_sp->down);
	return (1);
}

int 	incr_row_n_lines(t_dance *left_sp, int *lines, int side)
{
	int 	flag;
	t_dance	*curr;

	if (!add_increase_row(left_sp))
		return (0);
	flag = 0;
	curr = left_sp->down;
	while (curr != left_sp->down->down)
	{
		if (curr->coord % LEAD_DIGT == side - 1)
			flag++;
		curr = curr->right;
	}
	lines[(left_sp->right->name)[0] - 'A'] =
			(flag ? left_sp->down->coord : left_sp->coord);
	return (1);
}

int add_increase_middle_rows(t_dance *head, int side, int numfig)
{
	int		*lines;
	t_dance	*head_curr;
	t_dance *curr;


	if (!(lines = (int*)ft_memalloc(sizeof(int) * numfig)))
		return (0);
	head_curr = head->right;
	while (head_curr != head)
	{
		if (head_curr->coord % LEAD_DIGT == side - 1)
		{
			curr = head_curr->down;
			while (curr != head_curr)
			{
				if ((lines[(curr->name)[0] - 'A'] < curr->spacer->coord)
					&& (!(incr_row_n_lines(curr->spacer, lines, side))))
					return (0);
				curr = curr->down;
			}
		}
		head_curr = head_curr->right;
	}
	free(lines);
	return (1);
}
