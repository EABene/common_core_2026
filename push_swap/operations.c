
#include "push_swap.h"

void	sa(t_stack *a, t_stack *b)
{
// sa - swap first two elements at top of stack a
	int	temp;

	(void) b;
	temp = a->data[0];
	a->data[0] = a->data[1];
	a->data[1] = temp;
	ft_puts("sa");
}

void	sb(t_stack *a, t_stack *b)
{
// sb - swap first two elements at top of stack b
	int	temp;

	(void) a;
	temp = b->data[0];
	b->data[0] = b->data[1];
	b->data[1] = temp;
	ft_puts("sb");
}

void	ss(t_stack *a, t_stack *b)
{
// ss = sa and sb
	sa(a, b);
	sb(a, b);
	ft_puts("ss");
}

void	pa(t_stack *a, t_stack *b)
{
// pa - first of b is put to a
	int	i;

	i = a->size - 1;
	while (i >= 0)
	{
		a->data[i + 1] = a->data[i];
		i--;
	}
	a->data[0] = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i+1];
		i++;
	}
	a->size++;
	b->size--;
	ft_puts("pa");
}

void	pb(t_stack *a, t_stack *b)
{
// pb - first of a is put to b
	int	i;

	i = b->size - 1;
	while (i >= 0)
	{
		b->data[i + 1] = b->data[i];
		i--;
	}
	b->data[0] = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i+1];
		i++;
	}
	b->size++;
	a->size--;
	ft_puts("pb");
}

void	ra(t_stack *a, t_stack *b)
{	
// ra - rotate a, first becomes last
	int	i;
	int	tmp;

	(void) b;
	i = 0;
	tmp = a->data[0];

	while (i < a->size)
	{
		a->data[i] = a->data[i+1];
		i++;
	}
	a->data[a->size - 1] = tmp;
	ft_puts("ra");
}

void	rb(t_stack *a, t_stack *b)
{	
// rb - rotate b, first becomes last
	int	i;
	int	tmp;

	(void) a;
	i = 0;
	tmp = b->data[0];
	while (i < b->size)
	{
		b->data[i] = b->data[i+1];
		i++;
	}
	b->data[b->size - 1] = tmp;
	ft_puts("rb");
}

void	rr(t_stack *a, t_stack *b)
{
// rr - ra & rb
	ra(a, b);
	rb(a, b);
	ft_puts("rr");
}

void	rra(t_stack *a, t_stack *b)
{
// rra - reverse rotate a, last becomes first one
	int	i;
	int	tmp;

	(void) b;
	i = a->size - 1;
	tmp = a->data[a->size - 1];
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
	ft_puts("rra");
}

void	rrb(t_stack *a, t_stack *b)
{
// rrb - reverse rotate b, last becomes first one
	int	i;
	int	tmp;

	(void) a;
	i = b->size - 1;
	tmp = b->data[b->size - 1];
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = tmp;
	ft_puts("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
// rrr - rra & rrb
	rra(a, b);
	rrb(a, b);
	ft_puts("rrr");
}

