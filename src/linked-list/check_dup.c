#include "push_swap.h"

int	check_dup(t_stack *head, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	while (head)
	{
		if (head->value == value)
			return (0);
		head = head->next;
	}
	return (1);
}
