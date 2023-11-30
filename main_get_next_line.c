#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;
	int	*line;

	fd = open("GNT.txt", O_RDONLY)
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (1);
		printf("%s", line);
		free(line);
	}
	return (0);
}