//
// Created by Mort Deanne on 2019-07-26.
//

#include "dance.h"
#include "fillit.h"

#include "../tests/func_for_tests.h" ///delete this

int		increase_cage(t_dance *head, int old_side)
{
	t_dance *curr;

	curr = head->right;
	while (curr != head)
	{
		if (curr->coord % LEAD_DIGT == old_side)
			if (!add_cage(curr, (curr->right), create("Cl", curr->coord + 1)))
				return (0);
		curr = curr->right;
	}
	if (!add_cage(head->left, head,
			create("Cl", (old_side + 1) * LEAD_DIGT + 1)))
		return (0);
	curr = head->left;
	while (old_side--)
	{
		if (!add_cage(head->left, head, create("Cl", curr->coord + 1)))
			return (0);
		curr = head->left;
	}
	return (1);
}

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
	left_sp->down)) || !node_set_params(n_sp, "Sp", left_sp->coord + 1, n_sp))
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

int 	incr_row_n_lines(t_dance *left_sp, int *lines)
{
	if (!add_increase_row(left_sp))
		return (0);
	lines[(left_sp->right->name)[0] - 'A'] = left_sp->coord;
	return (1);
}

int add_increase_middle_rows(t_dance *head, int old_side, int numfig)
{
	int		*lines;
	t_dance	*head_curr;
	t_dance *curr;


	if (!(lines = (int*)ft_memalloc(sizeof(int) * numfig)))
		return (0);
	head_curr = head->right;
	while (head_curr != head)
	{
		if (head_curr->coord % LEAD_DIGT == old_side)
		{
			curr = head_curr->down;
			while (curr != head_curr)
			{
				if ((lines[(curr->name)[0] - 'A'] < curr->spacer->coord)
					&& (!(incr_row_n_lines(curr->spacer, lines))))
						return (0);
				curr = curr->down;
			}
		}
		head_curr = head_curr->right;
	}
	return (1);
}
