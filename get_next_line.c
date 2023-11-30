#include "get_next_line.h"

char *get_next_line(int fd)
{
	char			*buf;
	static char		*stash;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, buf, 0))
		return (NULL);
	while (!found_newline(stash))
	{
		readed = read(fd, buf, BUFFER_SIZE);
		add_to_stash(buf, stash, readed);
		buf[readed] = '\0';
	}
	extract_line();
	clear_stash();
	return (line);
}

void add_to_stash(char *stash, char *buf, int readed)
{
	int i;

	i = 0;
	while(buf[i] && i < readed)
	{
		stash[i] = buf[i];
		i++;
	}
}