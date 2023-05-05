#include "../include/push_swap.h"

void	print_lst(t_stack *head)
{
	while (head != NULL)
	{
		printf("%d\n", head->value);
		head = head->next;
	}
}
