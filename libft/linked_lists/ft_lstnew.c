/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:56:04 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 15:05:05 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int	main(void)
{
	t_list	*node;
	int		number;

	node = ft_lstnew("East Texas Bullfrog");
	if (node == NULL)
		return (1);
	printf("content: %s\n", (char *)node->content);
	printf("next ist NULL: %s\n", node->next == NULL ? "ja" : "nein");
	free(node);
	number = 70040;
	node = ft_lstnew(&number);
	printf("content: %d\n", *(int *)node->content);
	printf("gleiche Adresse: %s\n", node->content == &number ? "ja" : "nein");
	free(node);
	return (0);
}

