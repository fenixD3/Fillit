//
// Created by Mort Deanne on 2019-07-26.
//

#include "dance.h"
#include "fillit.h"

#include "../tests/func_for_tests.h" ///delete this

int		increase_cage(t_dance *head, int side)
{
	t_dance *curr;

	curr = head->right;
	while (curr != head)
	{
		if (curr->coord % LEAD_DIGT == side - 1)
			if (!add_cage(curr, (curr->right), create("Cl", curr->coord + 1)))
				return (0);
		curr = curr->right;
	}
	if (!add_cage(head->left, head,
			create("Cl", side * LEAD_DIGT + 1)))
		return (0);
	curr = head->left;
	while (side-- - 1)
	{
		if (!add_cage(head->left, head, create("Cl", curr->coord + 1)))
			return (0);
		curr = head->left;
	}
	return (1);
}

int 	add_first_last_row(int *figure, t_dance *head, t_dance *sp_next)
{
	t_dance *n_sp;
	t_dance *curr;
	t_dance *prev;
	int		i;

	if (!(n_sp = create_connct(sp_next->left, sp_next, sp_next->up, sp_next)) ||
		!node_set_params(n_sp, sp_next->name, sp_next->coord, n_sp))
		return (0);
	i = 0;
	prev = n_sp;
	while (n_sp->right != sp_next)
	{
		while (head->coord != figure[i])
			head = head->right;
		curr = head->down;
		while (curr->spacer->coord < sp_next->coord - 1)
			curr = curr->down;
		if (!(curr = create_connct(prev, sp_next, curr->up, curr)) ||
			!node_set_params(curr, curr->up->name, figure[i++], sp_next->up))
			return (0);
		curr->home = head;
		curr->spacer = sp_next->up;
		prev = prev->right;
		n_sp = n_sp->right;
	}
	increment_down_rownum(n_sp->down);
	return (1);
}
//curr, left_sp->name, curr->up->coord, n_sp
int 	add_increase_last_rows(int **figures, t_dance *head,
							  int numfig, int side)
{
	int		i;
	int 	k;
	t_dance	*spacer;

	i = 0;
	while (i < numfig)
	{
		spacer = head->down;
		while ((spacer->right->name)[0] - 'A' - 1 != i) /// так нельзя там есть долбаный пустой спейсер у него имя Sp
			spacer = spacer->down;
		k = 0;
		while (k < 4)
			figures[i][k++] += LEAD_DIGT;
		if (!(add_first_last_row(figures[i], head, spacer)))
			return (0);
		i++;
	}
	return (1);
}
