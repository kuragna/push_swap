/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:53 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/11 13:44:34 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack, int flag)
{
	int		c;
	t_node	*head;

	if (stack->size <= 1)
		return ;
	head = stack->head;
	c = head->value;
	head->value = head->next->value;
	head->next->value = c;
	print_move(flag);
}

void	rotate(t_stack **stack, int flag)
{
	t_node	*tmp;

	if ((*stack)->size < 3)
		return ;
	tmp = (*stack)->head;
	(*stack)->head = tmp->next;
	(*stack)->head->prev = NULL;
	tmp->next = NULL;
	(*stack)->tail->next = tmp;
	tmp->prev = (*stack)->tail;
	(*stack)->tail = tmp;
	print_move(flag);
}

void	reverse_rotate(t_stack **stack, int flag)
{
	t_node	*tmp;

	if ((*stack)->size < 3)
		return ;
	tmp = (*stack)->tail;
	(*stack)->tail = tmp->prev;
	(*stack)->tail->next = NULL;
	tmp->prev = NULL;
	(*stack)->head->prev = tmp;
	tmp->next = (*stack)->head;
	(*stack)->head = tmp;
	print_move(flag);
}

void	rotate_by_number(t_fp p, t_stack **stack, int flag, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		p(stack, flag);
}
