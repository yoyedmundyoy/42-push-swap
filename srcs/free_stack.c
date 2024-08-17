#include "../includes/push_swap.h"

void	free_stack(t_node **lst)
{
	t_node	*next;
	t_node	*curr;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	lst[0] = (void *)0;
}