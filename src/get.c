/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:20:29 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 20:02:39 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_pos(t_stack *stack, int target)
{
	t_node	*tmp[2];
	int		temp[3];

	temp[0] = stack->size / 2;
	temp[1] = 0;
	temp[2] = stack->size - 1;
	tmp[0] = stack->head;
	tmp[1] = stack->tail;
	while (temp[0]-- >= 0)
	{
		if (tmp[0]->value == target)
			return (temp[1]);
		if (tmp[1]->value == target)
			return (temp[2]);
		tmp[0] = tmp[0]->next;
		tmp[1] = tmp[1]->prev;
		temp[1]++;
		temp[2]--;
	}
	return (-1);
}

int	get_max(t_stack *stack)
{
	t_node	*tmp[2];
	int		mid;
	int		max[2];

	mid = stack->size / 2;
	tmp[0] = stack->head;
	tmp[1] = stack->tail;
	max[0] = tmp[0]->value;
	max[1] = tmp[1]->value;
	while (mid-- >= 0)
	{
		if (max[0] < tmp[0]->value)
			max[0] = tmp[0]->value;
		if (max[1] < tmp[1]->value)
			max[1] = tmp[1]->value;
		tmp[0] = tmp[0]->next;
		tmp[1] = tmp[1]->prev;
	}
	if (max[0] > max[1])
		return (max[0]);
	return (max[1]);
}

int	get_min(t_stack *stack)
{
	t_node	*tmp[2];	
	int		mid;
	int		min[2];

	mid = stack->size / 2;
	tmp[0] = stack->head;
	tmp[1] = stack->tail;
	min[0] = tmp[0]->value;
	min[1] = tmp[1]->value;
	while (mid-- >= 0)
	{
		if (min[0] > tmp[0]->value)
			min[0] = tmp[0]->value;
		if (min[1] > tmp[1]->value)
			min[1] = tmp[1]->value;
		tmp[0] = tmp[0]->next;
		tmp[1] = tmp[1]->prev;
	}
	if (min[0] < min[1])
		return (min[0]);
	return (min[1]);
}
