//
// Created by Mort Deanne on 2019-07-25.
//

#include "func_for_tests.h"


void print_cage(t_dance *head)
{
	printf("Print\n");
	t_dance *printing = head->right;
	while (printing != head)
	{
		printf("%c : %d", printing->name, printing->coord);
		printing = printing->right;
	}
	printing = head->down;
	while (printing != head)
	{
		printf("%c : %d\n", printing->name, printing->coord);
		printing = printing->down;
	}
}

void print_arr(int **arr, int numfig)
{
	int i = 0;
	int j;

	while (i < numfig)
	{
		j = 0;
		while (j < 4)
			printf("%d\t", arr[i][j++]);
		printf("\n");
		i++;
	}
}


//// with | - symbols
/*void print_list(t_dance *head)
{
	printf("Print list\n");
	t_dance *printing = head->right;
	t_dance *head_check = printing;

	while (printing != head)
	{
		printf("%d|\t", printing->coord);
		printing = printing->right;
	}
	printf("\n");

	printing = head->down->right;
	while (printing != NULL)
	{
		while (ft_strcmp(printing->name, 's') != 0)
		{
			while (head_check->coord != printing->coord)
			{
				head_check = head_check->right;
				ft_putstr("   |\t");
			}
			ft_putchar(*(printing->name));
			ft_putstr("  |\t");
			printing = printing->right;
			head_check = head_check->right;
		}
		while (head != head_check)
		{
			head_check = head_check->right;
			printf("   |\t");
		}
		printf("\n");
		printing = printing->right;
		head_check = head->right;
	}
}*/



void print_hidesp(t_dance *head)
{
	int coord;

	coord = 0;
	while (head->right)
	{
		if (head->coord == coord)
		{
			head = head->down;
			coord++;
		}
		else
		{
			printf("%d, ", coord);
			coord++;
		}
	}
	printf("\n");
}

void print_sp(t_dance *head)
{
	while (head->right)
	{
		printf("%d, ", head->coord);
		head = head->down;
	}
	printf("%d\n", head->coord);
}

void print_sp2(t_dance *head)
{
	printf("spasers is\n");
	print_sp(head);
	printf("hide spasers is\n");
	print_hidesp(head);
}

void print_list(t_dance *head)
{
	printf("Print list\n");
	t_dance *printing = head->right;
	t_dance *head_check = printing;

	printf("%d\t", head->coord);
	while (printing != head)
	{
		printf("%d\t", printing->coord);
		printing = printing->right;
	}
	printf("\n");

	printing = head->down->right;
	while (printing != NULL)
	{
		ft_putnbr(printing->left->coord);
		ft_putstr("\t");
		while (printing->name != 's')
		{
			while (head_check->coord != printing->coord)
			{
				head_check = head_check->right;
				ft_putstr("\t");
			}
			ft_putchar(printing->name);
			ft_putstr("\t");
			printing = printing->right;
			head_check = head_check->right;
		}
		while (head != head_check)
		{
			head_check = head_check->right;
			printf("\t");
		}
		printf("\n");
		printing = printing->right;
		head_check = head->right;
	}
}

void print_list_by_sp(t_dance *head)
{
	printf("Print list\n");
	t_dance *printing = head->right;
	t_dance *head_check = printing;
	t_dance *spacer;

	printf("%d\t", head->coord);
	while (printing != head)
	{
		printf("%d\t", printing->coord);
		printing = printing->right;
	}
	printf("\n");

	spacer = head->down;
	printing = spacer->right;
	while (spacer->right)
	{
		ft_putnbr(printing->left->coord);
		ft_putstr("\t");
		while (printing->name != 's')
		{
			while (head_check->coord != printing->coord)
			{
				head_check = head_check->right;
				ft_putstr("\t");
			}
			ft_putchar(printing->name);
			ft_putstr("\t");
			printing = printing->right;
			head_check = head_check->right;
		}
		while (head != head_check)
		{
			head_check = head_check->right;
			printf("\t");
		}
		printf("\n");
		spacer = spacer->down;
		printing = spacer->right;
		head_check = head->right;
	}
}

void recursion_test(t_dance *sp)
{
	sp = sp->right;
	sp->up = NULL;
	if (sp->right)
		recursion_test(sp);
}
