#include "push_swap.h"

void	solve(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	bit;
	int	commands;
	int	order;

	commands = 0;
	bit = 0;
	while (is_sorted(*stack_a) != 1)
	{
		commands = 0;
		while (commands < len)
		{
			order = (*stack_a)->order;
			if (((order >> bit) & 1) == 0)
				pb(stack_a, stack_b, "pb\n");
			else
				ra(stack_a, "ra\n");
			commands++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, "pa\n");
		bit++;
	}
}
