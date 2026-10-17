
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "ab\0cd\xff";
	char	mine[10];
	char	real[10];

	memset(mine, 'X', 10);
	memset(real, 'X', 10);
	ft_memcpy(mine, src, 6);
	memcpy(real, src, 6);
	printf("Nullbyte und 255:  %s\n", memcmp(mine, real, 10) ? "FAIL" : "OK");
	ft_memcpy(mine, "Hallo", 3);
	memcpy(real, "Hallo", 3);
	printf("teilweise:         %s\n", memcmp(mine, real, 10) ? "FAIL" : "OK");
	ft_memcpy(mine, "zzz", 0);
	printf("n = 0:             %s\n", memcmp(mine, real, 10) ? "FAIL" : "OK");
	printf("Rueckgabewert:     %s\n", ft_memcpy(mine, src, 2) == mine ? "OK" : "FAIL");
	return (0);
}
*/
