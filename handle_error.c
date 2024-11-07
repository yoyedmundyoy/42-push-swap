#include "push_swap.h"

void handle_error(void)
{
    write(STDERR_FILENO, "Error\n", 6);
    exit(1);
}