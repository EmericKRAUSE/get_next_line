/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrause <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:28:51 by ekrause           #+#    #+#             */
/*   Updated: 2023/12/14 11:28:54 by ekrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	read_and_add(int fd, char **line, char **stash, int *readed);
int		found_newline(char *stash);
char	*ft_strjoin(char *s1, char *s2);
void	free_stash(char *line);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
void	extract_line(char *stash, char **line);
void	clear_stash(char **stash);

#endif
