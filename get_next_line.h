# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *stash);
char	*ft_bzero(char *stash);
char	*get_next_line(int fd);
char	*clear_stash(char *stash);
char	*extract_line(char *stash);
int		found_newline(char *stash);
char	*add_to_stash(char *stash, char *buf, int readed);

# endif