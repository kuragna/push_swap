/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:28:16 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/30 19:27:45 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack()
{
	t_stack *stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	ft_memset(stack, 0, sizeof(*stack));
	return (stack);
}
