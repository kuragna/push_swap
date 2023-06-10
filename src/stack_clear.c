/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:25:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 19:54:38 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_clear(t_stack **stack_a)
{
	while ((*stack_a)->size)
	{
		pop(stack_a);
	}
	free(*stack_a);
	*stack_a = NULL;
}
