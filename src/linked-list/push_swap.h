#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

#define STACK_A() print_stack(stack_a->list, 'a')
#define STACK_B() print_stack(stack_b->list, 'b')
#define STACK_EMPTY 2147483648

enum e_ops
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
};

typedef struct s__list
{
	int	value;
	struct s__list *next;
} t__list;

typedef struct s_stack
{
	t__list *list;
	int	size;
} t_stack;

typedef void (*fp)(t_stack **, int);

/*-------- initialize stack --------*/
t__list *create_node(int value);
void	insert(t_stack **stack, t__list *node);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
/*-------- initialize stack --------*/

/*-------- errors --------*/
void	print_err(t_stack **stack, char **ptr);
int		check_dup(t__list *list, long value);
int		check(char *str);
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


int		issorted(t__list *list);
void	parsing(t_stack **stack, char **argv);
void	print_stack(t__list *list, char c);
void	small_stack(t_stack **stack);


/*-------- find --------*/
int		get_pos(t__list *list, int value);
int		find_biggest(t__list *list);
int		find_smallest(t__list *list);
/*-------- find --------*/

#endif
