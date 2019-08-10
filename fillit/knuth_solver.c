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
	bad_options(spacer->right, open_option);
	(*counter)--;
	return (0);
}

int		knuth_check(t_dance *spacer, int numfig, int *counter, char **sol_map)
{
	if (*counter == numfig /*&& spacer->right*/)
		return (fill_opt_to_sol_map(spacer->right, sol_map));
	else if (spacer->right)
		bad_options(spacer->right, hide_option);
	else if (!spacer->right)
		return (prepare_backtrack(spacer, counter));
	return (2);
}

int next_char(t_dance *spacer, t_dance **curr, int *counter, int numfig, char **sol_map)
{
	if (spacer->down->right && spacer->right->name == spacer->down->right->name)
	{
		*curr = spacer->down;
		while ((*curr)->right && !((*curr)->up->right->name - (*curr)->right->name))
			*curr = (*curr)->down;
		if ((!(*curr)->down->right && (*curr)->right->name -
							(*curr)->up->right->name != 1) || !(*curr)->right)
			return (prepare_backtrack(spacer, counter));
	}
	else if (spacer->down->right && *counter + 1 == numfig &&
						spacer->right->name + 1 == spacer->down->right->name)
	{
		*counter++;
		return (fill_opt_to_sol_map(spacer->down->right, sol_map));
	}
	else
		return (prepare_backtrack(spacer, counter));
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
	if ((tmp = next_char(spacer, &curr, &counter, numfig, sol_map)) == 1)
		return (1);
	if (!tmp)
		return (0);
	while (1)
	{
		if (!knuth_solver(curr, numfig, sol_map))
		{
			if (curr->down->right && curr->down->right->name == curr->right->name)
				curr = curr->down;
			else
				return (prepare_backtrack(spacer, &counter));
		}
		if (counter == numfig && spacer->right)
			return (fill_opt_to_sol_map(spacer->right, sol_map));
	}
}
