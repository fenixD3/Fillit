/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_manager.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:58:15 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/17 20:58:22 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_MANAGER_H
# define FREE_MANAGER_H
# include "dance.h"

typedef struct		s_freem
{
	int		numfig;
	int		side;
	int		**figures;
	char	*line;
	char	**sol_map;
	t_dance	*head;
}					t_freem;

void				free_manager(t_freem *mem, unsigned char flag);

#endif
