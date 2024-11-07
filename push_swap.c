#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_node *a;

    a = parse_args(argc, argv);
    if (!check_sorted(a))
        sort(&a);
    free_stack(&a);
    return (0);
}


// Test operations
// int main(int argc, char *argv[])
// {
//     t_node *a;

//     a = parse_args(argc, argv);
//     print_stack(a);
//     // sa
//     sa(&a, 1);
//     print_stack(a);
//     // ra
//     ra(&a, 1);
//     print_stack(a);
//     // rra
//     rra(&a, 1);
//     print_stack(a);
// }