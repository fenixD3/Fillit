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
		printf("%s : %d : %d\n", printing->name, printing->coord, printing->jump);
		printing = printing->right;
	}
	printing = head->down;
	while (printing != head)
	{
		printf("%s : %d : %d\n", printing->name, printing->coord, printing->jump);
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
		while (ft_strcmp(printing->name, "Sp") != 0)
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

void print_list(t_dance *head)
{
	printf("Print list\n");
	t_dance *printing = head->right;
	t_dance *head_check = printing;

	while (printing != head)
	{
		printf("%d\t", printing->coord);
		printing = printing->right;
	}
	printf("\n");

	printing = head->down->right;
	while (printing != NULL)
	{
		while (ft_strcmp(printing->name, "Sp") != 0)
		{
			while (head_check->coord != printing->coord)
			{
				head_check = head_check->right;
				ft_putstr("\t");
			}
			ft_putchar(*(printing->name));
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
