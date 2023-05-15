#include "push_swap.h"


void	print_op(int flag)
{
	if (flag == PA)
		WRITE("pa\n");
	if (flag == PB)
		WRITE("pb\n");
	if (flag == SA)
		WRITE("sa\n");
	if (flag == SB)
		WRITE("sb\n");
	if (flag == SS)
		WRITE("ss\n");
	if (flag == RA)
		WRITE("ra\n");
	if (flag == RRA)
		WRITE("rra\n");
}

/**
 * Swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements
 * ss, sa and sb
 */

void	print_stack(t_stack *stack, char c)
{
	printf("----- stack %c -----\n", c);
	for (; stack; )
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
	printf("----- stack %c -----\n", c);
}

void	swap(t_stack *stack, int flag)
{
	int	c;

	c = stack->value;
	stack->value = stack->next->value;
	stack->next->value = c;
	print_op(flag);
}

/**
 * Shift up all elements of stack by 1. 
 * The first element becomes the last one.
 * rr, ra and rb
 */
// [2][p]->[1][p]->[3][p]->null
// [1][p]->[3][p]->[2][p]->null
void	rotate(t_stack **stack, int flag)
{
	t_stack *first;
	t_stack *last;

	first = *stack;
	last = *stack;

	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
	print_op(flag);
}
/**
 * Shift down all elements of stack by 1.
 * The last element becomes the first one
 * rrr, rra and rrb
 */
// [2][p]->[1][p]->[3][p]->null
// [3][p]->[2][p]->[1][p]->null

void	reverse_rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	t_stack *t;

	tmp = *stack;
	t = *stack;

	while (t->next->next)
		t = t->next;
	tmp = t->next;
	t->next = NULL;
	push(stack, tmp->value, -1);
	free(tmp);
	print_op(flag);
}

typedef void (*fp)(t_stack **, int);
void	rotate_by_number(fp p, t_stack **stack, int flag, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		p(stack, flag);
}

/**
 * Take the first element at the top of [a] and put it at the top of [b].
 * Do nothing if [a] is empty.
 */
/**
 * Take the first element at the top of [b] and put it at the top of [a].
 * Do nothing if [b] is empty.
 */

void	push(t_stack **stack, long value, int flag)
{
	t_stack *tmp;

	if (value == STACK_EMPTY)
		return ;
	if (*stack == NULL)
		*stack = add_node(value);
	else
	{
		tmp = *stack;
		*stack = add_node(value);
		(*stack)->next = tmp;
	}
	print_op(flag);
}


long	pop(t_stack **stack)
{
	long value;
	t_stack *tmp;

	if (*stack == NULL)
		return (STACK_EMPTY);
	value = (*stack)->value;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (value);
}
