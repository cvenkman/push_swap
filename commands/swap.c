#include "../push_swap.h"

void	sa(stack **stack_a, char *str)
{
	int	first_value;
	int	second_value;

	if (stack_len(*stack_a) == 0 || stack_len(*stack_a) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_value = (*stack_a)->value;
	pop(stack_a);
	second_value = (*stack_a)->value;
	(*stack_a)->value = first_value;
	push(stack_a, second_value);
}

void	sb(stack **stack_b, char *str)
{
	int	first_value;
	int	second_value;

	if (stack_len(*stack_b) == 0 || stack_len(*stack_b) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	first_value = (*stack_b)->value;
	pop(stack_b);
	second_value = (*stack_b)->value;
	(*stack_b)->value = first_value;
	push(stack_b, second_value);
}

void	ss(stack **stack_a, stack **stack_b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	sa(stack_a, NULL);
	sb(stack_b, NULL);
}
