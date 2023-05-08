#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	first;

	first = stack->value;
	while (stack)
	{
		if (stack->value > first)
			first = stack->value;
		stack = stack->next;
	}
	return (first);
}
