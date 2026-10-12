/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:56:04 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/10 15:07:20 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
int	main(void)
{
	t_list	*node;
	char	*text;
	int		number;

	text = "Bullfrog";
	node = ft_lstnew(text);
	if (node == NULL)
		return (1);
	printf("Content string:  %s\n", (char *)node->content);
	free(node);
// ======
	number = 42;
	node = ft_lstnew(&number);
	if (node == NULL)
		return (1);
	printf("Content int: %d\n", *(int *)node->content);
	free(node);
//======
	node = ft_lstnew(NULL);
	if (node == NULL)
		return (1);
	printf("Content NULL: %p\n", node->content);
	free(node);
	return (0);
}
*/
