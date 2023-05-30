/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:38:11 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/30 18:46:15 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(t_stack **stack, char **ptr)
{
	stack_clear(stack);
	write(2, "Error\n", 6);
	ft_free(ptr);
	exit(EXIT_FAILURE);
}
