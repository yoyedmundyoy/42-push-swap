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

t_node *create_node(int n)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        handle_error();
    node->num = n;
    node->next = NULL;
    return (node);
}

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

t_node	*lstlast(t_node *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int stack_sorted(t_node *lst)
{
	int prev_num;

	prev_num = lst->num;
	while (lst)
	{
		if (prev_num > lst->num)
			return (0);
		prev_num = lst->num;
		lst = lst->next;
	}
	return (1);
}

int	lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}
