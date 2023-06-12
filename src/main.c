/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:19:50 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/11 13:43:59 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_move(int flag)
{
	const char	*ops[8] = {
		"sa\n",
		"sb\n",
		"pa\n",
		"pb\n",
		"ra\n",
		"rb\n",
		"rra\n",
		"rrb\n",
	};

	ft_putstr_fd((char *)ops[flag], 1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	mid;
	int	pos;
	int	size;
	int	size_b;

	size_b = 0;
	size = (*stack_a)->size;
	while (size > 3)
	{
		mid = size / 2;
		pos = get_pos(*stack_a, get_min(*stack_a));
		if (pos <= mid)
			rotate_by_number(rotate, stack_a, RA, pos);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - pos);
		push_front(stack_b, pop(stack_a), PB);
		size--;
		size_b = (*stack_b)->size;
	}
	sort_three(stack_a);
	while (size_b--)
		push_front(stack_a, pop(stack_b), PA);
	if ((*stack_a)->size != 3)
		free(*stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = create_stack();
	parsing(&stack_a, argv + 1);
	if (issorted(stack_a->head))
	{
		stack_clear(&stack_a);
		return (0);
	}
	if (stack_a->size == 2)
		swap(stack_a, SA);
	if (stack_a->size > 3)
		stack_b = create_stack();
	if (stack_a->size == 100)
		push_swap(&stack_a, &stack_b, 4);
	else if (stack_a->size == 500)
		push_swap(&stack_a, &stack_b, 11);
	else
		sort_five(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}
