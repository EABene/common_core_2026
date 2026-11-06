
#include <stdio.h>

int ft_counter(void)
{
	static int count; //guaranteed 0, because static keyword

	count++;
	return (count);
}

int	main(void)
{
	int result;

	ft_counter();
	ft_counter();
	ft_counter();
	ft_counter();
	ft_counter();
	result = ft_counter();
	printf("Function calles %i times\n", result);
}
