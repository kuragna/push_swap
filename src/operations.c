/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:02:55 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/09 18:36:44 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	stack_tail(t_node *tail, char c)
{
	printf("----- stack %c [tail] -----\n", c);
	while (tail)
	{
		printf("%d\n", tail->value);
		tail = tail->prev;
	}
	printf("----- stack %c [tail] -----\n", c);
}

void	stack_head(t_node *head, char c)
{
	printf("----- stack %c [head] -----\n", c);
	while (head)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
	printf("----- stack %c [head] -----\n", c);
}
