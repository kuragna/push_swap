#include "push_swap.h"


void	print_op(int flag)
{
	if (flag < 0)
		return ;
	const char *ops[8] = {"sa\n", "sb\n", "pa\n", "pb\n", "ra\n", "rb\n", "rra\n", "rrb\n"};
	ft_putstr_fd((char*)ops[flag], 1);
}


void	stack_tail(t_node *tail, char c)
{
	printf("----- stack %c [tail] -----\n", c);
	for (; tail; )
	{
		printf("%d\n", tail->value);
		tail = tail->prev;
	}
	printf("----- stack %c [tail] -----\n", c);
}

void	stack_head(t_node *head, char c)
{
	printf("----- stack %c [head] -----\n", c);
	for (; head; )
	{
		printf("%d\n", head->value);
		head = head->next;
	}
	printf("----- stack %c [head] -----\n", c);
}

