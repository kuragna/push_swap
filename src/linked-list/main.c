#include "push_swap.h"

void	find_leaks()
{
	system("leaks -q push_swap");
}
/* --- use PRINT for printing int --- */
/*check for INT_MAX and INT_MIN*/

void	test(t_stack *stack_a, t_stack *stack_b)
{
	int	b = find_biggest(stack_a);

	if (stack_a->value > stack_a->next->value)
		SA(stack_a);
	if (stack_a->value + 1 == b)
		rotate(stack_a, RA);
	PB(stack_b);
	small_stack(stack_a);
	PA(stack_a);
	if (stack_a->value == b)
		rotate(stack_a, RA);
	if (stack_a->value > stack_a->next->value)
		SA(stack_a);
}
int main(int argc, char **argv)
{
	(void)argc;
	t_stack *stack_a;
	t_stack *stack_b = NULL;

	
	add_numbers(&stack_a, argv + 1);
	test(stack_a, stack_b);
	STACK_A(stack_a);
#if 0	
[4 3 1 2] pb ra pa ra
[1 2 3 4] pb rra pa
[2 1 4 3] pb sa ra sa
[1 3 4 2] pb rra pa
#endif
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


