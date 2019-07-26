//
// Created by Mort Deanne on 2019-07-26.
//

#include "dance.h"
#include "fillit.h"

#include "../tests/func_for_tests.h" ///delete this

int		increase_cage(t_dance *head, int side)
{
	t_dance *curr;

	curr = head->right;
	while (curr != head)
	{
		if (curr->coord % LEAD_DIGT == side)
			if (!add_cage(curr, (curr->right), create("Cl", curr->coord + 1)))
				return (0);
		curr = curr->right;
	}
	if (!add_cage(head->left, head, create("Cl", (side + 1) * LEAD_DIGT + 1)))
		return (0);
	curr = head->left;
	while (side--)
	{
		if (!add_cage(head->left, head, create("Cl", curr->coord + 1)))
			return (0);
		curr = head->left;
	}
	return (1);
}

int 	increase_row(t_dance *lspacer)
{
	t_dance *rspacer;


}

/*
int 	increase_middle_rows(t_dance *head, int side)
{

}*/
