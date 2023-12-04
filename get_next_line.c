#include "get_next_line.h"

char *get_next_line(int fd)
{
	char			*buf;
	static char		*stash;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (found_newline(stash) == 0)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		stash = add_to_stash(buf, stash, readed);
		free (buf);
	}
	line = extract_line(stash);
	clear_stash();
	return (line);
}

char	*add_to_stash(char *stash, char *buf, int readed)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stash[i])
		i++;
	while (buf[i + j] && j < readed)
	{
		stash[i + j] = buf[i + j];
		j++;
	}
	return (stash);
}

int	found_newline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n' || stash[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] && stash [i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (stash[j] && j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}


char	*clear_stash(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i++;
	temp = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!temp)
		return  (NULL);
	j = 0;
	while (stash[i])
		temp[j++] = stash[i++];
	temp[j] = '\0';
	stash = ft_bzero(stash);
	i = 0;
	while (temp[i])
		stash[i] = temp[i++];
	stash[i] = '\0';
	free (temp);
	return (stash);
}

char	*ft_bzero(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
		stash[i++] = 0;
	return (stash);
}

int	ft_strlen(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
		i++;
	return (i);
}