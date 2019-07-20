//
// Created by Mort Deanne on 2019-07-16.
//

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 550
# include "libft/libft.h" // wrong (should be only libft.h!!!)

typedef struct		s_dance
{
	char	*name;
	int		coord;
	s_dance	*up;
	s_dance	*down;
	s_dance	*left;
	s_dance	*right;
}					t_dance;

void				ft_mkerr();
int					ft_readfile(char *filename, char **line);

#endif
