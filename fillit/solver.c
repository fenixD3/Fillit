#include "dance.h"
#include "fillit.h"

/* static void	reduce_row(t_dance *opt)
{
	;
} */

/* static void	reduce_options(t_dance *spacer, char name)
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
} */

/* void		solver(t_dance *head, t_dance *spacer, int numfig)
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
} */

static t_dance	*find_fst_spacer(t_dance *head, char fined_name)
{
	t_dance *spacer;
	t_dance *nxt_spacer;

	spacer = head->down;
	while (spacer->right->name != fined_name)
		spacer = spacer->down;

	return (spacer);
}

static t_dance	*reduce_option(t_dance *opt)
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

void			solver(t_dance *head, int numfig, int side, int counter)
{
	t_dance	*opt;
	t_dance	*spacer;
	char	fined_name;

	if (spacer->right && counter == numfig)
		return (print_solution(head)); // schribe
	fined_name = 'A' + counter;
	spacer = find_fst_spacer(head, fined_name);
	opt = spacer->right;
	while (opt != spacer->down)
		opt = reduce_option(opt);
	solver(head, numfig, side, ++counter);
}
