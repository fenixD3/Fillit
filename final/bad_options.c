/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:59:28 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/17 20:59:35 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	hide_option(t_dance *node)
{
	t_dance *curr;

	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr->down;
			curr->down->up = curr->up;
		}
		curr = curr->left;
	}
	curr->up->down = curr->down;
	curr->down->up = curr->up;
	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr->down;
			curr->down->up = curr->up;
		}
		curr = curr->right;
	}
}

void	open_option(t_dance *node)
{
	t_dance *curr;

	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr;
			curr->down->up = curr;
		}
		curr = curr->left;
	}
	curr->up->down = curr;
	curr->down->up = curr;
	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr;
			curr->down->up = curr;
		}
		curr = curr->right;
	}
}

void	bad_options(t_dance *node, void (*f)(t_dance *))
{
	t_dance *curr;

	while (node->name != 's')
	{
		curr = node->down;
		while (curr->name != 'c')
		{
			(*f)(curr);
			curr = curr->down;
		}
		node = node->right;
	}
}
