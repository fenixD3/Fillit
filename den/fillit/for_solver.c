#include "fillit.h"

_Bool			backtrack(t_dance *spacer, int *counter)
{
	open_row_opt(spacer);
	--(*counter);
	return (0);
}

_Bool fill_opt_sol_map(t_dance *node, char **sol_map)
{
	while (node->name != 's')
	{
		sol_map[node->coord / LEAD_DIGT - 1][node->coord % LEAD_DIGT - 1]
				= node->name;
		node = node->right;
	}
	return (1);
}
