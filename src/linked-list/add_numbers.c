#include "push_swap.h"

void	add_numbers(t_stack **stack, t_check *check)
{
	int			i;
	long	value;
	char	**args;	

	check_number(check->args);
	while (*check->args != NULL)
	{
		i = -1;
		args = ft_split(*check->args, ' ');
		while (args[++i] != NULL)
		{
			value = ft_atol(args[i]);
			check_dup(*stack, value);
			check->size += 1;
			insert(stack, add_node((int)value));
		}
		ft_free(args);
		check->args++;
	}
}


