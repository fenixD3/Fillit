//
// Created by Mort Deanne on 2019-08-06.
//

#include "fillit.h"


_Bool	fill_opt_to_sol_map(t_dance *node, char **sol_map)
{
	while (node->name != 's')
	{
		sol_map[node->coord / LEAD_DIGT - 1][node->coord % LEAD_DIGT - 1]
				= node->name;
		node = node->right;
	}
	return (1);
}

_Bool	prepare_backtrack(t_dance *spacer, int *counter)
{
	(*counter)--;
	bad_options(spacer->right, open_option);
	return (1);
}

_Bool	next_char(t_dance *spacer, t_dance **curr, int *counter)
{
	if (spacer->down->right && spacer->right->name == spacer->down->right->name)
	{
		*curr = spacer->down;
		while (!((*curr)->up->right->name - (*curr)->right->name))
			*curr = (*curr)->down;
		if ((*curr)->right->name - (*curr)->up->right->name != 1)
			if (prepare_backtrack(spacer, counter))
				return (0);
	}
	else
	if (prepare_backtrack(spacer, counter))
		return (0);
	return (1);
}

int		knuth_check(t_dance *spacer, int numfig, int *counter, char **sol_map)
{
	if (*counter == numfig && spacer->right)
		return (fill_opt_to_sol_map(spacer->right, sol_map));
	else if (spacer->right)
		bad_options(spacer->right, hide_option);
	else if (!spacer->right)
		if (prepare_backtrack(spacer, counter))
			return (0);
	return (2);
}

_Bool	knuth_solver(t_dance *spacer, int numfig, char **sol_map)
{
	static int	counter;
	t_dance		*curr;
	int 		tmp;

	counter++;
	if (!(tmp = knuth_check(spacer, numfig, &counter, sol_map)))
		return (0);
	else if (tmp == 1)
		return (1);
	if (!next_char(spacer, &curr, &counter))
		return (0);
	while (1)
	{
		if (!knuth_solver(curr, numfig, sol_map))
		{
			if (curr->down->right->name == curr->right->name)
				curr = curr->down;
			else
				if (prepare_backtrack(spacer, &counter))
					return (0);
		}
		if (counter == numfig && spacer->right)
			return (fill_opt_to_sol_map(spacer->right, sol_map));
	}
}

/*_Bool	knuth_solver(t_dance *spacer, int numfig, char **sol_map)
{
	static int	counter;
	t_dance		*curr;

	counter++;
	if (counter == numfig *//**&& spacer->right*//*)
		return (fill_opt_to_sol_map(spacer->right, sol_map));
	else if (spacer->right)
		bad_options(spacer->right, hide_option);
	else if (!spacer->right)
		if (prepare_backtrack(spacer, &counter))
			return (0);
	if (spacer->down->right && spacer->right->name == spacer->down->right->name)
	{
		curr = spacer->down;
		while (!(curr->up->right->name - curr->right->name))
			curr = curr->down;
		if (curr->right->name - curr->up->right->name != 1)
			if (prepare_backtrack(spacer, &counter))
				return (0);
	}
	else
		if (prepare_backtrack(spacer, &counter))
			return (0);
	while (1)
	{
		if (!knuth_solver(curr, numfig, sol_map))
		{
			if (curr->down->right->name == curr->right->name)
				curr = curr->down;
			else
				if (prepare_backtrack(spacer, &counter))
					return (0);
		}
		if (counter == numfig *//**&& spacer->right*//*)
		{
			fill_opt_to_sol_map(spacer->right, sol_map);
			return (1);
		}
	}
}*/