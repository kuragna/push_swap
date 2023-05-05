#include "push_swap.h"

int stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i += 1;
	}
	return (i);
}
