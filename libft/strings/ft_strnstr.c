
#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;
	
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *) haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && needle[j] != '\0' && haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}

static void	check(const char *name, const char *big, const char *little,
	size_t len)
{
	char	*mine;
	char	*real;

	mine = ft_strnstr(big, little, len);
	real = strnstr(big, little, len);
	if (mine != real)
		printf("FAIL %-28s deins: %p | original: %p\n",
			name, (void *)mine, (void *)real);
	else if (mine == NULL)
		printf("OK   %-28s NULL\n", name);
	else
		printf("OK   %-28s Position %ld\n", name, (long)(mine - big));
}

int	main(void)
{
	const char	*s = "Flusskrebs";

	check("Treffer in der Mitte", s, "sskr", 20);
	check("Treffer am Anfang", s, "Flu", 20);
	check("Treffer am Ende", s, "krebs", 20);
	check("nicht vorhanden", s, "fisch", 20);
	check("len schneidet Treffer ab", s, "krebs", 7);
	check("len passt genau", s, "krebs", 10);
	check("len eins zu kurz", s, "krebs", 9);
	check("leere Nadel", s, "", 20);
	check("leere Nadel, len 0", s, "", 0);
	check("len 0", s, "F", 0);
	check("Nadel laenger als big", "abc", "abcd", 10);
	check("Nadel gleich big", s, s, 10);
	check("Nadel gleich big, len kurz", s, s, 2);
	check("Teiltreffer davor", "aaab", "aab", 10);
	check("leerer Heuhaufen", "", "a", 10);
	check("nach \\0 nicht suchen", "ab\0cd", "cd", 5);
	return (0);
}
