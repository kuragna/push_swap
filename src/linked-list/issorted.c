/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:52 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 19:37:01 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 means not sorted
// 1 means sorted
int	issorted(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = stack->next;
		if (stack->value > tmp->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
