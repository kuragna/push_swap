#include "../include/push_swap.h"

int	small_number(t_stack *stack_a, int prev)
{
	int	min;

	min = stack_a->value;
	while (stack_a != NULL)
	{
		if ((min != prev )&& (min > stack_a->value))
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}
/* void	delete_node(t_stack **stack_a, int value)
{
	t_stack *tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->value == value)
			break;
		tmp = tmp->next;
	}
	(*stack_a)->next = tmp->next;
	free(tmp);
} */

int main()
{
	int	prev;
	t_stack *a = NULL;
	t_stack *b = NULL;

	insert(&a, add_node(2));
	insert(&a, add_node(3));

	printf("------------- before ---------------\n");
	print_lst(a);
	small_number(a, &prev);
	printf("------------- after  ---------------\n");
	print_lst(a);
	return 0;
}

// a = 3 2 1 4
// b = 1
