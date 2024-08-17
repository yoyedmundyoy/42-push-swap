#include "../includes/push_swap.h"

t_node	*lstlast(t_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
