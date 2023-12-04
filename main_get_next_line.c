#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	*line;
	int		i;

	i = 0 ;
	fd = open("GNL.txt", O_RDONLY);
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	free (line);
	close  (fd);
	return (0);
}