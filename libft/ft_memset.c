/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 16:32:24 by bsandler          #+#    #+#             */
/*   Updated: 2026/09/28 17:28:32 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	// *s is pointer
	// c is character to be filled in
	// 
	unsigned char	*p;
	unsigned char	d;
	size_t			i;

	p = (unsigned char *)	s;
	d = c;
	i = 0;
	while (i < n)
	{
		p[i] = d;
		i++;
	}
	return (s);
}

int	main(void)
{
	unsigned char c[60];
	int	i;

	i = 0;
	ft_memset(c, 38, 50);
	while (i < 60)
	{
		printf("%c", c[i]);
		i++;
	}
}
