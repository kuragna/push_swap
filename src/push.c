/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:08:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 18:52:12 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_back(t_stack **stack, int value)
{
	t_node	*node;

	node = create_node(value);
	if ((*stack)->head == NULL && (*stack)->size == 0)
	{
		(*stack)->head = node;
		(*stack)->tail = node;
	}
	else
	{
		(*stack)->tail->next = node;
		node->prev = (*stack)->tail;
		(*stack)->tail = node;
	}
	(*stack)->size += 1;
}

void	push_front(t_stack **stack, long value, int flag)
{
	t_node	*node;

	node = create_node(value);
	if (value == STACK_EMPTY || node == NULL)
		return ;
	if ((*stack)->head == NULL && (*stack)->size == 0)
	{
		(*stack)->head = node;
		(*stack)->tail = node;
	}
	else
	{
		(*stack)->head->prev = node;
		node->next = (*stack)->head;
		(*stack)->head = node;
	}
	(*stack)->size += 1;
	print_move(flag);
}

long	pop(t_stack **stack)
{
	t_node	*tmp;
	long	value;

	if ((*stack)->size == 0 || (*stack)->head == NULL)
		return (STACK_EMPTY);
	value = (*stack)->head->value;
	tmp = (*stack)->head;
	if ((*stack)->size == 1)
	{
		(*stack)->head = NULL;
		(*stack)->tail = NULL;
	}
	else
	{
		(*stack)->head = (*stack)->head->next;
		(*stack)->head->prev = NULL;
		tmp->next = NULL;
	}
	free(tmp);
	(*stack)->size -= 1;
	return (value);
}
