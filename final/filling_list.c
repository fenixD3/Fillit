/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:55:49 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/10 07:52:11 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

int		fill_row(int *figure, int step, const char n_name, t_freem *mem)
{
	int		i;
	t_dance	*curr;
	t_dance	*prev;
	t_dance	*new;

	i = 0;
	curr = mem->head;
	prev = mem->head->up;
	while (i < 4)
	{
		while (curr->coord != figure[i] + step)
			curr = curr->right;
		if (!(new = create_connct(prev, NULL, curr->up, curr)))
			free_manager(mem, 128);
		node_set_params(new, n_name, figure[i] + step, mem->head->up);
		new->home = curr;
		prev = prev->right;
		i++;
	}
	if (!(add_spacer(mem->head, create('s', 1), 0, new)))
		free_manager(mem, 128);
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

void	increase_figure_on_lead_digit(int *figure, int *highdn, int *step)
{
	int i;

	i = 0;
	while (i < 4)
		figure[i++] += LEAD_DIGT;
	(*highdn)++;
	*step = 0;
}

void	filling_list(t_freem *mem)
{
	int i;
	int lowdn;
	int highdn;
	int step;

	if (!(mem->head = make_cage(mem->side)))
		free_manager(mem, 128);
	i = -1;
	while (++i < mem->numfig)
	{
		step = 0;
		lowdn = find_max_low_dgtnum(mem->figures[i]);
		highdn = mem->figures[i][3] / LEAD_DIGT;
		while (highdn <= mem->side)
		{
			if (lowdn + step <= mem->side)
				fill_row(mem->figures[i], step++, ((char)i + 'A'), mem);
			else if (highdn < mem->side)
				increase_figure_on_lead_digit(mem->figures[i], &highdn, &step);
			else if (highdn == mem->side)
				break ;
		}
	}
	drop_mkfigarr(mem->figures, mem->numfig);
}
