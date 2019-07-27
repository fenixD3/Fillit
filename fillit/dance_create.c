/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:56:15 by ylila             #+#    #+#             */
/*   Updated: 2019/07/27 20:28:59 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"
#include <stdlib.h>

t_dance	*create(const char *n_name, const int n_coord)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	if (!(new->name = ft_strdup(n_name)))
		return (NULL);
	new->coord = n_coord;
	new->spacer = new;
	new->home = new;
	new->up = new;
	new->down = new;
	new->left = new;
	new->right = new;
	return (new);
}

/*int		add_hor(t_dance **dance, t_dance *left, t_dance *right, t_dance *new)
{
	if (!left || !right || !new)
		return (0);
	while (*dance != left)
		*dance = (*dance)->right;
	new->left = (*dance);
	new->right = (*dance)->right;
	(*dance)->right = new;
	return (1);
}

int		add_ver(t_dance **dance, t_dance *up, t_dance *down, t_dance *new)
{
	if (!up || !down || !new)
		return (0);
	while (*dance != up)
		*dance = (*dance)->down;
	new->up = (*dance);
	new->down = (*dance)->down;
	(*dance)->down = new;
	return (1);
}*/

t_dance		*create_connct(t_dance *left, t_dance *right, t_dance *up, t_dance *down)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	new->name = NULL;
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

int node_set_params(t_dance *curr, const char *n_name,
		const int n_coord, t_dance *spacer)
{
	if (!(curr->name = ft_strdup(n_name)))
		return (0);
	curr->coord = n_coord;
	curr->spacer = spacer;
	return (1);
}
