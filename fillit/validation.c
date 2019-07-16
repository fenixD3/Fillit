//
// Created by Mort Deanne on 2019-07-16.
//

#include "fillit.h"
#include <fcntl.h>

int		ft_connections_counter(const char *line, int i)
{
	int connections;

	connections = 0;
	if (i > 5 && *(line - 5) == '#')
		connections++;
	if (i < 15 && *(line + 5) == '#')
		connections++;
	if (i != 1 && *(line - 1) == '#')
		connections++;
	if (*(line + 1) == '#')
		connections++;
	return (connections);
}

void	ft_check(char line[BUFF_SIZE])
{
	int i;
	int sharp;
	int connections;

	while(*line)
	{
		i = 1;
		sharp = 0;
		connections = 0;
		while(i != 21)
		{
			if ((i % 5 == 0 && *line != '\n') || (i % 5 != 0 && *line != '#' &&
			*line != '.') || (*line == '#' && ++sharp > 4))
				ft_mkerr();
			if (*line == '#')
				connections += ft_connections_counter(line, i);
			i++;
			line++;
		}
		if (connections != 6 && connections != 8)
			ft_mkerr();
		if (*line == '\0')
			break;
		(*line == '\n') ? line++ : ft_mkerr();
	}
}

void	ft_readfile(char *filename, char **line)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_mkerr();
	if ((ret = read(fd, &buf, BUFF_SIZE)) > 545 || (ret + 1) % 21 != 0)
		ft_mkerr();
	buf[ret] = '\0';
	ft_check(buf);
	*line = ft_strdup(buf);
}

