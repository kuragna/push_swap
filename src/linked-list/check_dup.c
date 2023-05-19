/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:57:22 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 19:57:24 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *head, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	while (head)
	{
		if (head->value == value)
			return (0);
		head = head->next;
	}
	return (1);
}
