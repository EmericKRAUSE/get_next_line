# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void	add_to_stash(t_list **stash, char *buf, int readed);
int		found_newline(t_list *stash);
char	*extract_line(char *stash);
char	*clear_stash(char *stash);
char	*get_next_line(int fd);
int		ft_strlen(char *stash);
char	*ft_bzero(char *stash);
t_list	*ft_lstnew(void *data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);



# endif