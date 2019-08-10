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

// _Bool need for define exit with error or not
void		free_cage(t_dance **head, _Bool error)
{
	t_dance *prev;
	t_dance *upper;

	prev = *head;
	upper = (*head)->down;
	prev->left->right = NULL;
	upper->up->up->down = NULL;
	while (*head)
	{
		*head = (*head)->right;
		free(prev);
		prev = *head;
	}
	*head = upper;
	while (*head)
	{
		*head = (*head)->down;
		free(upper);
		upper = *head;
	}
	error ? ft_mkerr() : error;
	*head = NULL;
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

void		freelst_and_exit(t_dance *head)
{
	free_list(&head);
	ft_mkerr();
}