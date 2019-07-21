//
// Created by Mort Deanne on 2019-07-21.
//

#include "fillit.h"
#include "dance.h"

int 	fill_row(int *figure, int step, const char *n_name, t_dance *curr)
{
	int i;

	i = 0;
	while (i != 5)
	{
		while (curr->coord != figure[i])
			curr = curr->right;

	}
}

void 	filling_list(int **figures, int numfig, t_dance *head)
{
	while (numfig--)
	{

	}
}