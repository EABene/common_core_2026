
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	main(void)
{
	char x[100] = "";
	char *y = "Frog";
	char a[100] = "";
	char *b = "Frog";

	size_t ret1 = ft_strlcpy(x, y, 2);
	size_t ret2 = strlcpy(a, b, 2);
	printf("%s | %s\n", x, a);
	printf("%zu | %zu\n", ret1, ret2);
}
