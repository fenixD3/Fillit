/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/03 22:57:48 by mdeanne          ###   ########.fr       */
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






int main()
{
	char	*line;
	int		numfig;
	int 	**figures;

	char	*filename = "/Users/mdeanne/111/tests/mkfigtest4";
//	char	*filename = "/home/yas/Fillit/tests/mkfigtest4";

	numfig = ft_readfile(filename, &line);
	figures = mkfig_arr(line, numfig);

	printf("%d\n", numfig);
	print_arr(figures, numfig);
//	printf("%d %d %d\n", find_max_low_dgtnum(figures[0]), find_max_low_dgtnum(figures[1]), find_max_low_dgtnum(figures[2]));


	t_dance *head = make_cage(START_SIDE);
	filling_list(figures, numfig, head, START_SIDE);

	print_list(head);

	increase_list(head, START_SIDE + 1, numfig);

	print_list(head);
	recursion_test(head->down);

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
