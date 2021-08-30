#include "../push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int		first_b;
	int		order;
	t_stack	*tmp;

	tmp = *stack_b;
	if (stack_len(*stack_b) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	pb(t_stack **stack_a, t_stack **stack_b, char *str)
{
	int		first_a;
	int		order;
	t_stack	*tmp;

	tmp = *stack_a;
	if (stack_len(*stack_a) == 0)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}
