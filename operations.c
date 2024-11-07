#include "push_swap.h"

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
    t_node *tmp;

    if (!(*b))
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    if (print)
        write(1, "pa\n", 3);
}

// pb : push b 
// take the first element at the top of a and put it at the top of b. 
// Do nothing if a is empty.
void pb(t_node **a, t_node **b, int print)
{
    t_node *tmp;

    if (!(*a))
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    if (print)
        write(1, "pb\n", 3);
}


// ra : rotate a
// shift up all elements of stack a by 1. 
// The first element becomes the last one.
void ra(t_node **a, int print)
{
    t_node *tmp;
    
    tmp = *a;
    *a = (*a)->next;
    tmp->next = NULL;
    add_back(a, tmp);
    if (print)
        write(1, "ra\n", 3);
}

// rb : rotate b
// shift up all elements of stack b by 1. 
// The first element becomes the last one.
void rb(t_node **b, int print)
{
    t_node *tmp;
    
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;
    add_back(b, tmp);
    if (print)
        write(1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void rr(t_node **a, t_node **b, int print)
{
    ra(a, 0);
    rb(b, 0);
    if (print)
        write(1, "rr\n", 3);
}

// rra : reverse rotate a
// shift down all elements of stack a by 1. 
// The last element becomes the first one.
void rra(t_node **a, int print)
{
    t_node *tmp;

    tmp = lstlast(*a);
    tmp->next = *a;
    *a = tmp;
    remove_back(*a, tmp);
    if (print)
        write(1, "rra\n", 4);
}

// rrb : reverse rotate b 
// shift down all elements of stack b by 1. 
// The last element becomes the first one.
void rrb(t_node **b, int print)
{
    t_node *tmp;

    tmp = lstlast(*b);
    tmp->next = *b;
    *b = tmp;
    remove_back(*b, tmp);
    if (print)
        write(1, "rrb\n", 4);
}

//rrr : rra and rrb at the same time.
void rrr(t_node **a, t_node **b, int print)
{
    rra(a, 0);
    rrb(b, 0);
    if (print)
        write(1, "rrr\n", 4);
}