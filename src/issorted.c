/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:35:52 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 16:07:08 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 means not sorted
// 1 means sorted
int	issorted(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp2 = head;
	while (tmp2->next)
	{
		tmp = tmp2->next;
		if (tmp2->value > tmp->value)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}