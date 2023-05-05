#include "push_swap.h"

void	check_dup(t_stack *head, int value)
{
	t_stack *tmp;

	tmp = head;
	if (value > INT_MAX || value < INT_MIN)
		print_err();
	while (tmp != NULL)
	{
		if (tmp->value == value)
			print_err();
		tmp = tmp->next;
	}
}
