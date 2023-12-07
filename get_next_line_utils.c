#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;
	
	last_node = lst;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->data);
		next = current->next;
		free(current);
		current = next;
	}
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}