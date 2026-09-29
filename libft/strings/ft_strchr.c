/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:31:54 by bsandler          #+#    #+#             */
/*   Updated: 2026/09/28 17:43:38 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s[i]);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	const char *str = "Hello my friend";

	printf("%p\n", ft_strchr(str, 'i'));
}
