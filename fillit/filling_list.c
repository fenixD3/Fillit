//
// Created by Mort Deanne on 2019-07-21.
//

#include "fillit.h"
#include "dance.h"

int 	fill_row(int *figure, int step, const char *n_name, t_dance *head)
{
	int i;
	t_dance *curr;
	t_dance *prev;
	t_dance *new;

	i = 0;
	curr = head;
	prev = head->up;
	while (i != 5)
	{
		while (curr->coord != figure[i] + step)
			curr = curr->right;
		if (!(new = create_connct(prev, NULL, curr->up, curr)) ||
		!node_set_params(new, n_name, figure[i] + step, head->up->jump + 1))
			return (0);
		i++;
	}
	if (!(add_spacer(&head, create("Sp", 1), 1, &curr)))
		return (0);

}
void 	filling_list(int **figures, int numfig, t_dance *head)
{
	while (numfig--)
	{

	}
}