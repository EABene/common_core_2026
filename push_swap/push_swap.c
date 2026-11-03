
#include "push_swap.h"

void	print_arrays(int *a, int *b,  int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		printf("%i   %i\n", a[i], b[i]);
		i++;
	}
	printf("_   _\n");
	printf("a   b\n");
}

int		allocate_arrays(int	**a, int **b, int count)
{
	*a = ft_calloc(count, sizeof(int));
	if (!*a)
		return (0);
	*b = ft_calloc(count, sizeof(int));
	if (!*b)
		return (free(*a), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	*array_a;
	int	*array_b;
	int	i;

	if (argc <= 1)
		return (0);
	array_a = NULL;
	array_b = NULL;
	i = allocate_arrays(&array_a, &array_b, argc);
	if (!i)
		return (-1);
	i = 1;
	while (argv[i])
	{
		array_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	print_arrays(array_a, array_b, argc);
}
