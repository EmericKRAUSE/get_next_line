#include "get_next_line.h"
#include <stdio.h>

void	add_to_stash(t_list **stash, char *buf)
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
		if (stash->data != NULL)
		{
			i = 0;
			while (stash->data[i])
			{
				if (stash->data[i] == '\n' || stash->data[i] == '\0')
					return (1);
				i++;
			}
		}
		stash = stash->next;
	}
	return (0);
} 

char	*extract_line(t_list *stash)
{
	t_list	*last_node;
	char	*line;

	last_node = ft_lstlast(stash);
	line = malloc(sizeof(char) * ft_lstlen(stash) + 1);
	if (!line)
		return (NULL);
	line = ft_lstcpy(last_node, line);
	return (line);
}

void	clear_stash(t_list **stash)
{
	char	*new_data;
	t_list	*last_node;
	int		i;
	int		j;

	j = 0;
	i = 0;
	last_node = ft_lstlast(*stash);
	while (last_node->data[i] && last_node->data[i] != '\n')
		i++;
	if (last_node->data[i] == '\n')
	{
		i++;
		while (last_node->data[i + j])
			j++;
		new_data = malloc(sizeof(char) * (j + 1));
		if (!new_data)
			return ;
		j = 0;
		while (last_node->data[i + j])
		 	new_data[j++] = last_node->data[i++];
		new_data[j] = '\0';
		ft_lstclear(stash);
		*stash = ft_lstnew(new_data);
		free(new_data);
	}
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
		readed = read(fd, buf, BUFFER_SIZE);
		printf ("%d", readed);
		buf[readed] = '\0';
		add_to_stash(&stash, buf);
	}
	line = extract_line(stash);
	clear_stash(&stash);
	return (line);
}
