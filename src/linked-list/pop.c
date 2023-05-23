/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 20:00:44 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 20:12:53 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	pop(t_stack **stack)
{
	t__list *tmp;
	long value;

	if ((*stack)->list == NULL)
		return (STACK_EMPTY);
	tmp = (*stack)->list;
	value = tmp->value;
	(*stack)->list = tmp->next;
	free(tmp);
	(*stack)->size -= 1;
	return (value);
}
