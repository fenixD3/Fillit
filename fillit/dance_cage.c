/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance_cage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:59:04 by ylila             #+#    #+#             */
/*   Updated: 2019/07/21 17:00:48 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		add_cage(t_dance **curr, t_dance **head, t_dance *new)
{
	if (!new)
		return (0);
	(*curr)->right = new;
	new->left = *curr;
	new->right = *head;
	*(head)->left = new;
	return (1);
}

t_dance	*find_low_spacer(t_dance **head)
{
	t_dance *curr = *head;

	while (curr->down != *head)
		curr = curr->down;
	return (curr);
}

int		add_spacer(t_dance **curr, t_dance **head, t_dance *new)
{
	if (!new)
		return (0);
	(*curr)->right = new;
	new->left = *curr;
	new->up = find_low_spacer(head);
	new->down = *head;
	*(head)->up = new;
	return (1);
}

void	free_cage(t_dance **head)
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
		free(prev->name);
		free(prev);
		prev = *head;
	}
	*head = upper;
	while (*head)
	{
		*head = (*head)->down;
		free(upper->name);
		free(upper);
		upper = *head;
	}
	ft_mkerr();
}

t_dance	*make_cage(int side)
{
	t_dance	*head;
	t_dance	*curr;
	int		high_bit;
	int		low_bit;

	if (!(head = create("Head", 0)))
		return (NULL);
	high_bit = 0;
	curr = head;
	while (++high_bit <= side)
	{
		low_bit = 0;
		while (++low_bit <= side)
		{
			if (!add_cage(&curr, &head, create("Cl", high_bit * 100 + low_bit)))
				free_cage(&head);
			curr = curr->right;
		}
	}
	if (!(add_spacer(&curr, &head, create("Sp", 1))))
		free_cage(&head);
	return (head);
}
