/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:25:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:57 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack **stack_a)
{
	t_node	*tmp;

	while ((*stack_a)->head)
	{
		tmp = (*stack_a)->head;
		(*stack_a)->head = (*stack_a)->head->next;
		free(tmp);
		tmp = NULL;
	}
	free(*stack_a);
	(*stack_a)->head = NULL;
	(*stack_a)->tail = NULL;
}
