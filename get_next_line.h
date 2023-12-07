# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE=42
# endif

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stash(t_list *lst);
int		ft_strlen(char *str);
void	read_and_stash(int fd, t_list **lst);


# endif