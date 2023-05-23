/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:52 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 19:41:10 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 means not sorted
// 1 means sorted
int	issorted(t__list *list)
{
	t__list	*tmp;

	while (list->next)
	{
		tmp = list->next;
		if (list->value > tmp->value)
			return (0);
		list = list->next;
	}
	return (1);
}
