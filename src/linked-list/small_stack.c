#include "push_swap.h"

void	small_stack(t_stack **stack)
{
	int	nu[3];

	nu[0] = (*stack)->value;
	nu[1] = (*stack)->next->value;
	nu[2] = (*stack)->next->next->value;

	if (nu[2] > nu[0] && nu[1] < nu[2])
		swap(*stack, SA);
	// case 2
	else if (nu[0] > nu[1] && nu[1] > nu[2])
	{
		swap(*stack, SA);
		reverse_rotate(stack, RRA);
	}
	// case 3
	else if (nu[0] > nu[2] && nu[2] > nu[1])
		rotate(stack, RA);
	// case 4
	else if (nu[2] > nu[0] && nu[0] < nu[1])
	{
		swap(*stack, SA);
		rotate(stack, RA);
	}
	// case 5
	else if (nu[0] < nu[1] && nu[0] > nu[2])
		reverse_rotate(stack, RRA);
}

/*
[3 4 2 1] -> ko
[3 4 1 2] -> ko
[4 3 1 2] -> ko
[4 1 2 3] -> ok
[3 2 4 1] -> ok
[2 4 1 3] -> ok
[1 4 3 2] -> ok
[2 3 4 1] -> ok
[1 3 4 2] -> ok
[2 1 4 3] -> ok
[2 1 3 4] -> ok
[3 1 4 2] -> ok
*/
