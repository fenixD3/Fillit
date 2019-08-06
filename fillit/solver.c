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
	while (curr->right && curr->right->name == spacer->right->name)
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

_Bool			solver(t_dance *spacer, int numfig, int counter, int side)
{
/* This func receives counter equal to 1 from main */
	t_dance *opt;

printf("Sp row : %d, Recursion num = %d\n", spacer->coord, counter);
printf("\tFirst step\n");
print_spacers(spacer->home);
	hide_spacers(spacer);
printf("\tAfter hide_spacers\n");
print_spacers(spacer->home);
	opt = spacer->right;
	while (counter != numfig && opt->name != 's')
		opt = hide_option(opt);
printf("\tAfter hide_option\n");
print_spacers(spacer->home);
	if (counter == numfig)
		return (print_solution(spacer->home->down, side, counter - 1));
	if (!spacer->down->right)
	{
		open_rows(spacer);
		return (0);
	}
	spacer = spacer->down;
	++counter;
	while (!solver(spacer, numfig, counter, side))
	{
		if (spacer->down->right->name == spacer->right->name)
			spacer = spacer->down;
		else
			return (0);
	}
	return (1);
}
