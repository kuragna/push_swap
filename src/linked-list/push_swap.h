#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

#define WRITE(str) write(1, str, ft_strlen(str))
#define STACK_A() print_stack(stack_a, 'a')
#define STACK_B() print_stack(stack_b, 'b')
#define STACK_EMPTY 2147483648
#define PRINT(n) printf("%d\n", n)

/*-------- swap --------*/
#define SA() swap(stack_a, SA)
#define SB() swap(stack_b, SB)

/*-------- push --------*/
#define PA() push(&stack_a, pop(&stack_b), PA)
#define PB() push(&stack_b, pop(&stack_a), PB)

/*-------- rotate --------*/
#define RA() rotate(&stack_a, RA)
#define RB() rotate(&stack_b, RB)

/*-------- reverse rotate --------*/
#define RRA() reverse_rotate(&stack_a, RRA)
#define RRB() reverse_rotate(&stack_b, RRB)


enum e_ops
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};


typedef struct s_stack
{
	// position of node
	int	value;
	int	size;
	struct s_stack *next;
}	t_stack;

typedef void (*fp)(t_stack **, int);

/*-------- initialize stack --------*/
t_stack	*add_node(int value);
void	insert(t_stack **stack, t_stack *node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
/*-------- initialize stack --------*/

/*-------- errors --------*/
void	print_err(t_stack **stack, char **ptr);
int		check_dup(t_stack *stack, long value);
int		check_(char *str);
/*-------- errors --------*/

/*-------- opertations --------*/
void	swap(t_stack *stack, int flag);
void	swap_both(t_stack *a, t_stack *b, int flag);
void	rotate(t_stack **stack, int flag);
void	reverse_rotate(t_stack **stack, int flag);
long	pop(t_stack **stack);
void	push(t_stack **stack, long value, int flag);
void	rotate_by_number(fp p, t_stack **stack, int flag, int size);
/*-------- opertations --------*/


int		issorted(t_stack *stack);
void	add_numbers(t_stack **stack, char **argv, int *size);
void	print_stack(t_stack *stack, char c);
void	small_stack(t_stack **stack);


/*-------- find --------*/
int		get_pos(t_stack *stack, int value);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
/*-------- find --------*/

#endif
