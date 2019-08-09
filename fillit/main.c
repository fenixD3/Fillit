/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/09 20:00:24 by mdeanne          ###   ########.fr       */
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
	free_array((int**)sol_map, side);
}

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}

int		main(int ac, char **av)
{
clock_t begin = clock();



	int numfig;
	int side;
	char *line;
	char **sol_map;
	t_dance *head;

	int **figures;

/*	if (ac != 2)
	{
		ft_putendl("usage: ./fillit sample.fillit");
		return (0);
	}
	numfig = ft_readfile(av[1], &line);*/
///////////////////
	numfig = ft_readfile("/Users/mdeanne/aa/tests/test_11", &line);
//////////////////
	side = give_side(numfig);
	head = make_cage(side);
	figures = mkfig_arr(line, numfig);
	filling_list(figures, numfig, head, side); //free_array commented
	sol_map = create_init_sol_map(side);

clock_t begin_solver = clock();


	while (!knuth_solver(head->down, numfig, sol_map))
	{
		ft_putendl("new solve\n");
		side++;
/*		increase_list(head, side, numfig, &sol_map);*/
		free_array((int**)(sol_map), side - 1);
		sol_map = create_init_sol_map(side);
		free_list(&head);
		head = make_cage(side);
		free_array(figures, numfig);
		figures = mkfig_arr(line, numfig);
		filling_list(figures, numfig, head, side); //free_array commented
	}
	print_solution(sol_map, side);

clock_t end_solver = clock();

	free_list(&head);


clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
double time_spent_solver = (double)(end_solver - begin_solver) / CLOCKS_PER_SEC;
printf("time solver = %lf\n", time_spent_solver);
printf("time program = %lf\n", time_spent);
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
