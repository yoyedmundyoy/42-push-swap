#include "../includes/push_swap.h"

int main(int argc, char *argv[])
{
    t_node *a;

    a = parse_args(argc, argv);
    if (!stack_sorted(a))
        ft_printf("Sort stack\n");
    free_stack(&a);
    return (0);
}