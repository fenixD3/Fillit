#include "fillit.h"
#include <unistd.h>

static char	**create_init_sol_map(int side)
{
	char	**sol_map;
	int		i;
	int		j;

	if (!(sol_map = (char **)malloc(sizeof(char *) * side)))
		; // add free_list
	i = -1;
	while (++i < side)
	{
		j = -1;
		if (!(sol_map[i] = (char *)malloc(sizeof(char) * side)))
			; // add free_array & free_list
		while(++j < side)
			sol_map[i][j] = '.';
	}
	return (sol_map);
}

static void	fill_sol_map(char **sol_map, t_dance *spacer)
{
	t_dance	*curr;

	while (spacer->right)
	{
		curr = spacer->right;
		while (curr->name != 's')
		{
			sol_map[curr->coord / LEAD_DIGT - 1][curr->coord % LEAD_DIGT - 1]
			= curr->name;
			curr = curr->right;
		}
		spacer = spacer->down;
	}
}

_Bool		print_solution(t_dance *spacer, int side, int counter)
{
	char	**sol_map;
	int		i;
	int		j;

	sol_map = create_init_sol_map(side);
	fill_sol_map(sol_map, spacer);
	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
			write(1, &sol_map[i][j], 1);
		if (i < side)
			write (1, "\n", 1);
	}
	return (1);
}
