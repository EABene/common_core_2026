
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //delete later
# include <stdlib.h>
# include <stddef.h>

typedef struct	s_stack
{
	int	*data;
	int	size;
}				t_stack;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);


#endif
