#include "push_swap.h"

void	rr_sub(t_node **a, t_node **b, char *line)
{
	if (line[2] == 'a')
		rra(a, 0);
	else if (line[2] == 'b')
		rrb(b, 0);
	else if (line[2] == 'r')
		rrr(a, b, 0);
}

char	* move_and_gnl(t_node **a, t_node **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(b, 0);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(a, b, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(a, b, 0);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		rr_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(a, b, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(a, b, 0);
	else
		handle_error();
	return (get_next_line(0));
}

void	checker(t_node **a, t_node **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = move_and_gnl(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!check_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int main(int argc, char *argv[])
{
    t_node *a;
    t_node *b;
    char *line;

    b = NULL;
    a = parse_args(argc, argv);
    line = get_next_line(0);
    if (!line && !check_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && check_sorted(a))
		write(1, "OK\n", 3);
	else
		checker(&a, &b, line);
    free_stack(&b);
    free_stack(&a);
    return (0);
}