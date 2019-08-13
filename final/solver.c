#include "fillit.h"

static void		open_opt(t_dance *it)
{
	t_dance *curr;

	curr = it->right;
	while (curr->name != 's')
	{
		curr->up->down = curr;
		curr->down->up = curr;
		curr = curr->right;
	}
	curr = it->left;
	while (curr->name != 's')
	{
		curr->up->down = curr;
		curr->down->up = curr;
		curr = curr->left;
	}
}

void			open_row_opt(t_dance *spacer)
{
	t_dance *opt;
	t_dance *curr;

	opt = spacer->right;
	while (opt->name != 's')
	{
		curr = opt;
		while (curr->name == spacer->right->name)
			curr = curr->down;
		while (curr != opt->home)
		{
			curr->spacer->up->down = curr->spacer;
			curr->spacer->down->up = curr->spacer;
			open_opt(curr);
			curr = curr->down;
		}
		opt = opt->right;
	}
}

static void		hide_opt(t_dance *it)
{
	t_dance *curr;

	curr = it->right;
	while (curr->name != 's')
	{
		curr->up->down = curr->down;
		curr->down->up = curr->up;
		curr = curr->right;
	}
	curr = it->left;
	while (curr->name != 's')
	{
		curr->up->down = curr->down;
		curr->down->up = curr->up;
		curr = curr->left;
	}
}

void			hide_row_opt(t_dance *opt)
{
	t_dance *curr;

	while (opt->name != 's')
	{
		curr = opt;
		while (curr->name == opt->name)
			curr = curr->down;
		while (curr != opt->home)
		{
			curr->spacer->up->down = curr->spacer->down;
			curr->spacer->down->up = curr->spacer->up;
			hide_opt(curr);
			curr = curr->down;
		}
		opt = opt->right;
	}
}

_Bool			solver(t_dance *spacer, int numfig, char **sol_map)
{
	t_dance		*nsp;
	static int	counter;

	++counter;
	/*printf("Enter counter = %d, spacer = %d\n", counter, spacer->coord);
	print_sp(spacer->home);*/
	if (counter == numfig)
		return (fill_opt_to_sol_map(spacer->right, sol_map));
	else
	{
		hide_row_opt(spacer->right);
		/*printf("\tAfter hide\n");
		print_sp(spacer->home);*/
		nsp = find_next_spacer(spacer);
		if (!check_recursion(&spacer, &nsp, counter))
			return (0);
		while (!solver(nsp, numfig, sol_map))
		{
			if (nsp->down->right && nsp->down->right->name == nsp->right->name)
				nsp = nsp->down;
			else
				return (backtrack(spacer, &counter, 1));
		}
	}
	return (fill_opt_to_sol_map(spacer->right, sol_map));
}
