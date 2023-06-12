/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:55:14 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/11 13:41:36 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print_err(t_stack **stack, char **ptr)
{
	stack_clear(stack);
	write(2, "Error\n", 6);
	ft_free(ptr);
	exit(EXIT_FAILURE);
}

static int	check_dup(t_node *head, long value)
{
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (i != 0 && ft_isdigit(str[i - 1]) && ft_isdigit(str[i + 1]))
				return (1);
			i++;
		}
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	issorted(t_node *head)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp2 = head;
	while (tmp2 && tmp2->next)
	{
		tmp = tmp2->next;
		if (tmp2->value > tmp->value)
			return (0);
		tmp2 = tmp2->next;
	}
	return (1);
}

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
		while (nums[++i])
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
