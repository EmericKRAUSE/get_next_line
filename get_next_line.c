#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char			*list;
	static t_list	*stash;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	
	// 1. Read to fd and add to linked list
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	// 2. Extract from stash to line
	// 3. Clean up stash
	return (line);
}

void	read_and_stash(int fd, t_list *stash, int *readed)
{
	char *buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (!found_new_line(*stash) && readed != 0)
	{
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
	}
}

int	found_new_line(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	i = 0;
	current = get_last_node(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list *get_last_node(t_list *stash)
{
	t_list	last_node;

	last_node = stash;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}