/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:40:29 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/30 17:51:58 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_stack **stack, t__list *node)
{
	t__list	*tmp;

	if ((*stack)->list  == NULL)
		(*stack)->list = node;
	else
	{
		tmp = (*stack)->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	(*stack)->size += 1;
}
