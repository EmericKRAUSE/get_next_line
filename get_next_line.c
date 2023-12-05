#include "get_next_line.h"
#include <stdio.h>

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	t_list	*new_node;

	new_node = ft_lstnew(buf);
	if (!new_node)
		return ;
	ft_lstadd_back(stash, new_node);
}

int	found_newline(t_list *stash)
{
	int	i;

	while (stash != NULL)
	{
		i = 0;
		while (stash->data[i])
		{
			if (stash->data[i] == '\n' || stash->data[i] == '\0')
				return (1);
			i++;
		}
		stash = stash->next;
	}
	return (0);
} 

char	*extract_line(t_list *stash)
{
	int		i;
	int		j;
	char	*line;

	if (!stash)
		return (NULL);
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

	if (!stash)
		return (NULL);
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
	{
		stash[i] = temp[i];
		i++;
	}
	stash[i] = '\0';
	free (temp);
	return (stash);
}

char *get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static t_list	*stash;
	char			*line;
	int				readed;

	if (!stash)
		stash = ft_lstnew(NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	readed = 1;
	while (found_newline(stash) == 0 && readed > 0)
	{
		if (!buf)
			return (NULL);
		readed = read(fd, buf, BUFFER_SIZE);
		if (read <= 0)
			break;
		buf[readed] = '\0';
		add_to_stash(&stash, buf, readed);
		while (stash != NULL)
		{
			printf("%s", stash->data);
			stash = stash->next;
		}
	}
	line = extract_line(stash);
	stash = clear_stash(stash);
	return (line);
}
