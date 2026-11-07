
#include "push_swap.h"

static void	print_sizes(t_stack *a, t_stack *b)
{
	printf("size stack a: %i\n", a->size);
	printf("size stack b: %i\n", b->size);

}

float compute_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	for (i = 0; i < a->size; i++)
	{
		for (j = 0; j < a->size; j++)
		{
			total_pairs++;
			if (a->data[i] > a->data[j])
				mistakes++;
		}
	}
	return (mistakes / total_pairs);
}

/*
int	check_flags(char **argv)
{
	char	*simple = "--simple";
	char	*medium = "--medium";
	char	*complex = "--complex";
	char	*adaptive = "--adaptive";
	int		i = 0;

	if (strncmp(simple, *argv[i], 9) == 0)
		return (simple);
}
*/

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
	printf("Disorder: %f \n", compute_disorder(&a));
	selection_sort(&a, &b);
	print_stacks(&a, &b);
	print_sizes(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
