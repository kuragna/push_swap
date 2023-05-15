#include "push_swap.h"

// TODO: use index inside the node

int	get_pos(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
