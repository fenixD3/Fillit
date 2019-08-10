/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/10 07:52:10 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

/// DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//#include "../tests/func_for_tests.h"
//#include <time.h>
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

char	**create_init_sol_map(int side)
{
	char	**sol_map;
	int		i;
	int		j;

	if (!(sol_map = (char **)malloc(sizeof(char *) * side)))
		return (0);
	i = -1;
	while (++i < side)
	{
		j = -1;
		if (!(sol_map[i] = (char *)malloc(sizeof(char) * side)))
			return (0);
		while(++j < side)
			sol_map[i][j] = '.';
	}
	return (sol_map);
}

int		main(int ac, char **av)
{
//clock_t begin = clock();

	t_freem	mem;

/*	if (ac != 2)
	{
		ft_putendl("usage: ./fillit sample.fillit");
		return (0);
	}
	numfig = ft_readfile(av[1], &line);*/
///////////////////
	mem.numfig = ft_readfile("/home/yas/Fillit/tests/test_11", &mem.line, &mem.side);
//////////////////
	mem.figures = mkfig_arr(mem.line, mem.numfig);
	if (!(mem.sol_map = create_init_sol_map(mem.side)))
		free_manager(&mem, 128);
	filling_list(&mem);
	while (!knuth_solver(mem.head->down, mem.numfig, mem.sol_map))
	{
		free_manager(&mem, 6); // free sol_map && list
		mem.side++;
		if (!(mem.sol_map = create_init_sol_map(mem.side)))
			free_manager(&mem, 128);
		filling_list(&mem);
	}
	print_solution(mem.sol_map, mem.side);
	free_manager(&mem, 15);



//clock_t end = clock();
//double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//printf("time program = %lf\n", time_spent);
}
/*		char	*line;
	int		numfig;
	int		side;
	int 	**figures;
	char 	**sol_map;

	char	*filename = "/Users/mdeanne/Fillit/tests/mkfigtest4";
//	char	*filename = "/home/yas/Fillit/tests/mkfigtest4";

	numfig = ft_readfile(filename, &line);
	side = give_side(numfig);
	printf("side = %d\n", side);

	figures = mkfig_arr(line, numfig);
	printf("numfig = %d\n", numfig);


	t_dance *head = make_cage(side);
	filling_list(figures, numfig, head, side);

	sol_map = create_init_sol_map(side);
	if (!knuth_solver(head->down, numfig, sol_map))
	{
		printf("not enough side\nincreasing list\n");
		increase_list(head, side + 1, numfig, &sol_map);
		knuth_solver(head->down, numfig, sol_map);
		print_solution(sol_map, side + 1);
	}
	else
		print_solution(sol_map, side);

	free_list(&head);


}*/
