#include "../includes/push_swap.h"

// sa : swap a - swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
void sa(t_node **a, int print)
{
    t_node *tmp;

    if (!(*a) || lstsize(*a) < 2)
        return ;
    tmp = *a;
    (*a) = (*a)->next;
    tmp->next = (*a)->next;
    (*a)->next = tmp;
    if (print)
        write(1, "sa\n", 3);
}

// sb : swap b - swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
void sb(t_node **b, int print)
{
    t_node *tmp;

    if (!(*b) || lstsize(*b) < 2)
        return ;
    tmp = *b;
    (*b) = (*b)->next;
    tmp->next = (*b)->next;
    (*b)->next = tmp;
    if (print)
        write(1, "sb\n", 3);
}

// ss : sa and sb at the same time
void ss(t_node **a, t_node **b, int print)
{
    sa(a, 0);
    sb(b, 0);
    if (print)
        write(1, "ss\n", 3);
}

// pa : push a
// take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty.
void pa(t_node **a, t_node **b, int print)
{
    if (!(*b))
        return ;
    
}

// pb : push b 
// take the first element at the top of a and put it at the top of b. 
// Do nothing if a is empty.
void pb()
{

}