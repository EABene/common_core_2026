
#include "push_swap.h"

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
	sa(&a, &b);
	print_stacks(&a, &b);
	sa(&a, &b);
	print_stacks(&a, &b);

	free_stacks(&a, &b);
	return (0);
}
