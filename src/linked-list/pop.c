/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:00:44 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 20:01:37 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	pop(t_stack **stack)
{
	long	value;
	t_stack	*tmp;

	if (*stack == NULL)
		return (STACK_EMPTY);
	value = (*stack)->value;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (value);
}
