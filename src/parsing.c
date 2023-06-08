/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:39:34 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 19:00:52 by aabourri         ###   ########.fr       */
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
		if (!nums)
			return ;
		while (nums && nums[++i])
		{
			if (check_number(nums[i]))
				print_err(stack, nums);
			value = ft_atol(nums[i]);
			if (check_dup((*stack)->head, value))
				print_err(stack, nums);
			push_back(stack, value);
		}
		ft_free(nums);
		argv++;
	}
}
