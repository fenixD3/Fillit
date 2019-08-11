//
// Created by Mort Deanne on 2019-08-07.
//

#include "fillit.h"

void	free_arrfig(int ***figures, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(*(figures[i]));
		*(figures[i]) = NULL;
		i++;
	}
	free(*figures);
	*figures = NULL;
}

void	free_sol_map(char ***sol_map, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(*(sol_map[i]));
		*(sol_map[i]) = NULL;
		i++;
	}
	free(*sol_map);
	*sol_map = NULL;
}

void		free_list(t_dance **head)
{
	t_dance *curr;

	curr = (*head)->down;
	while (curr->right)
	{
		curr = curr->right;
		free(curr->left);
	}
	free(curr);
	curr = (*head)->right;
	while (curr != *head)
	{
		curr = curr->right;
		free(curr->left);
	}
	free(*head);
	*head = NULL;
}
