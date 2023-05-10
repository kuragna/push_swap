#include "push_swap.h"

void    print_err(t_stack **stack, char **ptr)
{
	stack_clear(stack);
	WRITE("Error\n");
	ft_free(ptr);
    exit(EXIT_FAILURE);
}
