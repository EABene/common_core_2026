/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:24:49 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 12:25:13 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dupe;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dupe = malloc(size * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	ft_memcpy(dupe, s1, size);
	return (dupe);
}
