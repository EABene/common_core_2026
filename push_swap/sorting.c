#include "push_swap.h"

int		find_lowest(t_stack *arr)
{
	int	i;
	int	lowest;

	i = 0;
	lowest = arr->data[0];
	while (i < arr->size)
	{
		if (lowest > arr->data[i])
			lowest = arr->data[i];
		i++;
	}
	return (lowest);
}

void	selection_sort(t_stack *a, t_stack *b)
{
	int	lowest;

	while (a->size > 0)
	{
		lowest = find_lowest(a);
		while (lowest != a->data[0])
			ra(a, b);
		pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
