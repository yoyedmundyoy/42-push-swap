#include "../includes/push_swap.h"

void sort(t_node **a)
{
    t_node *b;

    b = NULL;
    // If list only has 2 elements then just swap
    if (lstsize(*a) == 2)
        sa(a, 1);
    else
    {
        // 1. push and sort stack b until 3 elements left
        // in stack a, then sort stack a
        push_sort_b(a, &b);
        printf("push sort b done \n");
        print_stack(*a);
        print_stack(b);
        
        // 2. push and sort elements back from stack b to a
        push_sort_a(a, &b);
        printf("push sort a done \n");
        print_stack(*a);
        print_stack(b);
        // 3. ra or rra stack a until sorted
        final_rotate(a);
        printf("final rotate done \n");
        print_stack(*a);
        print_stack(b);
    }
}

void final_rotate(t_node **a)
{
    int i;

    i = find_index(*a, stack_min(*a));
    if (i < lstsize(*a) - i)
    {
        while ((*a)->num != stack_min(*a))
            ra(a, 0);
    }
    else
    {
        while ((*a)->num != stack_min(*a))
            rra(a, 0);
    }	
}
