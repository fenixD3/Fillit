#include "dance.h"
#include "fillit.h"

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

_Bool			solver(t_dance *head, t_dance *spacer, int numfig, int counter)
{
/* This func receives counter equal to 1 from main */
	t_dance *opt;

	hide_spacers(spacer);
	opt = spacer->right;
	while (counter != numfig && opt != spacer->down)
		opt = hide_option(opt);	
	if (counter == numfig)
		return (1);
	if (!spacer->down->right)
	{
		open_rows(spacer);
		return (0);
	}
	spacer = spacer->down;
	while (!solver(head, spacer, numfig, ++counter))
		spacer = spacer->down;
	return (1);
}
