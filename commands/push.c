#include "../push_swap.h"

void	pa(stack **stack_a, stack **stack_b, char *str)
{
	int	first_b;
	int order;

	if (stack_len(*stack_b) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	order = (*stack_b)->order;
	first_b = pop(stack_b);
	push(stack_a, first_b, order);
	// foo->a_size++;
	// foo->b_size--;
}

void	pb(stack **stack_a, stack **stack_b, char *str)
{
	int	first_a;
	int order;

	if (stack_len(*stack_a) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	order = (*stack_a)->order;
	first_a = pop(stack_a);
	push(stack_b, first_a, order);
	// foo->a_size--;
	// foo->b_size++;
}
