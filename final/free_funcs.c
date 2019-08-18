/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:59:41 by mdeanne           #+#    #+#             */
/*   Updated: 2019/08/18 16:15:21 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_arrfig(t_freem *mem)
{
	int i;

	i = 0;
	while (i < mem->numfig)
	{
		free(mem->figures[i]);
		mem->figures[i] = NULL;
		i++;
	}
	free(mem->figures);
	mem->figures = NULL;
}

void	free_sol_map(t_freem *mem)
{
	int i;

	i = 0;
	while (i < mem->side)
	{
		free(mem->sol_map[i]);
		mem->sol_map[i] = NULL;
		i++;
	}
	free(mem->sol_map);
	mem->sol_map = NULL;
}

void	free_list(t_dance **head)
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
