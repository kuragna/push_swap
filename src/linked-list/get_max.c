/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:25:48 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/26 18:10:45 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	get_max(t__list *list)
{
	int	max;

	max = list->value;
	while (list)
	{
		if (list->value > max)
			max = list->value;
		list = list->next;
	}
	return (max);
}
