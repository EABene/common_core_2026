/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsandler <bsandler@student.42vienna.c>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:23:10 by bsandler          #+#    #+#             */
/*   Updated: 2026/10/03 12:24:30 by bsandler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	w;
	int		l_switch;

	i = 0;
	w = 0;
	l_switch = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			l_switch = 0;
		else if (l_switch == 0)
		{
			l_switch = 1;
			w++;
		}
		i++;
	}
	return (w);
}

static int	length_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static char	**free_map(char **map, int j)
{
	while (j > 0)
	{
		j--;
		free(map[j]);
	}
	free(map);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**map;
	int		i;
	int		j;

	map = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			map[j] = ft_substr(s, i, length_word(s, c, i));
			if (map[j] == NULL)
				return (free_map(map, j));
			i = i + ft_strlen(map[j]);
			j++;
		}
		else
			i++;
	}
	map[j] = NULL;
	return (map);
}
