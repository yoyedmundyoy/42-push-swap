#include "../includes/push_swap.h"

t_node *create_node(int n)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        handle_error();
    node->num = n;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}