/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:07:31 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:07:49 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	if (f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>
static void	*to_upper_copy(void *content)
{
	char	*copy;
	int		i;

	copy = ft_strdup((char *)content);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (copy[i] != '\0')
	{
		copy[i] = ft_toupper(copy[i]);
		i++;
	}
	return (copy);
}

static void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list	*head;
	t_list	*mapped;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew("wisconsin"));
	ft_lstadd_back(&head, ft_lstnew("kentucky"));
	ft_lstadd_back(&head, ft_lstnew("georgia"));
	mapped = ft_lstmap(head, to_upper_copy, free);
	printf("--- original ---\n");
	print_list(head);
	printf("--- mapped ---\n");
	print_list(mapped);
	ft_lstclear(&mapped, free);
	return (0);
}
*/
