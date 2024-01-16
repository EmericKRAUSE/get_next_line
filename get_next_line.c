/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:28:13 by ekrause           #+#    #+#             */
/*   Updated: 2023/12/14 11:28:31 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			readed;

	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	line = NULL;
	read_and_add(fd, &line, &stash, &readed);
	return (line);
}

void	read_and_add(int fd, char **line, char **stash, int *readed)
{
	char	*buf;

	while (*readed > 0 && !found_newline(*stash))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *readed == 0) || *readed == -1)
		{
			free (buf);
			return ;
		}
		buf[*readed] = '\0';
		(*stash) = ft_strjoin(*stash, buf);
		free (buf);
	}
	if (*stash[0] == '\0')
	{
		free_stash(*stash);
		return ;
	}
	extract_line(*stash, line);
	clear_stash(stash);
}

void	extract_line(char *stash, char **line)
{
	int		i;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	(*line) = ft_strjoin(*line, str);
	free (str);
}

void	clear_stash(char **stash)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(*stash) - i + 1));
	if (!temp)
		return ;
	while ((*stash)[i])
		temp[j++] = (*stash)[i++];
	temp[j] = '\0';
	free(*stash);
	(*stash) = ft_strdup(temp);
	free (temp);
}
