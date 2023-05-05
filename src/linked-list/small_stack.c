#include "push_swap.h"

void	small_stack(t_stack *stack)
{
	int	nu[3];

	nu[0] = stack->value;
	nu[1] = stack->next->value;
	nu[2] = stack->next->next->value;

	if (issorted(stack))
		return ;
	if (nu[2] > nu[0] && nu[1] < nu[2])
		swap(stack, SA);
	// case 2
	else if (nu[0] > nu[1] && nu[1] > nu[2])
	{
		swap(stack, SA);
		reverse_rotate(stack, RRA);
	}
	// case 3
	else if (nu[0] > nu[2] && nu[2] > nu[1])
		rotate(stack, RA);
	// case 4
	else if (nu[2] > nu[0] && nu[0] < nu[1])
	{
		swap(stack, SA);
		rotate(stack, RA);
	}
	// case 5
	else if (nu[0] < nu[1] && nu[0] > nu[2])
		reverse_rotate(stack, RRA);
}
