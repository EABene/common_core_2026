
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	printf("=== TEST 1 ft_lstnew.c ===\n");
	char	*text = "John Snow";
	t_list	*node;

	node = ft_lstnew(text);
	// check return value (should return node, should not be NULL)
	if (node == NULL)
	{
		return (0);
		printf("FAIL - lstnew returned NULL");
	}
	// check content
	printf("Node Content: %s\n", (char *)node->content);

	// check if next is NULL
	printf("Next Node: %p\n", (char *)node->next);
	printf("\n=== TEST 2 ft_lstadd_front.c ===\n");
	ft_lstadd_back(


}
