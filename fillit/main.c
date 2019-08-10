/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/11 01:47:26 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

/// DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//#include "../tests/func_for_tests.h"
#include <time.h>
#include "../tests/func_for_tests.h"
/////////////////////////////////////////////


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
			write (1, "\n", 1);
	}
}

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}

char **create_init_sol_map(t_freem *mem)
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
		while(++j < mem->side)
			sol_map[i][j] = '.';
	}
	return (sol_map);
}


_Bool			solver(t_dance *spacer, int numfig, char **sol_map);


int		main(int ac, char **av)
{
clock_t begin = clock();

	t_freem	mem;

/*	if (ac != 2)
	{
		ft_putendl("usage: ./fillit sample.fillit");
		return (0);
	}
	mem.numfig = ft_readfile(av[1], &mem.line, &mem.side);*/
///////////////////
	mem.numfig = ft_readfile("/Users/mdeanne/Fillit/tests/42checker/valid_9", &mem.line, &mem.side);
//////////////////
	mem.figures = mkfig_arr(mem.line, mem.numfig);
	mem.sol_map = create_init_sol_map(&mem);
	filling_list(&mem);
	while (!knuth_solver(mem.head->down, mem.numfig, mem.sol_map))
	{
		free_manager(&mem, 6); // free sol_map && list
		mem.side++;
		mem.sol_map = create_init_sol_map(&mem);
		filling_list(&mem);
	}
	print_solution(mem.sol_map, mem.side);
	free_manager(&mem, 15);



clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("time program = %lf\n", time_spent);
}
