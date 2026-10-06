
#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	ft_lstadd_front(&list, ft_lstnew("Last"));
	ft_lstadd_front(&list, ft_lstnew("Middle"));
	ft_lstadd_front(&list, ft_lstnew("Beginning"));
	tmp = list;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (0);
}
