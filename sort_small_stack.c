#include "push_swap.h"

void sort_two(stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, "sa\n");
}

void	sort_three(stack **head)
{
	stack	*tmp;
	int		smallest_i;
	int		biggets_i;

	tmp = *head;
	smallest_i = find_smallest(*head);
	biggets_i = find_biggest(*head);
	if (smallest_i == 1 && biggets_i == 2)
		sa(head, "sa\n");
	else if (smallest_i == 2 && biggets_i == 1)
		rra(head, "rra\n");
	else if (smallest_i == 2 && biggets_i == 0)
	{
		sa(head, "sa\n");
		rra(head, "rra\n");
	}
	else if (smallest_i == 1 && biggets_i == 0)
		ra(head, "ra\n");
	else if (smallest_i == 0 && biggets_i == 1)
	{
		sa(head, "sa\n");
		ra(head, "ra\n");
	}
}

static void	sort_four(stack **stack_a, stack **stack_b)
{
	if (find_smallest(*stack_a) == 3)
		rra(stack_a, "rra\n");
	else if (find_smallest(*stack_a) == 1 || find_smallest(*stack_a) == 2)
		while (find_smallest(*stack_a) != 0)
			ra(stack_a, "ra\n");
	pb(stack_a, stack_b, "pb\n");
	sort_three(stack_a);
	pa(stack_a, stack_b, "pa\n");
}

static void	sort_five(stack **stack_a, stack **stack_b)
{
	if (find_biggest(*stack_a) == 3 || find_biggest(*stack_a) == 4)
		while (find_biggest(*stack_a) != 0)
			rra(stack_a, "rra\n");
	else if (find_biggest(*stack_a) == 1 || find_biggest(*stack_a) == 2)
		while (find_biggest(*stack_a) != 0)
			ra(stack_a, "ra\n");
	pb(stack_a, stack_b, "pb\n");
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, "pa\n");
	ra(stack_a, "ra\n");
}

void	sort_small_stack(stack **stack_a, stack **stack_b, int stack_len)
{
	if (stack_len == 3)
		sort_three(stack_a);
	if (stack_len == 4)
		sort_four(stack_a, stack_b);
	if (stack_len == 5)
		sort_five(stack_a, stack_b);
}
