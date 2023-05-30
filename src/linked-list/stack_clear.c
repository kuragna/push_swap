/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:25:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/25 15:10:57 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_clear(t_stack **stack)
{
	t__list *tmp;

	while ((*stack)->list)
	{
		tmp = (*stack)->list;
		(*stack)->list = (*stack)->list->next;
		free(tmp);
	}
	free(*stack);
}
