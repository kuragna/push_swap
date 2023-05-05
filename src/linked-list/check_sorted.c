#include "push_swap.h"


// 0 means not sorted
// 1 means sorted
int	issorted(t_stack *stack)
{
	t_stack *tmp;

	while (stack->next)
	{
		tmp = stack->next;
		if (stack->value > tmp->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
