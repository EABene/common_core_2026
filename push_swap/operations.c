#include "push_swap.h"

// sa - swap first two elements at top of stack a
// sb
// ss = sa and sb
// pa - first of b is put to a
// pb - first of a is put to b
// ra - rotate a, first becomes last
// rb
// rr
// rra - reverse rotate a, last becomes first one
// rrb
// rrr

void sa(t_stack *a, t_stack *b)
{
	int	temp;

	(void) b;
	temp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = temp;
}

void sb(t_stack *a, t_stack *b)
{
	int	temp;

	(void) a;
	temp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = temp;
}

void ss(t_stack *a, t_stack *b)
{
	sa(a, b);
	sb(a, b);
}

void pa(t_stack *a, t_stack *b)
{
	
}

void pb(t_stack *a, t_stack *b)
{
	
}

void ra(t_stack *a, t_stack *b)
{
	
}
