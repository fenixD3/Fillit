#include "dance.h"
#include "fillit.h"

/* static t_dance	*find_fst_spacer(t_dance *head, char fined_name)
{
	t_dance *spacer;
	t_dance *nxt_spacer;

	spacer = head->down;
	while (spacer->right->name != fined_name)
		spacer = spacer->down;

	return (spacer);
} */

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

static _Bool	print_solution(t_dance *head);

_Bool			solver(t_dance *head, t_dance *spacer, int numfig, int counter)
{
/* This func receives counter equal to 1 from main */
	t_dance	*opt;
	// t_dance	*spacer;
	// char	fined_name;

	/* if (!spacer->right)
		return (0); */
	/* if (spacer->right && counter == numfig)
		return (print_solution(head)); */
	// fined_name = 'A' + counter;
	// spacer = find_fst_spacer(head, fined_name);
	hide_spacers(spacer);
	opt = spacer->right;
	while (counter != numfig && opt != spacer->down)
		opt = hide_option(opt);
	spacer = spacer->down;
	if (counter == numfig)
		return (print_solution(head)); // return (1);
	if (!spacer->right)
		// Add opening hided rows before backtrack!
		return (0);
	/* if (!solver(head, spacer, numfig, ++counter))
		solver(head, spacer->down, numfig, counter); */
	while (!solver(head, spacer, numfig, ++counter))
		spacer = spacer->down;
}
