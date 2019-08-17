/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knuth_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylila <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 03:13:31 by ylila             #+#    #+#             */
/*   Updated: 2019/08/17 21:18:05 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

_Bool	prepare_backtrack(t_dance *spacer, int *counter)
{
	bad_options(spacer->right, open_option);
	(*counter)--;
	return (0);
}

int		knuth_check(t_dance *spacer, int numfig, int *counter, char **sol_map)
{
	if (*counter == numfig)
		return (fill_opt_to_sol_map(spacer->right, sol_map));
	else if (spacer->right)
		bad_options(spacer->right, hide_option);
	else if (!spacer->right)
		return (prepare_backtrack(spacer, counter));
	return (2);
}

int		next_char(t_dance *spacer, t_dance **curr, int *counter, t_freem *mem)
{
	if (spacer->down->right && spacer->right->name == spacer->down->right->name)
	{
		*curr = spacer->down;
		while ((*curr)->right &&
		!((*curr)->up->right->name - (*curr)->right->name))
			*curr = (*curr)->down;
		if ((!(*curr)->down->right && (*curr)->right->name -
							(*curr)->up->right->name != 1) || !(*curr)->right)
			return (prepare_backtrack(spacer, counter));
	}
	else if (spacer->down->right &&
						spacer->down->right->name - spacer->right->name == 1)
		*curr = spacer->down;
	else if (spacer->down->right && *counter + 1 == mem->numfig &&
						spacer->right->name + 1 == spacer->down->right->name)
	{
		(*counter)++;
		fill_opt_to_sol_map(spacer->right, mem->sol_map);
		return (fill_opt_to_sol_map(spacer->down->right, mem->sol_map));
	}
	else
		return (prepare_backtrack(spacer, counter));
	return (2);
}

_Bool	a_solver(t_freem *mem)
{
	int		counter;
	t_dance *spacer;

	spacer = mem->head->down;
	counter = 0;
	while (1)
	{
		if (!knuth_solver(spacer, mem, &counter))
		{
			if (spacer->down->right &&
			spacer->down->right->name == spacer->right->name)
				spacer = spacer->down;
			else
				return (0);
		}
		if (counter == mem->numfig && spacer->right)
			return (fill_opt_to_sol_map(spacer->right, mem->sol_map));
	}
}

_Bool	knuth_solver(t_dance *spacer, t_freem *mem, int *counter)
{
	t_dance		*cr;
	int			tmp;

	(*counter)++;
	if (!(tmp = knuth_check(spacer, mem->numfig, counter, mem->sol_map)))
		return (0);
	else if (tmp == 1)
		return (1);
	if ((tmp = next_char(spacer, &cr, counter, mem)) == 1)
		return (1);
	if (!tmp)
		return (0);
	while (1)
	{
		if (!knuth_solver(cr, mem, counter))
		{
			if (cr->down->right && cr->down->right->name == cr->right->name)
				cr = cr->down;
			else
				return (prepare_backtrack(spacer, counter));
		}
		if (*counter == mem->numfig && spacer->right)
			return (fill_opt_to_sol_map(spacer->right, mem->sol_map));
	}
}
