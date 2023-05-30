#include "push_swap.h"
#include <math.h>

void	print_op(int flag);

void	find_leaks()
{
	system("leaks -q push_swap");
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return n;
}

int	get_mid(t__list *list, int min, int max)
{
	int	value;

	while (list)
	{
		value = list->value;
		if (ft_abs(min - value) == ft_abs(max - value))
			return (value);
		list = list->next;
	}
	return (-1);
}



void	to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size = (*stack_b)->size;

	while (size)
	{
		int	mid = size / 2;
		int	idx = get_pos((*stack_b)->list, get_max((*stack_b)->list));

		if (idx == 1)
			swap(*stack_b, SB);
		else if (idx <= mid)
			rotate_by_number(rotate, stack_b, RB, idx);
		else
			rotate_by_number(reverse_rotate, stack_b, RRB, size - idx);
		push(stack_a, pop(stack_b), PA);
		size--;
	}

}

void	to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size = (*stack_a)->size;

	while (size)
	{
		int	mid = size / 2;
		int	idx = get_pos((*stack_a)->list, get_min((*stack_a)->list));
		if (idx == 1)
			swap(*stack_a, SA);
		else if (idx < mid)
			rotate_by_number(rotate, stack_a, RA, idx);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - idx);
		push(stack_b, pop(stack_a), PB);
		size--;
	}
}


int	find_by_index(t__list *list, int idx)
{
	int	i = -1;
	while (++i < idx)
		list = list->next;
	return (list->value);
}

int	get_last(t__list *list)
{
	while (list->next)
		list = list->next;
	return (list->value);
}

void	st(t_stack **stack_a, t_stack **stack_b, int key)
{
	int	size = (*stack_a)->size;

	while (size)
	{
		if ((*stack_a)->list->value <= key)
		{
			push(stack_b, pop(stack_a), PB);
			if ((*stack_b)->size >= 2 && (*stack_b)->list->value < key - 13)
				rotate(stack_b, RB);
		}
		else
			rotate(stack_a, RA);
		size--;
	}
}


int	main(int argc, char **argv)
{
	(void)argc;
	t_stack *stack_a = create_stack();

	parsing(&stack_a, argv + 1);
// 	set_index(&stack_a->list, 1);
	return 0;
}

