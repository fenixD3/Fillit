/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/07/21 18:47:29 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "dance.h"
#include <stdio.h>

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}

void print_cage(t_dance *head)
{
	printf("Print\n");
	t_dance *printing = head->right;
	while (printing != head)
	{
		printf("%s : %d\n", printing->name, printing->coord);
		printing = printing->right;
	}
	printing = head->down;
	while (printing != head)
	{
		printf("%s : %d\n", printing->name, printing->coord);
		printing = printing->down;
	}
}

int main()
{
	char	*line;
	int		numfig;
	int 	**figures;

/*	char	*filename = "/Users/ylila/Fillit_hub/tests/mkfigtest";

	numfig = ft_readfile(filename, &line);
	figures = mkfig_arr(line, numfig);

	printf("%d\n", numfig);
	free(line);*/
//	clean_arrfigs(figures, numfig);

	t_dance *head = make_cage(3);
	print_cage(head);
	free_cage(&head, 0);
}
