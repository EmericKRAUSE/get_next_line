#include "get_next_line.h"

int	ft_strlen(char *stash)
{
	int	i;

	if (!stash)
		return  (0);
	i = 0;
	while (stash[i])
		i++;
	return (i);
}

char	*ft_bzero(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
		stash[i++] = 0;
	return (stash);
}