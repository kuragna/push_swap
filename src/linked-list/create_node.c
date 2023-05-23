/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:43:40 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 18:18:32 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t__list *create_node(int value)
{
	t__list *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}
