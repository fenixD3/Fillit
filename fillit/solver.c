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

static void		open_rows(t_dance *spacer)
{
	t_dance *opt;
	t_dance *curr;

	opt = spacer->right;
	while (opt != spacer->down)
	{
		curr = opt->down;
		while (curr != opt->home)
		{
			if (curr->spacer->up->down != curr->spacer &&
			curr->sapcer->down->up != curr->sapcer)
			{
				curr->spacer->up->down = curr->spacer;
				curr->spacer->down->up = curr->spacer;
			}
			curr = curr->down;
		}
		opt = opt->right;
	}
}

static _Bool		print_solution(t_dance *opt, int side, int counter)
{
	char	sol_map[side][side];
	int		i;
	int		j;

	while (opt->right)
	{
		if (opt->name != 's')
			sol_map[opt->coord / LEAD_DIGT][opt->coord % LEAD_DIGT] = opt->name;
		opt = opt->right;
	}
	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
		{
			if (sol_map[i][j] >= 'A' && sol_map[i][j] <= 'A' + counter)
				write(&sol_map[i][j], 1);
			else
				write(".", 1);
		}
		if (i < side - 1)
			write ("\n", 1);
	}
	return (1);
}

_Bool			solver(t_dance *spacer, int numfig, int counter, int side)
{
/* This func receives counter equal to 1 from main */
	t_dance *opt;

	hide_spacers(spacer);
	opt = spacer->right;
	while (counter != numfig && opt != spacer->down)
		opt = hide_option(opt);
	if (counter == numfig)
		return (print_solution(spacer->home->down->right, side, counter));
	if (!spacer->down->right)
	{
		open_rows(spacer);
		return (0);
	}
	spacer = spacer->down;
	while (!solver(spacer, numfig, ++counter))
		spacer = spacer->down;
	return (1);
}
