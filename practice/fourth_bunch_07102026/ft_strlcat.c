
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	dstlen = i;
	if (dstlen == dstsize)
		return (ft_strlen(src) + dstlen);
	j = 0;
	while ((i + j) < dstsize - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + dstlen);
}

int	main(void)
{
	char x[100] = "Hakuna ";
	char *y = "Matata!";
	char a[100] = "Hakuna ";
	char *b = "Matata!";

	int	e = ft_strlcat(x, y, 0);
	int	f = strlcat(a, b, 0);

	printf("%s | %s\n", x, a);
	printf("%d | %d\n", e, f);
}
