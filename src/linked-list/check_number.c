#include "push_swap.h"

void	check_number(char **str)
{
	while (*str != NULL)
	{
		if (!ft_isnumber(*str))
			print_err();
		str++;
	}
}
