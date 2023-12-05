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

t_list *ft_lstnew(void *data)
{
	t_list *new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->data = data;
	new_list->next = NULL;
	return (new_list);
}

t_list *ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL && new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
	}
}

int	ft_lstlen(t_list *lst)
{
	int	i;
	int	count;

	count = 0;
	while (lst != NULL)
	{
		if (lst->data != NULL)
		{
			i = 0;
			while (lst->data[i])
			{
				if (lst->data[i] == '\n')
				{
					count++;
					return (count);
				}
				else
				{
					i++;
					count++;
				}
			}
		}
		lst = lst->next;
	}
	return (count);
}

char	*ft_lstcpy(t_list *lst, char *line)
{
	int	i;
	int j;

	j = 0;
	while (lst != NULL)
	{
		if (lst->data != NULL)
		{
			i = 0;
			while (lst->data[i])
			{
				if (lst->data[i] == '\n')
				{
					line[j] = lst->data[i];
					break;
				}
				else
					line[j] = lst->data[i]; 
				i++;
				j++;
			}
		}
		lst = lst->next;
	}
	line[j] = '\0';
	return (line);
}

void	ft_lstclear(t_list **lst)
{
	t_list *temp;

	if (*lst != NULL && lst != NULL)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			free(temp->data);
			free(temp);
		}
	}
}