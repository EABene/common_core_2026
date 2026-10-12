/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:06:37 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:08:47 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	t_list			*head;
	t_list			*node1;
	t_list			*node2;
	t_list			*node3;
	t_list			*node4;

	node1 = ft_lstnew("Node");
	head = node1;
	node2 = ft_lstnew("Node");
	node3 = ft_lstnew("Node");
	node4 = ft_lstnew("Node");
	ft_lstadd_back(&head, node2);
	ft_lstadd_back(&head, node3);
	ft_lstadd_back(&head, node4);
	printf("%d\n", ft_lstsize(head));
}
*/
