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
	if (fd < 0)
		printf("error");
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		i++;
	}
	close(fd);
	free(line);
	return (0);
}