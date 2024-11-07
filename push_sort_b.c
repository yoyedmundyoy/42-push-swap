#include "push_swap.h"

void push_sort_b(t_node **a, t_node **b)
{
    int i;

    i = 0;
    while (i < 2)
    {
        if (lstsize(*a) > 3 && !check_sorted(*a))
            pb(a, b, 1);
        ++i;
    }
        
    // sort till 3 or stack a sorted
    while (lstsize(*a) > 3 && !check_sorted(*a))
        sort_b_step(a, b);
    // if stack a is not sorted then sort 3 stack a
    if (!check_sorted(*a))
        sort_three(a);

}

void sort_three(t_node **a)
{
    if (stack_min(*a) == (*a)->num)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (stack_max(*a) == (*a)->num)
	{
		ra(a, 1);
		if (!check_sorted(*a))
			sa(a, 1);
	}
	else
	{
		if (find_index(*a, stack_max(*a)) == 1)
			rra(a, 1);
		else
			sa(a, 1);
	}
}

void sort_b_step(t_node **a, t_node **b)
{
    int i;

    // calculate cheapest node
    i = calculate_cost(*a, *b);
    
    // apply rotate and push cheapest node
    apply_rotate(a, b, i, 'a');
}

int calculate_cost(t_node *a, t_node *b)
{
    t_node *tmp;
    int cost;

    tmp = a;
    cost = cost_rrarrb(a, b, tmp->num);
    while (tmp)
    {
        if (cost_rrarrb(a, b, tmp->num) < cost)
            cost = cost_rrarrb(a, b, tmp->num);
        if (cost_rrarb(a, b, tmp->num) < cost)
            cost = cost_rrarb(a, b, tmp->num);
        if (cost_rarrb(a, b, tmp->num) < cost)
            cost = cost_rarrb(a, b, tmp->num);
        if (cost_rarb(a, b, tmp->num) < cost)
            cost = cost_rarb(a, b, tmp->num);
        tmp = tmp->next;
    }

    return (cost);
}

int find_index(t_node *head, int num)
{
    int i;

    i = 0;
    while (head && (head->num != num))
    {
        head = head->next;
        ++i;
    }
    return (i);
}

int find_target_index_b(t_node *head, int num)
{
    int i;
    t_node *tmp;

    i = 1;
    if ((num > head->num) && (num < lstlast(head)->num))
        i = 0;
    else if ((num > stack_max(head)) || (num < stack_min(head)))
        i = find_index(head, stack_max(head));
    else
    {
        tmp = head->next;
        while (tmp && ((num > head->num) || (num < tmp->num)))
        {
            head = head->next;
            tmp = head->next;
            ++i;
        }
    }
    return (i);
}

int stack_max(t_node *head)
{
    int max;

    max = head->num;
    while (head)
    {
        if (head->num > max)
            max = head->num;
        head = head->next;
    }
    return (max);
}

int stack_min(t_node *head)
{
    int min;

    min = head->num;
    while (head)
    {
        if (head->num < min)
            min = head->num;
        head = head->next;
    }
    return (min);
}

int cost_rrarrb(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_index(a, num))
        i = lstsize(a) - find_index(a, num);
    if (i < (lstsize(b) - find_target_index_b(b, num)) && find_target_index_b(b, num))
        i = lstsize(b) - find_target_index_b(b, num);
    return (i);
}

int cost_rrarb(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_index(a, num))
        i = lstsize(a) - find_index(a, num);
    i = i + find_target_index_b(b, num);
    return (i);
    
}

int cost_rarrb(t_node *a, t_node *b, int num)
{
    int i;

    i = 0;
    if (find_target_index_b(b, num))
        i = lstsize(b) - find_target_index_b(b, num);
    i = i + find_index(a, num);
    return (i);
}

int cost_rarb(t_node *a, t_node *b, int num)
{
    int i;
    
    i = find_index(a, num);
    if (i < (find_target_index_b(b, num)))
        i = find_target_index_b(b, num);
    return (i);
}

void apply_rotate(t_node **a, t_node **b, int cost, char stack)
{
    if (stack == 'a')
        apply_rotate_a(a, b, cost, stack);
    else if (stack == 'b')
        apply_rotate_b(a, b, cost, stack);
}

void apply_rotate_a(t_node **a, t_node **b, int cost, char stack)
{
    t_node *tmp;

    tmp = *a;
    while (cost > -1)
    {
        if (cost_rrarrb(*a, *b, tmp->num) == cost)
            cost = apply_rrarrb(a, b, tmp->num, stack);
        else if (cost_rrarb(*a, *b, tmp->num) == cost)
            cost = apply_rrarb(a, b, tmp->num, stack);
        else if (cost_rarrb(*a, *b, tmp->num) == cost)
            cost = apply_rarrb(a, b, tmp->num, stack);
        else if (cost_rarb(*a, *b, tmp->num) == cost)
            cost = apply_rarb(a, b, tmp->num, stack);
        else 
            tmp = tmp->next;
    }
}


int apply_rrarrb(t_node **a, t_node **b, int num, char stack)
{
    if (stack == 'a')
    {
        while ((*a)->num != num && find_target_index_b(*b, num) > 0)
            rrr(a, b, 1);
        while ((*a)->num != num)
            rra(a, 1);
        while (find_target_index_b(*b, num) > 0)
            rrb(b, 1);
        pb(a, b, 1);
    }
    else if (stack == 'b')
    {
        while ((*b)->num != num && find_target_index_a(*a, num) > 0)
            rrr(a, b, 1);
        while ((*b)->num != num)
            rrb(b, 1);
        while (find_target_index_a(*a, num) > 0)
            rra(a, 1);
        pa(a, b, 1);
    }
    return (-1);
}

int apply_rrarb(t_node **a, t_node **b, int num, char stack)
{
    if (stack == 'a')
    {
        while ((*a)->num != num)
            rra(a, 1);
        while (find_target_index_b(*b, num) > 0)
            rb(b, 1);
        pb(a, b, 1);
    }
    else if (stack == 'b')
    {
        while ((*b)->num != num)
            rrb(a, 1);
        while (find_target_index_a(*a, num) > 0)
            ra(a, 1);
        pa(a, b, 1);
    }
    return (-1);
}

int apply_rarrb(t_node **a, t_node **b, int num, char stack)
{
    if (stack == 'a')
    {
        while ((*a)->num != num)
            ra(a, 1);
        while (find_target_index_b(*b, num) > 0)
            rrb(b, 1);
        pb(a, b, 1);
    }
    else if (stack == 'b')
    {
        while ((*b)->num != num)
            rb(b, 1);
        while (find_target_index_a(*a, num) > 0)
            rra(a, 1);
        pa(a, b, 1);
    }
    return (-1);
}

int apply_rarb(t_node **a, t_node **b, int num, char stack)
{
    if (stack == 'a')
    {
        while ((*a)->num != num && find_target_index_b(*b, num) > 0)
            rr(a, b, 1);
        while ((*a)->num != num)
            ra(a, 1);
        while (find_target_index_b(*b, num) > 0)
            rb(b, 1);
        pb(a, b, 1);
    }
    else if (stack == 'b')
    {
        while ((*b)->num != num && find_target_index_a(*a, num) > 0)
            rr(a, b, 1);
        while ((*b)->num != num)
            rb(b, 1);
        while (find_target_index_a(*a, num) > 0)
            ra(a, 1);
        pa(a, b, 1);
    }
    return (-1);
}
