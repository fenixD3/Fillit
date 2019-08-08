#include "fillit.h"

void	print_spacers(t_dance *head)
{
	t_dance *curr = head->down;
	while (curr != head)
	{
		printf("%d, ",curr->coord);
		curr = curr->down;
	}
	printf("\n");
}

static _Bool fill_opt_sol_map(t_dance *node, char **sol_map)
{
	while (node->name != 's')
	{
		sol_map[node->coord / LEAD_DIGT - 1][node->coord % LEAD_DIGT - 1]
		= node->name;
		node = node->right;
	}
	return (1);
}

static void		open_opt(t_dance *it)
{
	t_dance *lft;

	lft = it->left;
	it = it->right;
	while (1)
	{
		if (it->name == 's' && lft->name == 's')
			break ;
		if (it->name != 's')
		{
			if (it->up->down != it || it->down->up != it)
			{
				it->up->down = it;
				it->down->up = it;
			}
			it = it->right;
		}
		if (lft->name != 's')
		{
			if (lft->up->down != lft || lft->down->up != lft)
			{
				lft->up->down = lft;
				lft->down->up = lft;
			}
			lft = lft->left;
		}
	}
}

static void		open_row_opt(t_dance *spacer)
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
			if (curr->spacer->up->down != curr->spacer ||
				curr->spacer->down->up != curr->spacer)
			{
				curr->spacer->up->down = curr->spacer;
				curr->spacer->down->up = curr->spacer;
			}
			/*printf("\t\tOpen rows. Opt coord: %d Curr name: %c Curr space: %d\n\t", opt->coord, curr->name, curr->spacer->coord);
			print_spacers(spacer->home);*/
			open_opt(curr);
			curr = curr->down;
		}
		opt = opt->right;
	}
}

static void		hide_opt(t_dance *it)
{
	t_dance *lft;

	lft = it->left;
	it = it->right;
	while (1)
	{
		if (it->name == 's' && lft->name == 's')
			break ;
		if (it->name != 's')
		{
			if (it->up->down == it && it->down->up == it)
			{
				it->up->down = it->down;
				it->down->up = it->up;
			}
			it = it->right;
		}
		if (lft->name != 's')
		{
			if (lft->up->down == lft && lft->down->up == lft)
			{
				lft->up->down = lft->down;
				lft->down->up = lft->up;
			}
			lft = lft->left;
		}
	}
}

static t_dance	*hide_row_opt(t_dance *opt)
{
/* Reduce each row corresponding to each option at this column, where
 * opt pointer is pointing, leaving out options with name == opt->name
 */
	t_dance *curr;
	t_dance *it;

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
		hide_opt(curr);
		curr = curr->down;
	}
	return (opt->right);
}

_Bool			solver(t_dance *spacer, int numfig, char **sol_map, int side)
{
/* This func receives counter equal to 1 from main */
	t_dance		*opt;
	static int	counter;

	++counter;
	printf("Recursion num = %d, Spacer = %d\n", counter, spacer->coord);
	/*printf("\tEnter\n");
	print_spacers(spacer->home);*/
	if (counter == numfig)
	{
		printf("Spacer coord : %d\n", spacer->coord);
		return (fill_opt_sol_map(spacer->right, sol_map));
	}
	else
	{
		opt = spacer->right;
		while (opt->name != 's')
			opt = hide_row_opt(opt);
		/*printf("\tAfter hide\n");
		print_spacers(spacer->home);*/
		opt = spacer;
		while (opt->down->right && opt->down->right->name == opt->right->name)
			opt = opt->down;
		if (opt->down->right && opt->down->right->name - opt->right->name == 1)
			opt = opt->down;
		if (!opt->right || !opt->down->right)
		{
			open_row_opt(spacer);
			/*printf("\tAfter open\n");
			print_spacers(spacer->home);*/
			--counter;
			return (0);
		}
		while (!solver(opt, numfig, sol_map, side))
		{
			if (opt->down->right->name == opt->right->name)
				opt = opt->down;
			else
			{
				open_row_opt(spacer);
				--counter;
				return (0);
			}
		}
	}
	printf("Spacer coord : %d\n", spacer->coord);
	return (fill_opt_sol_map(spacer->right, sol_map));
}