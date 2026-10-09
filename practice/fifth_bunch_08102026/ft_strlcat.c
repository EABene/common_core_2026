
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	j = 0;
	while (i + j < dstsize - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

int	main(void)
{
	char a[100] = "East Texas ";
	char *b = "Town of El Paso";
	char c[100] = "East Texas ";
	char *d = "Town of El Paso";

	size_t x = ft_strlcat(a, b, 99);
	size_t y = strlcat(c, d, 99);

	printf("%s | %s\n", a, c);
	printf("%zu | %zu\n", x, y);
}
