/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:57:22 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 14:11:03 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_dup(t_node *head, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}
