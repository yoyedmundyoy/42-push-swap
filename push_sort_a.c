#include "push_swap.h"

void push_sort_a(t_node **a, t_node **b)
{
    int i;

    while (*b)
    {
        i = calculate_cost_ba(*a, *b);
        apply_rotate(a, b, i, 'b');
    }
}

int calculate_cost_ba(t_node *a, t_node *b)
{
    t_node *tmp;
    int cost;

    tmp = b;

    cost = cost_rrarrb_ba(a, b, tmp->num);

    while (tmp)
    {
        if (cost_rrarrb_ba(a, b, tmp->num) < cost)
            cost = cost_rrarrb_ba(a, b, tmp->num);
        if (cost_rrarb_ba(a, b, tmp->num) < cost)
            cost = cost_rrarb_ba(a, b, tmp->num);
        if (cost_rarrb_ba(a, b, tmp->num) < cost)
            cost = cost_rarrb_ba(a, b, tmp->num);
        if (cost_rarb_ba(a, b, tmp->num) < cost)
            cost = cost_rarb_ba(a, b, tmp->num);
        tmp = tmp->next;
    }
    
    return (cost);
}

int cost_rrarrb_ba(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_target_index_a(a, num))
        i = lstsize(a) - find_target_index_a(a, num);
    if (i < (lstsize(b) - find_index(b, num)) && find_index(b, num))
        i = lstsize(b) - find_index(b, num);
    return (i);
}

int cost_rrarb_ba(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_target_index_a(a, num))
        i = lstsize(a) - find_target_index_a(a, num);
    i = i + find_index(b, num);
    return (i);
    
}

int cost_rarrb_ba(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_target_index_a(a, num))
        i = lstsize(a) - find_target_index_a(a, num);
    i = i + find_index(b, num);
    return (i);
}

int cost_rarb_ba(t_node *a, t_node *b, int num)
{
    int i;

    i = find_target_index_a(a, num);
    if (i < (find_index(b, num)))
        i = find_index(b, num);
    return (i);
}
int find_target_index_a(t_node *head, int num)
{
    int i;
    t_node *tmp;

    i = 1;
    if ((num < head->num) && (num > lstlast(head)->num))
        i = 0;
    else if ((num > stack_max(head)) || (num < stack_min(head)))
        i = find_index(head, stack_min(head));
    else
    {
        tmp = head->next;
        while (tmp && ((num < head->num) || (num > tmp->num)))
        {
            head = head->next;
            tmp = head->next;
            ++i;
        }
    }
    return (i);
}

void apply_rotate_b(t_node **a, t_node **b, int cost, char stack)
{
    t_node *tmp;

    tmp = *b;
    while (cost > -1)
    {
        if (cost_rrarrb_ba(*a, *b, tmp->num) == cost)
            cost = apply_rrarrb(a, b, tmp->num, stack);
        else if (cost_rrarb_ba(*a, *b, tmp->num) == cost)
            cost = apply_rrarb(a, b, tmp->num, stack);
        else if (cost_rarrb_ba(*a, *b, tmp->num) == cost)
            cost = apply_rarrb(a, b, tmp->num, stack);
        else if (cost_rarb_ba(*a, *b, tmp->num) == cost)
            cost = apply_rarb(a, b, tmp->num, stack);
        else 
            tmp = tmp->next;
    }
}