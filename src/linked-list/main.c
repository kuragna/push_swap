#include "push_swap.h"

void	find_leaks()
{
	system("leaks -q push_swap");
}
/* --- use PRINT for printing int --- */
int main(int argc, char **argv)
{
	(void)argc;
	t_check check;
	t_stack *stack_a;
	t_stack *stack_b = NULL;

	check.size = 0;
	check.args = argv + 1;
	add_numbers(&stack_a, &check);
	STACK_A(stack_a);
	push(&stack_b, pop(&stack_a), PB);
	STACK_A(stack_a);
	STACK_B(stack_b);
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


// 1 2 3 4
// 2 3 4 1
// 3 4 1 2
// 4 1 2 3
// case1: [3 4 1] [2]
// 		: [1 3 4] [2]

// case2: [4 1 2] [3]
// 		: [1 2 4] [3]

// case3: [1 2 3] [4]


// [3 4 1] [1 [2] 3 4] [2]
// [4 1 2] [1 2 [3] 4] [3]
// [1 2 3] [1 2 3 [4]] [4]
