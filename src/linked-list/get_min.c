/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:26:24 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/30 18:26:30 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	get_min(t__list *list)
{
	int	min;

	min = list->value;
	while (list)
	{
		if (list->value < min)
			min = list->value;
		list = list->next;
	}
	return (min);
}
