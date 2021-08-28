#include "../push_swap.h"

void	ra(stack **stack_a, char *str)
{
	stack	*head;
	stack	*second;

	if (stack_len(*stack_a) == 0 || stack_len(*stack_a) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_a;
	second = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = head;
	(*stack_a)->next->next = NULL;
	*stack_a = second;
}

void	rb(stack **stack_b, char *str)
{
	stack	*head;
	stack	*second;

	if (stack_len(*stack_b) == 0 || stack_len(*stack_b) == 1)
		return ;
	if (str)
		ft_putstr_fd(str, 1);
	head = *stack_b;
	second = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = head;
	(*stack_b)->next->next = NULL;
	*stack_b = second;
}

void	rr(stack **stack_a,stack **stack_b, char *str)
{
	if (str)
		ft_putstr_fd(str, 1);
	ra(stack_a, NULL);
	rb(stack_b, NULL);
}