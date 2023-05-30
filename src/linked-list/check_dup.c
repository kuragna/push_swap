/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:57:22 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/30 18:53:20 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t__list *list, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	while (list)
	{
		if (list->value == value)
			return (0);
		list = list->next;
	}
	return (1);
}
