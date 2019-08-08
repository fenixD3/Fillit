/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/08 22:34:47 by ylila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

/// DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "../tests/func_for_tests.h"
#define START_SIDE 4

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}


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



int main()
{
	char	*line;
	int		numfig;
	int		side;
	int 	**figures;

	char	*filename = "/Users/ylila/Fillit_hub/tests/mkfigtest4";
//	char	*filename = "/home/yas/Fillit/tests/mkfigtest4";

	numfig = ft_readfile(filename, &line);
	side = give_side(numfig);
	printf("%d\n", side);

	figures = mkfig_arr(line, numfig);
	printf("%d\n", numfig);
	char **sol_map = create_init_sol_map(side);

	t_dance *head = make_cage(side);
	filling_list(figures, numfig, head, side);
	print_list(head);

	while (!solver(head->down, numfig, sol_map, side))
	{
		printf("not enough side\n");
		++side;
		increase_list(head, side, numfig);
		free_arrfigs(sol_map, side - 1);
		print_list(head);
		sol_map = create_init_sol_map(side);
	}
	print_solution2(sol_map, side);
/*	increase_list(head, side + 1, numfig);

	if (!solver(head->down, numfig, 1, side))
		printf("not enough side");*/
	free_list(&head);

/*	t_dance *head = make_cage(3);
	print_cage(head);
	printf("_____________\n");
	add_spacer2(head, create('s', 1), 1, head->up);

	ft_strcpy(head->down->name, "AA");
	ft_strcpy(head->up->name, "BB");

	print_cage(head);
	free_cage(&head, 0);*/
}
