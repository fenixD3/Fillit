/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/07/28 00:00:09 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"

/// DELETE THIS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "../tests/func_for_tests.h"

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

	char	*filename = "/Users/mdeanne/Fillit/tests/mkfigtest";

	numfig = ft_readfile(filename, &line);
	figures = mkfig_arr(line, numfig);

	printf("%d\n", numfig);
	print_arr(figures, numfig);
//	printf("%d %d %d\n", find_max_low_dgtnum(figures[0]), find_max_low_dgtnum(figures[1]), find_max_low_dgtnum(figures[2]));


	t_dance *head = make_cage(3);
	filling_list(figures, numfig, head, 3);
	print_list(head);
	increase_cage(head, 3);

	add_increase_middle_rows(head, 3, numfig);

	print_list(head);

	free(line);
//	clean_arrfigs(figures, numfig);

/*	t_dance *head = make_cage(3);
	print_cage(head);
	printf("_____________\n");
	add_spacer2(head, create("Sp", 1), 1, head->up);

	ft_strcpy(head->down->name, "AA");
	ft_strcpy(head->up->name, "BB");

	print_cage(head);
	free_cage(&head, 0);*/
}
