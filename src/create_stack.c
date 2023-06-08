/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:28:16 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/07 15:31:38 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;
	size_t	size;

	size = sizeof(*stack);
	stack = malloc(size);
	if (!stack)
		return (NULL);
	ft_memset(stack, 0, size);
	return (stack);
}
