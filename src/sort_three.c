/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:34:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 20:01:12 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack **stack)
{
	int	nu[3];

	nu[0] = (*stack)->head->value;
	nu[1] = (*stack)->head->next->value;
	nu[2] = (*stack)->tail->value;
	if (issorted((*stack)->head))
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
