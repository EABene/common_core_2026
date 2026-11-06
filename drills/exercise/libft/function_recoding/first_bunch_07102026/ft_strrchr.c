
#include <stdio.h>
#include <string.h>


char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	d;
	int		i;

	ptr = (char *) s;
	d = (char) c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (i != 0)
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		i--;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}

int	main(void)
{
	char *x = "East Texas Town of El Paso";

	printf("%s | %s\n", ft_strrchr(x, 'a'), strrchr(x, 'a'));
	printf("%s | %s\n", ft_strrchr(x, 'T'), strrchr(x, 'T'));
	printf("%s | %s\n", ft_strrchr(x, '\0'), strrchr(x, '\0'));

}
