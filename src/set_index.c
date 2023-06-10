/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:57:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 17:11:27 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_index(t_stack **stack)
{
	t_node	*head;
	t_node	*tmp;

	head = (*stack)->head;
	while (head)
	{
		head->index = 1;
		tmp = (*stack)->head;
		while (tmp)
		{
			if (head->value > tmp->value)
				head->index += 1;
			tmp = tmp->next;
		}
		head = head->next;
	}
	head = (*stack)->head;
	while (head)
	{
		head->value = head->index;
		head = head->next;
	}
}
