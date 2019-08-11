//
// Created by Mort Deanne on 2019-08-07.
//

#include "fillit.h"

/* Hides all nodes of option and left spacer node without "*node"*/
void	hide_option(t_dance *node)
{
	t_dance *curr;

	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr->down;
			curr->down->up = curr->up;
		}
		curr = curr->left;
	}
	curr->up->down = curr->down;
	curr->down->up = curr->up;
	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr->down;
			curr->down->up = curr->up;
		}
		curr = curr->right;
	}
}

void	open_option(t_dance *node)
{
	t_dance *curr;

	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr;
			curr->down->up = curr;
		}
		curr = curr->left;
	}
	curr->up->down = curr;
	curr->down->up = curr;
	curr = node;
	while (curr->name != 's')
	{
		if (curr != node)
		{
			curr->up->down = curr;
			curr->down->up = curr;
		}
		curr = curr->right;
	}
}

/* finc takes pointer to first node of option that, we guess, is "good" opt */
/* fakes pointer to open_option() or hide_option()*/
void	bad_options(t_dance *node, void (*f)(t_dance *))
{
	t_dance *curr;

	while (node->name != 's')
	{
		curr = node->down;
		while (curr->name != 'c')
		{
			(*f)(curr);
			curr = curr->down;
		}
		node = node->right;
	}
}