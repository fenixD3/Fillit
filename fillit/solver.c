#include "fillit.h"
#include <unistd.h>

static t_dance	*hide_option(t_dance *opt)
{
/* Reduce each row corresponding to each option at this column, where
 * opt pointer is pointing, leaving out options with name == opt->name
 */
	t_dance *curr;

	curr = opt;
	while (curr->name == opt->name)
		curr = curr->down;
	while (curr != opt->home)
	{
		if (curr->spacer->up->down == curr->spacer &&
		curr->spacer->down->up == curr->spacer)
		{
			curr->spacer->up->down = curr->spacer->down;
			curr->spacer->down->up = curr->spacer->up;
		}
		curr = curr->down;
	}
	return (opt->right);
}

static void		hide_spacers(t_dance *spacer)
{
	t_dance *curr;

	curr = spacer->down;
	while (curr->right->name == spacer->right->name)
		curr = curr->down;
	spacer->down = curr;
	curr->up = spacer;
	curr = spacer->up;
	while (curr->right->name == spacer->right->name)
		curr = curr->up;
	spacer->up = curr;
	curr->down = spacer;
}

static void		open_spacers(t_dance *spacer, t_dance *curr)
{
	spacer->down = curr;
	while (curr->down->right && curr->down->right->name == spacer->right->name)
		curr = curr->down;
	curr->down->up = curr;
	curr = spacer->left;
	while (curr->name != 's')
		curr = curr->left;
	if (curr->down != spacer)
	{
		spacer->up = curr;
		while (curr->up->right->name == spacer->right->name)
			curr = curr->up;
		curr->up->down = curr;
	}
}
static void		open_rows(t_dance *spacer)
{
	t_dance *opt;
	t_dance *curr;

	opt = spacer->right;
	while (opt->name != 's')
	{
		curr = opt->down;
		while (curr != opt->home)
		{
			if (curr->spacer->up->down != curr->spacer &&
			curr->spacer->down->up != curr->spacer)
			{
				curr->spacer->up->down = curr->spacer;
				curr->spacer->down->up = curr->spacer;
			}
			curr = curr->down;
		}
		opt = opt->right;
	}
	open_spacers(spacer, opt);
}

static _Bool		print_solution(t_dance *spacer, int side, int counter)
{
	char	**sol_map; //
	t_dance	*curr;
	int		i;
	int		j;

	sol_map = (char **)malloc(sizeof(char *) * side);
	i = -1;
	while (++i < side)
	{
		j = -1;
		sol_map[i] = (char *)malloc(sizeof(char) * side);
		while(++j < side)
			sol_map[i][j] = '.';
	}
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
	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
			write(1, &sol_map[i][j], 1);
		if (i < side - 1)
			write (1, "\n", 1);
	}
	return (1);
}

_Bool			solver(t_dance *spacer, int numfig, int counter, int side)
{
/* This func receives counter equal to 1 from main */
	t_dance *opt;
	static int i;
	++i;
	hide_spacers(spacer);
	opt = spacer->right;
	while (counter != numfig && opt->name != 's')
		opt = hide_option(opt);
	if (counter == numfig)
		return (print_solution(spacer->home->down, side, counter - 1));
	if (!spacer->down->right)
	{
		open_rows(spacer);
		i--;
		return (0);
	}
	spacer = spacer->down;
	while (!solver(spacer, numfig, ++counter, side))
		spacer = spacer->down;
	return (1);
}
