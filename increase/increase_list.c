/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:56:32 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/10 19:41:03 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit/dance.h"
#include "../fillit/fillit.h"

int		increase_cage(t_dance *head, int side)
{
	t_dance *curr;

	curr = head->right;
	while (curr != head)
	{
		if (curr->coord % LEAD_DIGT == side - 1)
			if (!add_cage(curr, (curr->right), create('c', curr->coord + 1)))
				return (0);
		curr = curr->right;
	}
	if (!add_cage(head->left, head, create('c', side * LEAD_DIGT + 1)))
		return (0);
	curr = head->left;
	while (side-- - 1)
	{
		if (!add_cage(head->left, head, create('c', curr->coord + 1)))
			return (0);
		curr = head->left;
	}
	return (1);
}

///////////////////////
#include "../tests/func_for_tests.h"
///////////////////////

int		add_increase_middle_rows(t_dance *head, int side, int numfig)
{
	int		*lines;
	t_dance	*head_curr;
	t_dance *curr;

	if (!(lines = (int*)ft_memalloc(sizeof(int) * numfig)))
		return (0);
	head_curr = head->right;
	while (head_curr != head)
	{
		if (head_curr->coord % LEAD_DIGT == side - 1)
		{
			curr = head_curr->down;
			while (curr != head_curr)
			{
				if ((lines[curr->name - 'A'] < curr->spacer->coord)
					&& (!(increment_row_n_lines(curr->spacer, lines, side))))
					return (0);
				curr = curr->down;
			}
		}
		head_curr = head_curr->right;
	}
	free(lines);
	return (1);
}

int add_increase_last_rows(t_dance *head, int side, int numfig)
{
	int		i;
	int		lowdn;
	t_dance	*spacer;

	i = 0;
	while (i < numfig)
	{
		spacer = head->down;
		while (spacer->down->down->name != 'h' &&
				spacer->down->right->name - 'A' - 1 != i)
			spacer = spacer->down;
		if (!(add_increase_row(spacer,
				side + 1 - spacer->right->coord % LEAD_DIGT)))
			return (0);
		lowdn = lst_find_max_low_dgtnum(spacer->down);
		while (lowdn++ < side)
		{
			spacer = spacer->down;
			if (!add_increase_row(spacer, 1))
				return (0);
		}
		i++;
	}
	return (1);
}

void increase_list(t_dance *head, int side, int numfig, char ***sol_map)
{
	free_array((int**)(*sol_map), side - 1);
	if (!increase_cage(head, side) ||
		!add_increase_middle_rows(head, side, numfig) ||
		!add_increase_last_rows(head, side, numfig))
	{
		free_list(&head);
		ft_mkerr();
	}
	if(!(*sol_map = create_init_sol_map(side)))
	{
		free_array((int**)sol_map, side);
		freelst_and_exit(head);
	}
}
