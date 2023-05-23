/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:34 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/23 18:30:22 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_stack **stack, char **argv)
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
			if (check(nums[i]) == 0)
				print_err(stack, nums);
			value = ft_atol(nums[i]);
			if (check_dup((*stack)->list, value) == 0)
				print_err(stack, nums);
			insert(stack, create_node(value));
		}
		ft_free(nums);
		argv++;
	}
}
