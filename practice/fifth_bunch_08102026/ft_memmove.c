
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char *ptrdst;
	unsigned char *ptrsrc;

	ptrdst = (unsigned char *)dest;
	ptrsrc = (const unsigned char *)src;
	i = 0;
	n_dupe = n;
	if (ptrdst > ptrsrc) // backwards copying
	{
		while (n > 0)
		{
			n--;
			ptrdst[n] = ptrsrc[n];
		}
	}
	else // forwards copying
		while (i < n)
	{
		ptrdst[i] = ptrsrc[i];
		i++;
	}
	return (dest);
}
// wenn dest kleiner, vorwärts kopieren ist ok
int	main(void)
{
	char x[100] = "XXXXXXXXXXXXXXXXXXXXXXX";
	char *y = "Test String.";

	ft_memmove(x, y, 5);
	printf("%s\n", x);
}
