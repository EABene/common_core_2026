/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:02:57 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:04:25 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
static void	del(void *content)
{
	printf("del: %s\n", (char *)content);
	free(content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew(ft_strdup("Texas"));
	node2 = ft_lstnew(ft_strdup("Oklahoma"));
	node1->next = node2;
	ft_lstdelone(node1, del);
	printf("node2 still here: %s\n", (char *)node2->content);
	ft_lstdelone(node2, del);
	return (0);
}
*/
