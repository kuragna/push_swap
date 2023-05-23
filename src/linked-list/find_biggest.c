/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:41:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 19:52:48 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest(t__list *list)
{
	int	first;

	first = list->value;
	while (list)
	{
		if (list->value > first)
			first = list->value;
		list = list->next;
	}
	return (first);
}
