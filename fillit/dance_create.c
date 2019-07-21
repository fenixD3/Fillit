/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dance_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:56:15 by ylila             #+#    #+#             */
/*   Updated: 2019/07/21 17:03:32 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_dance	*create(const char *n_name, const int n_coord)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	if (!(new->name = ft_strdup(n_name)))
		return (NULL);
	new->coord = n_coord;
	new->jump = 0;
	new->up = new;
	new->down = new;
	new->left = new;
	new->right = new;
	return (new);
}

int		add_hor(t_dance **dance, t_dance *left, t_dance *right, t_dance *new)
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
}


