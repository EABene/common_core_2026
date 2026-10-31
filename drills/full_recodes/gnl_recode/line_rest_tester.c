
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*x = "Example \n Rest";
	char	*y;
	char	*z;

	y = ft_get_line(x);
	z = ft_get_rest(x);
	printf("%s \n %s \n", y, z);
}

