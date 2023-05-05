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
#define SWAP_A(stack) swap(stack, SA)
#define SWAP_B(stack) swap(stack, SB)

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

typedef struct s_check
{
	int		size;
	int		sorted;
	char	**args;
}	t_check;

int		ft_isnumber(char *str);
t_stack	*add_node(int value);
void	insert(t_stack **stack, t_stack *node);
void	check_number(char **str);
void	check_dup(t_stack *stack, int value);
int		issorted(t_stack *stack);
void	add_numbers(t_stack **stack, t_check *check);
void	stack_clear(t_stack **stack);
void	print_err(void);
void	print_stack(t_stack *stack, char c);
void	small_stack(t_stack *stack);
void	swap(t_stack *stack, int flag);
void	rotate(t_stack *stack, int flag);
void	reverse_rotate(t_stack *stack, int flag);
long	pop(t_stack **stack);
void	push(t_stack **stack, long value, int flag);
int		stack_size(t_stack *stack);
#endif
