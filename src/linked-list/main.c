#include "push_swap.h"

void	find_leaks()
{
	system("leaks -q push_swap");
}
/* --- use PRINT for printing int --- */
/*check for INT_MAX and INT_MIN*/

//void	four(t_stack *stack_a, t_stack *stack_b)
//{
//	int	b = find_biggest(stack_a);
//
//	if (stack_a->value > stack_a->next->value)
//		SA();
//	if (stack_a->value + 1 == b)
//		RA();
//	PB();
//	small_stack(stack_a);
//	PA();
//	if (stack_a->value == b)
//		RA();
//	if (stack_a->value > stack_a->next->value)
//		SA();
//}
int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int main(int argc, char **argv)
{
	atexit(find_leaks);
	(void)argc;
	t_stack *stack_a;
	//t_stack *stack_b = NULL;
	add_numbers(&stack_a, argv + 1);
	STACK_A();
	//stack_clear(&stack_a);
#if 0
	if (check_sorted(stack_a) == 1)
		exit(EXIT_SUCCESS);
	if (check.size > 1)
		check_sorted(stack_a);
	if (check.size == 2)
		swap(stack_a, SA);
	//print_lst(stack_a);
	//stack_clear(&stack_a);
#endif
	return 0;
}
// 3 1 2
// case1: 2 1 3 --> OK
// case2: 3 2 1 --> OK
// case3: 3 1 2 --> OK
// case4: 1 3 2 --> OK
// case5: 2 3 1 --> OK


/*
[3 4 2 1 5]
[3 4 1 5 2]
[4 3 5 1 2]
[4 5 1 2 3]
[3 2 4 5 1]
[2 4 1 5 3]
[5 1 4 3 2]
[5 2 3 4 1]
[1 3 4 5 2]
[2 5 1 4 3]
[2 5 1 3 4]
[3 1 4 5 2]
*/





