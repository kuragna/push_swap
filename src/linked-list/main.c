#include "push_swap.h"

void	print_op(int flag);

void	find_leaks()
{
	system("leaks -q push_swap");
}

int	get_key(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack->value);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i += 1;
	}
	return (i);
}

void	test(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	idx;
	int	mid;

	while (size > 3)
	{
		mid = size / 2;
		idx = get_pos(*stack_a, find_smallest(*stack_a));
		if (idx == 1)
			swap(*stack_a, SA);
		else if (idx <= mid)
			rotate_by_number(rotate, stack_a, RA, idx);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - idx);
		push(stack_b, pop(stack_a), PB);
		size--;
	}

	small_stack(stack_a);

	long value = 1;
	while (value != STACK_EMPTY)
	{
		value = pop(stack_b);
		push(stack_a, value, PA);
	}
}

int main(int argc, char **argv)
{
	int	size = 0;
	(void)argc;
	t_stack *stack_a = NULL;
// 	t_stack *stack_b = NULL;

	parsing(&stack_a, argv + 1, &size);
// 	test(&stack_a, &stack_b, size);
// 	if (size != 0 && !issorted(stack_a))
// 		test(&stack_a, &stack_b, size);
// 	stack_clear(&stack_a);

	return 0;
}

// 1 - divide size by 2
// 2 - find index of small number
// 3 - compare how many steps has to do to be on the top of stack A
// 4 - push top of stack A to stack B
