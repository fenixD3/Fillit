//
// Created by yas on 8/10/19.
//

#ifndef FREE_MANAGER_H
# define FREE_MANAGER_H
# include "dance.h"

typedef struct		s_freem
{
	int 	numfig;
	int 	side;
	int 	**figures;
	char	*line;
	char	**sol_map;
	t_dance	*head;
}					t_freem;

void	free_manager(t_freem *mem, unsigned char flag);

#endif
