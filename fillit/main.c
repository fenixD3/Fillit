/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/07/20 18:59:04 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}


#include <stdio.h>

int main()
{
	char	*line;
	int		numfig;
	int 	**figures;

	char	*filename = "/Users/mdeanne/fill/tests/mkfigtest";

	numfig = ft_readfile(filename, &line);
	figures = mkfig_arr(line, numfig);

	printf("%d\n", numfig);
	free(line);
//	clean_arrfigs(figures, numfig);
}
