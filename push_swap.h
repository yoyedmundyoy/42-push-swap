#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node {
    long num;

    struct s_node *next;
} t_node;

// core functions
t_node *parse_args(int argc, char *argv[]);
void handle_error(void);
int	handle_atoi(const char *str);

// stack_utils
t_node  *create_node(int n);
void	add_back(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	free_stack(t_node **lst);
int     check_sorted(t_node *lst);
int     lstsize(t_node *lst);
void	remove_back(t_node *lst, t_node *last);
int     find_index(t_node *head, int num);
int     find_target_index_a(t_node *head, int num);
int     find_target_index_b(t_node *head, int num);
int     stack_max(t_node *head);
int     stack_min(t_node *head);

// operations
void    sa(t_node **a, int print);
void    sb(t_node **b, int print);
void    ss(t_node **a, t_node **b, int print);
void    pa(t_node **a, t_node **b, int print);
void    pb(t_node **a, t_node **b, int print);
void    ra(t_node **a, int print);
void    rb(t_node **b, int print);
void    rr(t_node **a, t_node **b, int print);
void    rra(t_node **a, int print);
void    rrb(t_node **b, int print);
void    rrr(t_node **a, t_node **b, int print);

// sort functions
void    sort(t_node **a);
void    push_sort_a(t_node **a, t_node **b);
void    push_sort_b(t_node **a, t_node **b);
void    sort_b_step(t_node **a, t_node **b);
void    sort_three(t_node **a);

// cost functions
int calculate_cost(t_node *a, t_node *b);
int calculate_cost_ba(t_node *a, t_node *b);

int cost_rrarrb(t_node *a, t_node *b, int num);
int cost_rrarb(t_node *a, t_node *b, int num);
int cost_rarrb(t_node *a, t_node *b, int num);
int cost_rarb(t_node *a, t_node *b, int num);

int cost_rrarrb_ba(t_node *a, t_node *b, int num);
int cost_rrarb_ba(t_node *a, t_node *b, int num);
int cost_rarrb_ba(t_node *a, t_node *b, int num);
int cost_rarb_ba(t_node *a, t_node *b, int num);


// apply functions
void apply_rotate(t_node **a, t_node **b, int cost, char stack);
void apply_rotate_a(t_node **a, t_node **b, int cost, char stack);
void apply_rotate_b(t_node **a, t_node **b, int cost, char stack);
int apply_rrarrb(t_node **a, t_node **b, int num, char stack);
int apply_rrarb(t_node **a, t_node **b, int num, char stack);
int apply_rarrb(t_node **a, t_node **b, int num, char stack);
int apply_rarb(t_node **a, t_node **b, int num, char stack);
void final_rotate(t_node **a);


// testing
#include <stdio.h>
void print_stack(t_node *lst);

#endif


// int	ft_find_place_b(t_stack *stack_b, int nbr_push)
// {
// 	int		i;
// 	t_stack	*tmp;

// 	i = 1;
// 	if (nbr_push > stack_b->nbr && nbr_push < ft_lstlast(stack_b)->nbr)
// 		i = 0;
// 	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
// 		i = ft_find_index(stack_b, ft_max(stack_b));
// 	else
// 	{
// 		tmp = stack_b->next;
// 		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
// 		{
// 			stack_b = stack_b->next;
// 			tmp = stack_b->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }