/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:55:49 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/08 20:19:49 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

int 	fill_row(int *figure, int step, const char n_name, t_dance *head)
{
	int i;
	t_dance *curr;
	t_dance *prev;
	t_dance *new;

/*	/////////////////
	static int num;
	num++;
	ft_putnbr(num);
	ft_putchar('\n');
	if (num == 160)
		ft_putchar('G');
	/////////////////*/

	i = 0;
	curr = head;
	prev = head->up;
	while (i < 4)
	{
		while (curr->coord != figure[i] + step)
			curr = curr->right;
		if (!(new = create_connct(prev, NULL, curr->up, curr)))
			return (0);
		node_set_params(new, n_name, figure[i] + step, head->up);
		new->home = curr;
		prev = prev->right;
		i++;
	}
	if (!(add_spacer(head, create('s', 1), 0, new)))
		return (0);
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

char	**create_init_sol_map(int side)
{
	char	**sol_map;
	int		i;
	int		j;

	if (!(sol_map = (char **)malloc(sizeof(char *) * side)))
		; // add free_list
	i = -1;
	while (++i < side)
	{
		j = -1;
		if (!(sol_map[i] = (char *)malloc(sizeof(char) * side)))
			; // add free_array & free_list
		while(++j < side)
			sol_map[i][j] = '.';
	}
	return (sol_map);
}

void 	filling_list(int **figures, int numfig, t_dance *head, int side)
{
	int i;
	int lowdn; //max low digit number
	int highdn; //max high digit number
	int step;

	i = -1;
	while (++i < numfig)
	{
		step = 0;
		lowdn = find_max_low_dgtnum(figures[i]);
		highdn = figures[i][3] / LEAD_DIGT;
		while (highdn <= side)
		{
			if (lowdn + step <= side)
			{
				if (!fill_row(figures[i], step++, ((char) i + 'A'), head))
					free_list(&head);
			}
			else if (highdn < side)
				increase_figure_on_lead_digit(figures[i], &highdn, &step);
			else if (highdn == side)
				break ;
		}
	}
	//free_array(figures, numfig);
}
