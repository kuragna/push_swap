#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

#define WRITE(str) write(1, str, ft_strlen(str))
#define STACK_A(a) print_stack(a, 'a')
#define STACK_B(b) print_stack(b, 'b')
#define STACK_EMPTY 2147483648
#define PRINT(n) printf("%d\n", n)
#define SA(stack) swap(stack, SA)
#define SB(stack) swap(stack, SB)
#define PA(a) push(&a, pop(&stack_b), PA)
#define PB(b) push(&b, pop(&stack_a), PB)

enum e_ops
{
	SA = 1,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
};


typedef struct s_stack
{
	// position of node
	int	value;
	struct s_stack *next;
}	t_stack;


/*-------- initialize stack --------*/
t_stack	*add_node(int value);
void	insert(t_stack **stack, t_stack *node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
/*-------- initialize stack --------*/

/*-------- errors --------*/
void	print_err(void);
void	check_dup(t_stack *stack, int value);
void	check_(char **argv);
/*-------- errors --------*/

/*-------- opertations --------*/
void	swap(t_stack *stack, int flag);
void	rotate(t_stack *stack, int flag);
void	reverse_rotate(t_stack *stack, int flag);
long	pop(t_stack **stack);
void	push(t_stack **stack, long value, int flag);
/*-------- opertations --------*/


int		issorted(t_stack *stack);
void	add_numbers(t_stack **stack, char **argv);
void	print_stack(t_stack *stack, char c);
void	small_stack(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);

#endif
