#include "push_swap.h"


void	print_op(int flag)
{
	if (flag < 0)
		return ;
	const char *ops[8] = {"sa\n", "sb\n", "pa\n", "pb\n", "ra\n", "rb\n", "rra\n", "rrb\n"};
	ft_putstr_fd((char*)ops[flag], 1);
}


void	print_stack(t__list *list, char c)
{
	printf("----- stack %c -----\n", c);
	for (; list; )
	{
		printf("%d\n", list->value);
		list = list->next;
	}
	printf("----- stack %c -----\n", c);
}

/**
 * Swap the first 2 elements at the top of stack.
 * Do nothing if there is only one or no elements
 * ss, sa and sb
 */

void	swap(t_stack *stack, int flag)
{
	int	c;
	t__list *list;

	if (stack->size < 2)
		return ;
	list = stack->list;
	c = list->value;
	list->value = list->next->value;
	list->next->value = c;
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
	t__list	*first;
	t__list	*last;

	if ((*stack)->size < 3)
		return ;
	first = (*stack)->list;
	last = (*stack)->list;
	while (last->next)
		last = last->next;
	(*stack)->list = first->next;
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
	t__list	*t;
	t__list *tmp;

	if ((*stack)->size < 3)
		return ;
	t = (*stack)->list;
	tmp = (*stack)->list;
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
	t__list *tmp;

	if (value == STACK_EMPTY)
		return ;
	else if ((*stack)->list == NULL)
		(*stack)->list = create_node(value);
	else
	{
		tmp = (*stack)->list;
		(*stack)->list = create_node(value);
		(*stack)->list->next = tmp;
	}
	if (flag != -1)
		(*stack)->size += 1;
	print_op(flag);
}

