/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:42:16 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 19:53:36 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t__list *list)
{
	int	first;

	first = list->value;
	while (list)
	{
		if (list->value < first)
			first = list->value;
		list = list->next;
	}
	return (first);
}
