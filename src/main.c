#include "push_swap.h"

void	print_op(int flag);
void	select_number(t_stack *stack, int *first, int *last, int low, int high);

void	find_leaks()
{
	system("leaks -q push_swap");
}


void	four_to_100(t_stack **stack_a, t_stack **stack_b)
{
	int	mid;
	int	pos;
	int	size;

	size = (*stack_a)->size;
	while (size > 3)
	{
		mid = size / 2;
		pos = get_pos(*stack_a, get_min(*stack_a));

		if (pos <= mid)
			rotate_by_number(rotate, stack_a, RA, pos);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - pos);
		size--;
		push_front(stack_b, pop(stack_a), PB);
	}
	small_stack(stack_a);
	while (*stack_b != NULL && (*stack_b)->size != 0)
		push_front(stack_a, pop(stack_b), PA);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	push2a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	mid;
	int	pos;
	int	max;

	size = (*stack_b)->size;
	while (size)
	{
		mid = size / 2;
		max = get_max(*stack_b);
		pos = get_pos(*stack_b, max);
		if (pos == 1)
			swap(*stack_b, SB);
		else if (pos <= mid)
			rotate_by_number(rotate, stack_b, RB, pos);
		else
			rotate_by_number(reverse_rotate, stack_b, RRB, size - pos);
		push_front(stack_a, pop(stack_b), PA);
		size--;
	}
}

#if 0
void	push_to(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	mid;
	int	pos;
	int	max;

	size = (*stack_a)->size;
	while (size > 3)
	{
		mid = size / 2;
		max = get_min(*stack_a);
		pos = get_pos(*stack_a, max);

		if (pos == 1)
			swap(*stack_a, SA);
		else if (pos <= mid)
			rotate_by_number(rotate, stack_a, RA, pos);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, size - pos);
		push_front(stack_b, pop(stack_a), PB);
		size--;
	}
	small_stack(stack_a);
}
#endif

void	select_number(t_stack *stack, int *first, int *last, int low, int high)
{
	int	mid;
	t_node *tmp;

	mid = stack->size / 2;
	tmp = stack->head;
	while (mid--)
	{
		if (tmp->value >= low && tmp->value <= high)
			break;
		tmp = tmp->next;
	}
	*first = get_pos(stack, tmp->value);
	mid = stack->size;
	tmp = stack->tail;
	while (mid--)
	{
		if (tmp->value >= low && tmp->value <= high)
			break;
		tmp = tmp->prev;
	}
	*last = ft_abs(stack->size - get_pos(stack, tmp->value));
}

void	push2b(t_stack **stack_a, t_stack **stack_b, int key, int mag, int size)
{
	int	first;
	int	last;
	int	sz;

	sz = size;
	while (sz-- && (*stack_a)->size != 0)
	{
		select_number(*stack_a, &first, &last, 1, key);
		if (first == 1)
			swap(*stack_a, SA);
		else if (first <= last)
			rotate_by_number(rotate, stack_a, RA, first);
		else
			rotate_by_number(reverse_rotate, stack_a, RRA, last);
		push_front(stack_b, pop(stack_a), PB);	
		if ((*stack_b)->head->value < key - mag)
		{
			if ((*stack_b)->size == 2)
				swap(*stack_b, SB);
			rotate(stack_b, RB);
		}
	}
	if ((*stack_a)->size != 0)
		push2b(stack_a, stack_b, key + size, mag, size);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int ch)
{
	int	key;
	int	mag;
	int	size;

	key = (*stack_a)->size / ch;
	mag = key / 2;
	size = key;
	push2b(stack_a, stack_b, key, mag, size);
	push2a(stack_a, stack_b);
}


void	set_index(t_stack **stack)
{
	t_node	*head;
	t_node	*tmp;

	head = (*stack)->head;
	while (head)
	{
		head->index = 1;
		tmp = (*stack)->head;
		while (tmp)
		{
			if (head->value > tmp->value)
				head->index += 1;
			tmp = tmp->next;
		}
		head = head->next;
	}
	head = (*stack)->head;
	while (head)
	{
		head->value = head->index;
		head = head->next;
	}
}

int	main2(int argc, char **argv)
{
	(void)argc;

	t_stack *stack = create_stack();

	parsing(&stack, argv + 1);
	set_index(&stack);

	t_node *head = stack->head;
	t_node *tail = stack->tail;

	printf("----- head -----\n");
	for (; head ;)
	{
		printf("value: %d | index: %d\n", head->value, head->index);
		head = head->next;
	}

	printf("\n----- tail -----\n");
	for (; tail; )
	{
		printf("value: %d | index: %d\n", tail->value, tail->index);
		tail = tail->prev;
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc <= 1)
		return 0;
	stack_a = create_stack();
	parsing(&stack_a, argv + 1);
	set_index(&stack_a);
	if (issorted(stack_a->head))
	{
		stack_clear(&stack_a);
		return 0;
	}
	if (stack_a->size == 2)
		swap(stack_a, SA);
	if (stack_a->size > 3)
		stack_b = create_stack();
	if (stack_a->size == 100)
		push_swap(&stack_a, &stack_b, 4);
	else if (stack_a->size == 500)
		push_swap(&stack_a, &stack_b, 11);
	else if (stack_a->size >= 3)
		four_to_100(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return 0;
}

