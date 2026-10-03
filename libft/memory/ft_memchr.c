/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:16:15 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 12:19:55 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	sign;
	size_t			i;

	ptr = (unsigned char *) s;
	sign = c;
	i = 0;
	while (i < n)
	{
		if (sign == ptr[i])
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
