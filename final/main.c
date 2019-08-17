/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/17 18:55:17 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mkerr(void)
{
	ft_putendl("error");
	exit(1);
}

void	print_solution(char **sol_map, int side)
{
	int		i;
	int		j;

	i = -1;
	while (++i < side)
	{
		j = -1;
		while (++j < side)
			write(1, &sol_map[i][j], 1);
		if (i < side)
			write(1, "\n", 1);
	}
}

char	**create_init_sol_map(t_freem *mem)
{
	char	**sol_map;
	int		i;
	int		j;

	if (!(sol_map = (char **)malloc(sizeof(char *) * mem->side)))
		free_manager(mem, 128);
	i = -1;
	while (++i < mem->side)
	{
		j = -1;
		if (!(sol_map[i] = (char *)malloc(sizeof(char) * mem->side)))
			free_manager(mem, 128);
		while (++j < mem->side)
			sol_map[i][j] = '.';
	}
	return (sol_map);
}

_Bool	fill_opt_to_sol_map(t_dance *node, char **sol_map)
{
	while (node->name != 's')
	{
		sol_map[node->coord / LEAD_DIGT - 1][node->coord % LEAD_DIGT - 1] =
				node->name;
		node = node->right;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_freem	mem;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit sample.fillit");
		return (0);
	}
	mem.numfig = ft_readfile(av[1], &mem.line, &mem.side);
	mem.figures = mkfig_arr(mem.line, mem.numfig);
	mem.sol_map = create_init_sol_map(&mem);
	filling_list(&mem);
	while (!a_solver(&mem))
	{
		free_manager(&mem, 6);
		mem.side++;
		mem.sol_map = create_init_sol_map(&mem);
		filling_list(&mem);
	}
	print_solution(mem.sol_map, mem.side);
	free_manager(&mem, 15);
}
