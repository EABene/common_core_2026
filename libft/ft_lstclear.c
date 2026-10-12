/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:02:42 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:04:44 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
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
	t_list	*head;

	head = NULL;
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Arizona")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("Texas")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("New Mexico")));
	ft_lstclear(&head, del);
	printf("head: %p\n", (void *)head);
	ft_lstclear(&head, del);
	printf("second lstclear: no crash\n");
	return (0);
}
*/
