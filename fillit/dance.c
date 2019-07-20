#include "fillit.h"
#include <stdlib.h>

t_dance	*create(const char *n_name, const int n_coord)
{
	t_dance *new;

	if (!(new = (t_dance *)malloc(sizeof(t_dance))))
		return (NULL);
	if (!(new->name = ft_strdup(n_name)))
		return (NULL);
	new->coord = n_coord;
	new->up = NULL;
	new->down = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	add(t_dance **dance, t_dance *
