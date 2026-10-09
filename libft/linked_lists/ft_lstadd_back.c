
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

 int main(void)
{
	t_list *list;
	t_list *tmp;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew("Last"));
	ft_lstadd_back(&list, ft_lstnew("Middle"));
	ft_lstadd_back(&list, ft_lstnew("Beginning"));
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
