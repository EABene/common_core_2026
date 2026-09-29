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
	char	*ptr;
	char	d;
	size_t	i;

	ptr = (char *) s;
	d = (char) c;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i++;
	}
	if (d == '\0')
		return (&ptr[i]);
	return (NULL);
}
