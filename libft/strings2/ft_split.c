
// #include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_words(char const *s, char del)
{
	size_t	i;
	size_t	w;
	int		l_switch;

	i = 0;
	w = 0;
	l_switch = 0;
	while (s[i] != '\0')
	{
		if (s[i] == del)
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

char	**ft_split(char const *s, char c)
{
	char	**map;

	map = malloc(count_words(s, c) + 1);
	if (map == NULL)
		return (NULL);

}

int	main(void)
{

}

