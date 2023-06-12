/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:49:03 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/12 18:19:23 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# ifndef STACK_EMPTY
#  define STACK_EMPTY 2147483648
# endif

enum e_flags
{
	SA = 0,
	SB = 1,
	PA = 2,
	PB = 3,
	RA = 4,
	RB = 5,
	RRA = 6,
	RRB = 7,
};

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

typedef void	t_fp(t_stack **, int);
t_stack	*create_stack(void);
t_node	*create_node(int value);
int		issorted(t_node *head);
int		get_pos(t_stack *stack, int target);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);

long	pop(t_stack **stack);

void	stack_clear(t_stack **stack_a);
void	push_back(t_stack **stack, int value);
void	swap(t_stack *stack, int flag);
void	rotate(t_stack **stack, int flag);
void	reverse_rotate(t_stack **stack, int flag);
void	push_front(t_stack **stack, long value, int flag);
void	rotate_by_number(t_fp p, t_stack **stack, int flag, int size);
void	parsing(t_stack **stack, char **argv);
void	sort_three(t_stack **stack);
void	set_index(t_stack **stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int ch);

int		ft_abs(int n);
void	print_move(int flag);
#endif
