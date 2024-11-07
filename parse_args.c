#include "push_swap.h"

static t_node *parse_quoted(char *nums)
{
    char **num_arr;
    t_node *stack;
    int i;

    stack = NULL;
    num_arr = ft_split(nums, ' ');
    i = 0;
    while (num_arr[i])
    {
        if (handle_atoi(num_arr[i]) == -1)
            handle_error();
        add_back(&stack, create_node(ft_atoi(num_arr[i])));
        free(num_arr[i]);
        ++i;
    }
    free(num_arr);
    return (stack);
}

static t_node *parse_unquoted(int argc, char *argv[])
{
    int i;
    t_node *stack;

    stack = NULL;
    i = 1;
    while (i < argc)
    {
        if (handle_atoi(argv[i]) == -1)
            handle_error();
        add_back(&stack, create_node(ft_atoi(argv[i])));
        ++i;
    }
    return (stack);
}

static int check_dup(t_node *stack)
{
    t_node *tmp;

    while (stack)
    {
        tmp = stack->next;
        while (tmp)
        {
            if (stack->num == tmp->num)
                return (1);
            tmp = tmp->next;
        }
        stack = stack->next;
    }
    return (0);
}

t_node *parse_args(int argc, char *argv[])
{
    t_node *a;

    a = NULL;
    if (argc < 2)
        handle_error();
    else if (argc == 2)
        a = parse_quoted(argv[1]);
    else
        a = parse_unquoted(argc, argv);
    if (check_dup(a))
    {
        free_stack(&a);
        handle_error();
    }
    return (a);
}