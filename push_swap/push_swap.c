
#include "push_swap.h"

int	init_stacks(t_stack *a, t_stack *b, int count)
{
	a->data = ft_calloc(count, sizeof(int));
	if (!a->data)
		return (0);
	b->data = ft_calloc(count, sizeof(int));
	if (!b->data)
		return (free(a->data), 0);
	a->size = 0;
	b->size = 0;
	return (1);
}

void fill_stack(t_stack *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		a->data[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	a->size = i - 1;
}

void free_stacks(t_stack *a, t_stack *b)
{
	free(a->data);
	free(b->data);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	printf("Stack a: ");
	while (i < a->size)
	{
		printf("%i ", a->data[i]);
		i++;
	}
	i = 0;
	printf("\nStack b: ");
	while (i < b->size)
	{
		printf("%i ", b->data[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 1)
		return (0);
	if (!init_stacks(&a, &b, argc -1))
		return (1);
	fill_stack(&a, argv);
	print_stacks(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
