/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:15:46 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 12:16:07 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			bytes;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && count > (size_t)-1 / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
