
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i] != '\0')
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	j = 0;
	while (i + j < size - 1 && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

int	main(void)
{
	char x[100] = "East Texas Town of el Paso";
	char *y = " is nice";
	char c[100] = "East Texas Town of el Paso";
	char *d = " is nice";

	size_t a = ft_strlcat(x, y, 99);
	size_t b = strlcat(c, d, 99);

	printf("%s\n", x);
	printf("%zu\n", a);
}
