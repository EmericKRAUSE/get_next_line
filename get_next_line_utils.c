#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	last_node = lst;
	if (lst == NULL)
		return (NULL);
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

void	free_stash(t_list **lst)
{
	t_list *tmp;

	while (*lst)
	{ 
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->data);
		free (tmp);
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