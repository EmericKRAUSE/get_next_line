#include "get_next_line.h"

void	clear_stash(t_list **stash)
{
	t_list *last;
	t_list *clean_node;
	int i;
	int	j;

	clean_node = malloc(sizeof(t_list));
	if (!clean_node || !stash)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*stash);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data[i] && last->data[i]== '\n')
		i++;
	clean_node->data = malloc(sizeof(char) * ((ft_strlen(last->data) - i) + 1));
	if (!clean_node->data)
		return ;
	j = 0;
	while (last->data[i])
		clean_node->data[j++] = last->data[i++];
	clean_node->data[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

void	generate_line(char **line, t_list *stash)
{
	int	i;
	int j;

	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->data[i])
		{
			if (stash->data[i] == '\n')
			{
				j++;
				break;
			}
			j++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (j + 1));
}

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->data[i])
		{
			if (stash->data[i] == '\n')
			{
				(*line)[j++] = stash->data[i];
				break;
			}
			(*line)[j++] = stash->data[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	add_to_stash(t_list **stash, char *buf, int readed)
{
	t_list *new_node;
	t_list *last_node;
	int i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = malloc(sizeof(char) * (readed + 1));
	if (!new_node->data)
	{
		free (new_node);
		return ;
	}
	i = 0;
	while (buf[i] && i < readed)
	{
		new_node->data[i] = buf[i];
		i++;
	}
	new_node->data[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last_node = ft_lstlast(*stash);
	last_node->next = new_node;
}
                             
int	found_newline(t_list *stash)
{
	t_list	*current_node;
	int		i;

	if (stash == NULL)
		return (0);
	current_node = ft_lstlast(stash);
	i = 0;
	while (current_node->data[i])
	{
		if (current_node->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	read_and_stash(int fd, t_list **stash)
{
	int		readed;
	char	*buf;
	
	readed = 1;
	while (!found_newline(*stash) && readed > 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}

}

char *get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clear_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}