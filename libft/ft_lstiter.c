/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:03:10 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:04:06 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
static void add_three(void *content)
{
	*(int *)content = *(int *)content + 3;
}

int	main(void)
{
	t_list	*head = NULL;
	t_list	*tmp;
	int	a = 4;
	int	b = 7;
	int	c = 11;

	ft_lstadd_back(&head, ft_lstnew(&a));
	ft_lstadd_back(&head, ft_lstnew(&b));
	ft_lstadd_back(&head, ft_lstnew(&c));
	ft_lstiter(head, add_three);

	tmp = head;
	while (tmp != NULL)
	{
		printf("%d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
*/
