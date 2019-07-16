// make a header

#include "fillit.h"

void	ft_mkerr()
{
	ft_putendl("error");
	exit(1);
}


#include <stdio.h>

int main()
{
	char *line;
	//char *filename = "/Users/mdeanne/fill/tests/nvtest3";

	ft_readfile(filename, &line);
	free(line);
}