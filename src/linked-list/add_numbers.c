#include "push_swap.h"

void	add_numbers(t_stack **stack, char **argv)
{
	int			i;
	long	value;
	char	**args;	

	check_(argv);
	while (*argv != NULL)
	{
		i = -1;
		args = ft_split(*argv, ' ');
		while (args[++i] != NULL)
		{
			value = ft_atol(args[i]);
			if (value > INT_MAX || value < INT_MIN)
				print_err();
			check_dup(*stack, value);
			insert(stack, add_node((int)value));
		}
		ft_free(args);
		argv++;
	}
}
