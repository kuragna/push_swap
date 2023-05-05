#include "push_swap.h"

void	insert(t_stack **stack, t_stack *node)
{
	t_stack *tmp;

	if (*stack == NULL)
		*stack = node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;	
	}
}
