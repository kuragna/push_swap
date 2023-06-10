/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:55:14 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 16:51:48 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * 0 means found non-integer
 * 1 means argmunet clean
 */
int	check_number(char *str)
{
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (ft_isdigit(*(str - 1)) && ft_isdigit(*(str + 1)))
				return (1);
			str++;
		}
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}
