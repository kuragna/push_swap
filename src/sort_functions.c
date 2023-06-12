/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:23:34 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/10 14:56:51 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	select_number(t_stack *stack, int *ptr, int low, int high)
{
	int		mid;
	t_node	*tmp;

	mid = stack->size / 2;
	tmp = stack->head;
	while (mid--)
	{
		if (tmp->value >= low && tmp->value <= high)
			break ;
		tmp = tmp->next;
	}
	ptr[0] = get_pos(stack, tmp->value);
	mid = stack->size;
	tmp = stack->tail;
	while (mid--)
	{
		if (tmp->value >= low && tmp->value <= high)
			break ;
		tmp = tmp->prev;
	}
	ptr[1] = ft_abs(stack->size - get_pos(stack, tmp->value));
}

static void	push2a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	mid;
	int	pos;
	int	max;

	size = (*stack_b)->size;
	while (size)
	{
		mid = size / 2;
		max = get_max(*stack_b);
		pos = get_pos(*stack_b, max);
		if (pos == 1)
			swap(*stack_b, SB);
		else if (pos <= mid)
			rotate_by_number(rotate, stack_b, RB, pos);
		else
			rotate_by_number(reverse_rotate, stack_b, RRB, size - pos);
		push_front(stack_a, pop(stack_b), PA);
		size--;
	}
}

static void	push2b(t_stack **stack_a, t_stack **stack_b, int *keys, int size)
{
	int	two[2];
	int	sz;

	sz = size;
	while (sz-- && (*stack_a)->size != 0)
	{
		select_number(*stack_a, two, 1, keys[0]);
		if (two[0] == 1)
			swap(*stack_a, SA);
		else if (two[0] <= two[1])
			rotate_by_number(rotate, stack_a, RA, two[0]);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, two[1]);
		push_front(stack_b, pop(stack_a), PB);
		if ((*stack_b)->head->value < keys[0] - keys[1])
		{
			if ((*stack_b)->size == 2)
				swap(*stack_b, SB);
			rotate(stack_b, RB);
		}
	}
	keys[0] += size;
	if ((*stack_a)->size != 0)
		push2b(stack_a, stack_b, keys, size);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int ch)
{
	int	keys[2];
	int	size;

	keys[0] = (*stack_a)->size / ch;
	keys[1] = keys[0] / 2;
	size = keys[0];
	set_index(stack_a);
	push2b(stack_a, stack_b, keys, size);
	push2a(stack_a, stack_b);
	free(*stack_b);
}
