#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
