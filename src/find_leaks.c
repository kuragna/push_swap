/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_leaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:42:51 by aabourri          #+#    #+#             */
/*   Updated: 2023/05/19 19:43:08 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_leaks(void)
{
	system("leaks -q push_swap");
}