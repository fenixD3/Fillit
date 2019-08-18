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
	if (flag & 128)
	{
		if (mem->figures != NULL)
			free_arrfig(mem);
		if (mem->line != NULL)
			free(mem->line);
		if (mem->head != NULL)
			free_list(&(mem->head));
		if (mem->sol_map != NULL)
			free_sol_map(mem);
		ft_mkerr();
	}
	if (flag & 1)
		free_arrfig(mem);
	if (flag & 2)
		free_sol_map(mem);
	if (flag & 4)
		free_list(&(mem->head));
	if (flag & 8)
	{
		free(mem->line);
		mem->line = NULL;
	}
	if (flag & 16)
		ft_mkerr();
}
