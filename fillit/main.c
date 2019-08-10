/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/11 01:47:26 by mdeanne          ###   ########.fr       */
=======
/*   Updated: 2019/08/09 23:04:29 by ylila            ###   ########.fr       */
>>>>>>> master
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

<<<<<<< HEAD
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
=======

static char	**create_init_sol_map(int side)
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

_Bool		print_solution2(char **sol_map, int side)
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
						return (1);
}

#include <time.h>

int main()
{
	clock_t begin = clock();
	char	*line;
	int		numfig;
	int		side;
	int 	**figures;

	//char	*filename = "/Users/ylila/Fillit_hub/tests/mkfigtest4";
	char	*filename = "/Users/ylila/Fillit_hub/tests/vtest2";
//	char	*filename = "/home/yas/Fillit/tests/mkfigtest4";

	numfig = ft_readfile(filename, &line);
	side = give_side(numfig);
	printf("%d\n", side);

	figures = mkfig_arr(line, numfig);
	printf("%d\n", numfig);
	char **sol_map = create_init_sol_map(side);

	t_dance *head = make_cage(side);
	filling_list(figures, numfig, head, side);
	//print_list(head);

	while (!solver(head->down, numfig, sol_map))
	{
		ft_putendl("new solve\n");
		side++;
		free_arrfigs((int**)(sol_map), side - 1);
		sol_map = create_init_sol_map(side);
		free_list(&head);
		head = make_cage(side);
		//free_arrfigs(figures, numfig);
		figures = mkfig_arr(line, numfig);
		filling_list(figures, numfig, head, side); //free_array commented
		//print_list(head);
	}
	print_solution2(sol_map, side);
/*	increase_list(head, side + 1, numfig);
>>>>>>> master


_Bool			solver(t_dance *spacer, int numfig, char **sol_map);


<<<<<<< HEAD
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
=======
	print_cage(head);
	free_cage(&head, 0);*/
	clock_t  end = clock();
	printf("Time = %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
>>>>>>> master
}
