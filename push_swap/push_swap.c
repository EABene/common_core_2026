
#include "push_swap.h"

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%i ", arr[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	*array;
	int	i;
	int	j;

	if (argc <= 1)
		return (0);
	array = malloc(argc);
	if (!array)
		return (-1);
	i = 1;
	j = 0;
	while (argv[i])
	{
		array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	print_array(array, argc -1);
}
