#include "push_swap.h"

void	exit_str(char *str_error)
{
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
