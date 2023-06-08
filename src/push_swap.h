/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:49:03 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/08 19:03:29 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

// #define STACK_A() stack_head(stack_a->head, 'a'); \
// 	stack_tail(stack_a->tail, 'a');
// #define STACK_B() stack_head(stack_b->head, 'b'); \
// 	stack_tail(stack_b->tail, 'b')

#define STACK_EMPTY 2147483648

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
typedef	struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef	struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;


typedef	void	(*fp)(t_stack **, int);
t_stack *create_stack(void);
t_node	*create_node(int value);
int		check_dup(t_node *head, long value);
int		check_number(char *str);
int		issorted(t_node *head);
int		get_pos(t_stack *stack, int target);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);

long	pop(t_stack **stack);

void	print_op(int flag);
void	stack_clear(t_stack **stack_a);
void	print_err(t_stack **stack, char **ptr);
void	push_front(t_stack **stack, long value, int flag);
void	push_back(t_stack **stack, int value);
void	swap(t_stack *stack, int flag);
void	rotate(t_stack **stack, int flag);
void	reverse_rotate(t_stack **stack, int flag);
void	push_front(t_stack **stack, long value, int flag);
void	rotate_by_number(fp p, t_stack **stack, int flag, int size);
void	parsing(t_stack **stack, char **argv);
void	stack_head(t_node *head, char c);
void	stack_tail(t_node *tail, char c);
void	small_stack(t_stack **stack);
void	set_index(t_stack **stack);
#endif
