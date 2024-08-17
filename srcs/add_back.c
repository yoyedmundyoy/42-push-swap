#include "../includes/push_swap.h"

void	add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}