/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:02:07 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:06:11 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
#include <stdio.h>
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*tmp;

	node1 = ft_lstnew("California");
	head = node1;
	node2 = ft_lstnew("Colorado");
	node3 = ft_lstnew("Oregon");
	node4 = ft_lstnew("Washington");
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node4);
	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
*/
