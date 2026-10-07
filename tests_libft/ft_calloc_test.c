
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	unsigned char	*p;
	void			*a;
	void			*b;
	size_t			i;

	p = ft_calloc(10, sizeof(int));
	i = 0;
	while (p && i < 10 * sizeof(int) && p[i] == 0)
		i++;
	printf("40 Bytes auf 0:     %s\n", i == 40 ? "OK" : "FAIL");
	free(p);
	a = ft_calloc(0, 5);
	b = ft_calloc(5, 0);
	printf("0-Faelle eindeutig: %s\n", a && b && a != b ? "OK" : "FAIL");
	free(a);
	free(b);
	printf("Ueberlauf 1:        %s\n", ft_calloc(SIZE_MAX, 2) == NULL ? "OK" : "FAIL");
	printf("Ueberlauf 2:        %s\n", ft_calloc(2, SIZE_MAX / 2 + 1) == NULL ? "OK" : "FAIL");
	return (0);
}

