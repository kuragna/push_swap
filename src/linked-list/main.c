#include "push_swap.h"

void	print_op(int flag);



void	find_leaks()
{
	system("leaks -q push_swap");
}


void	test(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	idx;
	int	mid;

	size = (*stack_a)->size;
	while (size > 3)
	{
		mid = size / 2;
		idx = get_pos((*stack_a)->list, find_smallest((*stack_a)->list));
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
#if 0

void	move(t_stack **stack_a, t_stack **stack_b, int size, int key)
{
	while (size)
	{
		if ((*stack_a)->value <= key)
			push(stack_b, pop(stack_a), PB);
		else
			rotate(stack_a, RA);
		size--;
	}
}

void	steps(t_stack **stack_a, t_stack **stack_b, int size)
{
	while (size)
	{
		int	mid = size / 2;
		int	idx = get_pos(*stack_b, find_biggest(*stack_b));
		if (idx <= mid)
			rotate_by_number(rotate, stack_b, RB, idx);
		else
			rotate_by_number(reverse_rotate, stack_b, RRB, size - idx);
		push(stack_a, pop(stack_b), PA);
		size--;
	}
}


void	same(t_stack **stack_a, t_stack **stack_b, int size)
{

	while (size)
	{
		int	mid = size / 2;
		int	idx = get_pos(*stack_a, find_biggest(*stack_a));
		if (idx <= mid)
			rotate_by_number(rotate, stack_a, RA, idx);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - idx);
		push(stack_b, pop(stack_a), PB);
		size--;
	}
}
#endif

// first: 100 moves
// second: 75 moves
// third: 50 moves
// last: 25 move


t_stack *create_stack()
{
	t_stack *stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	ft_memset(stack, 0, sizeof(*stack));
	return (stack);
}

int main(int argc, char **argv)
{
	(void)argc;
	t_stack *stack_a = create_stack();
	t_stack *stack_b = create_stack();

	parsing(&stack_a, argv + 1);
	test(&stack_a, &stack_b);
	return 0;
}
