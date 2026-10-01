
#include "libft.h"

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

static void	free_map(char **map, int j)
{
	while (j > 0)
	{
		j--;
		free(map[j]);
	}
	free(map);
}

char	**ft_split(char const *s, char c)
{
	char	**map;
	int		i; // index for whole string
	int		j; //index for map pointer
	int		len;

	map = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = length_word(s, c, i);
			map[j] = ft_substr(s, i, len);
			if (map[j] == NULL)
			{
				free_map(map, j);
				return (NULL);
			}
			j++;
			i = i + len;
		}
		else
			i++;
	}
	map[j] = NULL;
	return(map);
}
