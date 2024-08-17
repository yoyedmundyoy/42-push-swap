#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node {
    long num;
    long idx;

    struct s_node *prev;
    struct s_node *next;
} t_node;

t_node *parse_args(int argc, char *argv[]);
void handle_error(void);
t_node *create_node(int n);
void	add_back(t_node **lst, t_node *new);
t_node	*lstlast(t_node *lst);
void	free_stack(t_node **lst);

#endif