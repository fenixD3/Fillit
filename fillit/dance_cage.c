/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance_cage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:59:04 by ylila             #+#    #+#             */
/*   Updated: 2019/07/30 18:14:22 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"
#include <stdlib.h>

int			add_cage(t_dance *right, t_dance *left, t_dance *new)
{
	if (!new)
		return (0);
	right->right = new;
	new->left = right;
	new->right = left;
	left->left = new;
	return (1);
}

int			add_spacer(t_dance *head, t_dance *new, _Bool edge, t_dance *curr)
{
	if (!new)
		return (0);
	new->coord = head->up->coord + 1;
	new->up = head->up;
	head->up->down = new;
	new->down = head;
	head->up = new;
	new->right = NULL;
	new->left = NULL;
	if (!edge)
	{
		curr->right = new;
		new->left = curr;
	}
	return (1);
}

void		free_cage(t_dance **head, _Bool error)
	// _Bool need for define exit with error or not
{
	t_dance *prev;
	t_dance *upper;

	prev = *head;
	upper = (*head)->down;
	prev->left->right = NULL;
	upper->up->up->down = NULL;
	while (*head)
	{
		*head = (*head)->right;
		free(prev);
		prev = *head;
	}
	*head = upper;
	while (*head)
	{
		*head = (*head)->down;
		free(upper);
		upper = *head;
	}
	error ? ft_mkerr() : error;
	*head = NULL;
}

t_dance		*make_cage(int side)
{
	t_dance	*head;
	t_dance	*curr;
	int		high_bit;
	int		low_bit;

	if (!(head = create('h', 0)))
		return (NULL);
	high_bit = 0;
	curr = head;
	while (++high_bit <= side)
	{
		low_bit = 0;
		while (++low_bit <= side)
		{
			if (!add_cage(curr, head,
			create('c', high_bit * LEAD_DIGT + low_bit)))
				free_cage(&head, 1);
			curr = curr->right;
		}
	}
	if (!(add_spacer(head, create('s', 1), 1, curr)))
		free_cage(&head, 1);
	return (head);
}
