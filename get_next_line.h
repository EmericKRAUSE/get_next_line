# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
# endif

typedef	struct	s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;


# endif