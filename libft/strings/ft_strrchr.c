/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:20:54 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 16:21:33 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	d;
	size_t	i;

	ptr = (char *) s;
	d = (char) c;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	while (i != 0)
	{
		if (ptr[i] == d)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == d)
		return (&ptr[i]);
	return (NULL);
}
