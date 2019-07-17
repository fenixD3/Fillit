/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 04:58:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/07/17 04:59:27 by mdeanne          ###   ########.fr       */
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

	char	*filename = "/Users/mdeanne/fill/tests/nvtest3";

	numfig = ft_readfile(filename, &line);
	printf("%d\n", numfig);
	free(line);
}
