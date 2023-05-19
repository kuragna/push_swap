/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:34 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 20:02:56 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_stack **stack, char **argv, int *size)
{
	int		i;
	long	value;
	char	**nums;

	while (*argv)
	{
		i = -1;
		nums = ft_split(*argv, ' ');
		while (nums[++i])
		{
			if (check_(nums[i]) == 0)
				print_err(stack, nums);
			value = ft_atol(nums[i]);
			if (check_dup(*stack, value) == 0)
				print_err(stack, nums);
			insert(stack, create_node(value));
			*size += 1;
		}
		ft_free(nums);
		argv++;
	}
}
