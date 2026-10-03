/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:17:49 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 12:18:08 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;

	if (dst == src || len == 0)
		return (dst);
	ptrdst = (unsigned char *) dst;
	ptrsrc = (const unsigned char *) src;
	if (ptrdst > ptrsrc)
	{
		while (len > 0)
		{
			len--;
			ptrdst[len] = ptrsrc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
