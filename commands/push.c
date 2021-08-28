#include "../push_swap.h"

void	pa(stack **stack_a, stack **stack_b, char *str)
{
	int	first_b;

	if (stack_len(*stack_b) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_b = pop(stack_b);
	push(stack_a, first_b);
	// foo->a_size++;
	// foo->b_size--;
}

void	pb(stack **stack_a, stack **stack_b, char *str)
{
	int	first_a;

	if (stack_len(*stack_a) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_a = pop(stack_a);
	push(stack_b, first_a);
	// foo->a_size--;
	// foo->b_size++;
}
