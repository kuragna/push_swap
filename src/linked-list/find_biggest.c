/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:41:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 19:41:54 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	first;

	first = stack->value;
	while (stack)
	{
		if (stack->value > first)
			first = stack->value;
		stack = stack->next;
	}
	return (first);
}
