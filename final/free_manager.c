/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:59:46 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/17 20:59:49 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_manager(t_freem *mem, unsigned char flag)
{
	if (flag >> 7 == 1)
	{
		if (mem->figures != NULL)
			free_arrfig(&mem->figures, mem->numfig);
		if (mem->line != NULL)
			free(mem->line);
		if (mem->head != NULL)
			free(mem->head);
		if (mem->sol_map != NULL)
			free_sol_map(&mem->sol_map, mem->side);
		ft_mkerr();
	}
	if (flag << 7 >> 7 == 1)
		free_arrfig(&mem->figures, mem->numfig);
	if (flag << 6 >> 7 == 1)
		free_sol_map(&mem->sol_map, mem->side);
	if (flag << 5 >> 7 == 1)
		free_list(&(mem->head));
	if (flag << 4 >> 7 == 1)
		free(mem->line);
	if (flag << 3 >> 7 == 1)
		ft_mkerr();
}
