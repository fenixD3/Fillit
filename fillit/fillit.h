//
// Created by Mort Deanne on 2019-07-16.
//

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 550
# define LEAD_DIGT 100
# include "libft/libft.h" // wrong (should be only libft.h!!!)

typedef struct		s_dance
{
	char			*name;
	int				coord;
	struct	s_dance	*up;
	struct	s_dance	*down;
	struct	s_dance	*left;
	struct	s_dance	*right;
}					t_dance;

void				ft_mkerr();
int					ft_readfile(char *filename, char **line);
int					**mkfig_arr(const char *line, int numfig);

#endif
