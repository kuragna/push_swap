#include "push_swap.h"

void	find_leaks()
{
	system("leaks -q push_swap");
}

int main(int argc, char **argv)
{
	atexit(find_leaks);

	int	size = 0;
	(void)argc;
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	add_numbers(&stack_a, argv + 1, &size);

	int	idx;
	int	mid;

	if (issorted(stack_a))
		exit(0);
	while (size > 3)
	{
		mid = size / 2;
		idx = get_pos(stack_a, find_smallest(stack_a));
		if (idx <= mid)
			rotate_by_number(rotate, &stack_a, RA, idx);
		if (idx > mid)
			rotate_by_number(reverse_rotate, &stack_a, RRA, size - idx);
		push(&stack_b, pop(&stack_a), PB);
		size--;
	}

	small_stack(&stack_a);
	long t = 1;
	while (t != STACK_EMPTY)
	{
		t = pop(&stack_b);
		push(&stack_a, t, PA);
	}
	return 0;
}

