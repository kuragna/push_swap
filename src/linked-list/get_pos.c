/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:38 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 19:51:49 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: use index inside the node

int	get_pos(t__list *list, int value)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->value == value)
			return (i);
		i++;
		list = list->next;
	}
	return (-1);
}
