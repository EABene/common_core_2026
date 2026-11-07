
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //delete later
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct	s_stack
{
	int	*data;
	int	size;
}				t_stack;

int		init_stacks(t_stack *a, t_stack *b, int count);
void	fill_stack(t_stack *a, char **argv);
void	free_stacks(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);

void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	complex_sort(t_stack *a, t_stack *b);

void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);


void	ft_puts(const char *s);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
