/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:56:15 by ylila             #+#    #+#             */
/*   Updated: 2019/07/30 23:41:19 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"
#include <stdlib.h>

t_dance		*create(char n_name, int n_coord)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	new->name = n_name;
	new->coord = n_coord;
	new->spacer = new;
	new->home = new;
	new->up = new;
	new->down = new;
	new->left = new;
	new->right = new;
	return (new);
}

t_dance		*create_connct(t_dance *left, t_dance *right,
							t_dance *up, t_dance *down)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	new->name = 0;
	new->coord = 0;
	new->spacer = new;
	new->home = new;
	new->left = left;
	new->right = right;
	new->up = up;
	new->down = down;
	if (left)
		left->right = new;
	if (right)
		right->left = new;
	if (up)
		up->down = new;
	if (down)
		down->up = new;
	return (new);
}

void		node_set_params(t_dance *curr, char n_name,
							int n_coord, t_dance *spacer)
{
	curr->name = n_name;
	curr->coord = n_coord;
	curr->spacer = spacer;
}