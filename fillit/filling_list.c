//
// Created by Mort Deanne on 2019-07-21.
//

#include "fillit.h"
#include "dance.h"

int 	fill_row(int *figure, int step, const char n_name, t_dance *head)
{
	int i;
	t_dance *curr;
	t_dance *prev;
	t_dance *new;

	i = 0;
	curr = head;
	prev = head->up;
	while (i < 4)
	{
		while (curr->coord != figure[i] + step)
			curr = curr->right;
		if (!(new = create_connct(prev, NULL, curr->up, curr)) ||
		!node_set_params(new, &n_name, figure[i] + step, head->up->jump + 1))
			return (0);
		prev = prev->right;
		i++;
	}
	if (!(add_spacer(&head, create("Sp", 1), 0, &new)))
		return (0);
	new->right->left = new;
	return (1);
}

int		find_max_low_dgtnum(const int *figure)
{
	int lowdn;
	int i;

	lowdn = 0;
	i = 0;
	while (i < 4)
	{
		if (figure[i] % LEAD_DIGT > lowdn)
			lowdn = figure[i] % LEAD_DIGT;
		i++;
	}
	return (lowdn);
}


void 	filling_list(int **figures, int numfig, t_dance *head, int side)
{
	int i;
	int lowdn; //max low digit number
	int highdn; //max high digit number
	int step;

	i = 0;
	step = 0;
	while (i < numfig)
	{
		lowdn = find_max_low_dgtnum(figures[i]);
		highdn = figures[i][3] / LEAD_DIGT;
		while (highdn <= side)
		{
			if (lowdn + step <= side)
				fill_row(figures[i], step++, ((char) i + 'A'), head); /// if (!) clear list
			else if (highdn < side)
			{
				step = 0;
				while (step < 4)
					figures[i][step++] += LEAD_DIGT;
				step = 0;
				highdn++;
			}
			else if (highdn == side)
				break ;
		}
		i++;
	}
}