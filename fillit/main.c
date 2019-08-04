/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/04 21:48:19 by mdeanne          ###   ########.fr       */
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
	int		side;
	int 	**figures;

	char	*filename = "/Users/mdeanne/123/tests/mkfigtest3";
//	char	*filename = "/home/yas/Fillit/tests/mkfigtest4";

	numfig = ft_readfile(filename, &line);
	side = give_side(numfig);
	printf("%d\n", side);

	figures = mkfig_arr(line, numfig);
	printf("%d\n", numfig);


	t_dance *head = make_cage(side);
	filling_list(figures, numfig, head, side);
	print_list(head);

	if (!solver(head->down, numfig, 1, side))
		printf("not enough side");

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
