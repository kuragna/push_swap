/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:34:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 19:48:13 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_stack(t_stack **stack)
{
	int	nu[3];

	nu[0] = (*stack)->list->value;
	nu[1] = (*stack)->list->next->value;
	nu[2] = (*stack)->list->next->next->value;
	if (issorted((*stack)->list))
		return ;
	else if (nu[2] > nu[0] && nu[1] < nu[2])
		swap(*stack, SA);
	else if (nu[0] > nu[1] && nu[1] > nu[2])
	{
		swap(*stack, SA);
		reverse_rotate(stack, RRA);
	}
	else if (nu[0] > nu[2] && nu[2] > nu[1])
		rotate(stack, RA);
	else if (nu[2] > nu[0] && nu[0] < nu[1])
	{
		swap(*stack, SA);
		rotate(stack, RA);
	}
	else if (nu[0] < nu[1] && nu[0] > nu[2])
		reverse_rotate(stack, RRA);
}
