#include "fillit.h"

_Bool			backtrack(t_dance *spacer, int *counter, _Bool decrement)
{
	open_row_opt(spacer);
	/*printf("\tAfter open\n");
	print_sp(spacer->home);*/
	if (decrement)
		--(*counter);
	return (0);
}

t_dance		*find_next_spacer(t_dance *spacer)
{
	t_dance *nsp;

	nsp = spacer;
	while (nsp->right && nsp->right->name == spacer->right->name)
		nsp = nsp->down;
	return (nsp);
}

_Bool		check_recursion(t_dance **spacer, t_dance **nsp, int counter)
{
	if ((!(*nsp)->down->right &&
	(*nsp)->right->name - (*spacer)->right->name != 1) || !(*nsp)->right)
	{
		if (counter == 1)
		{
			open_row_opt(*spacer);
			if ((*spacer)->down->right &&
			(*spacer)->down->right->name == (*spacer)->right->name)
			{
				*spacer = (*spacer)->down;
				hide_row_opt((*spacer)->right);
				*nsp = find_next_spacer(*spacer);
				check_recursion(spacer, nsp, counter);
			}
		}
		else
			return (backtrack(*spacer, &counter, 1));
	}
	return (1);
}
