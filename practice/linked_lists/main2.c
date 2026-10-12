
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*text;
	t_list	*node;

	node = ft_lstnew(text);
	// check return value (should return node, should not be NULL)
	if (node == NULL)
	{
		return (NULL);
		printf("FAIL - lstnew returned NULL");
	}
	// check content


	// check if next is NULL

}
