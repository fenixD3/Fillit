#include "dance.h"

static void	reduce_row(t_dance *opt)
{
	;
}

static void	reduce_options(t_dance *spacer, char name)
{
	t_dance	*last;
	t_dance	*opt;

	opt = spacer->right;
	while (opt != spacer->down)
	{
		last = opt->down;
		while (last->name == name)
			last = last->down;
		opt->down = last;
		last->up = opt;
		opt = opt->right;
	}
	while (opt->name == name)
		opt = opt->down;
	spacer->down = opt;
	opt->up = spacer;
}

void		solver(t_dance *head, t_dance *spacer, int numfig)
{
	static int		i;
	t_dance			*opt;

	++i;
	opt = spacer->right;
	reduce_options(spacer, opt->name);
	while (opt != spacer->down)
	{
		reduce_row(opt); // schribe!
		opt = opt->right;
	}
	if (i == numfig)
		print_solution(head); // schribe! mb add any free functions and finish with exit()
	solver(head, spacer->down, numfig);
}
