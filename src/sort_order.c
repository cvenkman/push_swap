#include "../push_swap.h"

static int	smallest(t_stack *head)
{
	int	smallest;
	int	smallest_i;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (head)
	{
		if (head->value < smallest)
			smallest = head->value;
		head = head->next;
	}
	return (smallest);
}

static int	smallest1(t_stack *head, int num)
{
	int	smallest;
	int	smallest_i;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (head)
	{
		if (head->value < smallest && head->value > num)
			smallest = head->value;
		head = head->next;
	}
	return (smallest);
}

void	sort(t_stack **stack_a, t_stack *stack_b)
{
	int		i;
	int		small;
	int		u;
	int		len;
	t_stack	*head;

	i = 0;
	u = 0;
	head = *stack_a;
	len = stack_len(*stack_a);
	small = smallest(*stack_a);
	while (i != len)
	{
		while ((*stack_a)->value != small)
			*stack_a = (*stack_a)->next;
		(*stack_a)->order = i;
		i++;
		*stack_a = head;
		small = smallest1(*stack_a, small);
	}
}
