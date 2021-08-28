#include "push_swap.h"


int	find_elem(stack *head, int elem)
{
	int	i;

	i = 0;
	while (head && head->value != elem)
	{
		head = head->next;
		i++;
	}
	return(i);
}

void	ra_rra(stack **head, int stack_len, int elem)
{
	int i;
	i = find_elem(*head, elem);
	if (i < stack_len / 2)
		while (find_elem(*head, elem) != 0)
			ra(head, "ra\n");
	else
	{
		while (find_elem(*head, elem) != 0)
			rra(head, "rra\n");
	}
}

int	find_big(stack *head, int num, int len)
{
	int smallest_from_big = num;
	int	i;
	int min;
	int arr[len];
	
	i = 0;
	min = 2147483647;
	while (head)
	{
		if (head->value > num)
			arr[i++] = head->value;
		head = head->next;
	}
	// i = 0;
	// while (i < len)
	// {
	// 	printf("arr %d ", arr[i]);
	// 	i++;
	// }
	i = -1;
	while (++i < len)
		if (arr[i] < min)
			min = arr[i];
	return(min);
}


int	smallest_from_big(stack *head, int num)
{
	int	i;
	int smallest;

	stack *always_head;
	always_head = head;
	i = 0;
	if (stack_len(head) == 1)
		return (head->value); ////
	while (head)
	{
		if (head->value > num)
			i++;
		head = head->next;
	}
	head = always_head;
	if (i == 0)
	{
		smallest = find_smallest(head);
		while (i < smallest)
		{
			head = head->next;
			i++;
		}
		return (head->value);
	}
	return(find_big(head, num, i));
}
// 11 83 152 160 119 24 141 55 179 92 135 27 68 144 54 15 100 67 161 4 176 57 129 23 71 189 112 137 148 72 138 188 197 115 41 29 39 30 200 22 155 91 136 158 2

int ra_rra_end(stack *stack_a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stack_a->next && stack_a->value < stack_a->next->value)
	{
		i++;
		stack_a = stack_a->next;
	}
	stack_a = stack_a->next;
	while (stack_a->next && stack_a->value < stack_a->next->value)
	{
		j++;
		stack_a = stack_a->next;
	}
	if (i < j)
		return (0);
	return (1);
}

void	ra_rra_mode(stack *head, int stack_len, int elem, stuff **tmp)
{
	// int RRA;
	// int RA;
	// RRA = 0;
	// RA = 0;
	int i;
	// stack *tmp;
	int u = 0;
	i = find_elem(head, elem);
	if (i < stack_len / 2)
	{
		while (find_elem(head, elem) != 0)
		{
			ra(&head, NULL);
			(*tmp)->RA++;
		}
		while (u < (*tmp)->RA)
		{
			ra(&head, NULL);
			u++;
		}
	}
	else
	{
		while (find_elem(head, elem) != 0)
		{
			rra(&head, NULL);
			(*tmp)->RRA++;
		}
		while (u < (*tmp)->RRA)
		{
			ra(&head, NULL);
			u++;
		}
	}
	
	// return (j);
}

void find_mode(stack *stack_a, stack *stack_b, stuff **tmp, stuff **best)
{
	int		bigger_than_b_num;
	int i = 0;
	int RA_RRA;
	int PA;
	while (stack_b)
	{
		bigger_than_b_num = smallest_from_big(stack_a, stack_b->value);
		ra_rra_mode(stack_a, stack_len(stack_a), bigger_than_b_num, tmp);
		printf("ra %d\n", (*tmp)->RA);
		printf("rra %d\n", (*tmp)->RRA);
		// printf("ra %d\n", (*tmp)->RA);
		// printf("ra %d\n", (*tmp)->RA);
		stack_b = stack_b->next;
		// while (stack_b)
		// {
		// 	RA_RRA = ra_rra_mode(stack_a, stack_len(stack_a), bigger_than_b_num);
		// 	printf("ra_rra %d\n", RA_RRA);
		// 	stack_b = stack_b->next;
		// 	//stack_b = stack_b->next;
		// 	//ra_rra(stack_a, stack_len(*stack_a), bigger_than_b_num);
		// }
		// stack_b = stack_b->next;

		//pa(stack_a, stack_b, "pa\n");
	}
}

void	sort(stack **stack_a, stack **stack_b)
{
	int		bigger_than_b_num;
	stack	*head;
	stuff	*tmp;
	stuff	*best;
	int i = 1;

	head = *stack_a;
	tmp = malloc(sizeof(stuff));
	ft_bzero(tmp, sizeof(stuff));
	best = malloc(sizeof(stuff));
	// ft_bzero(best, sizeof(stuff));
	best->mode = 10000;
	best->RA = 10000;
	best->RB = 10000;
	best->RRA = 10000;
	best->RRB = 10000;
	best->total = 10000;
	while (stack_len(*stack_a) != 3)
		pb(stack_a, stack_b, "pb\n");
	sort_three(stack_a);

	while (*stack_b)
	{
		bigger_than_b_num = smallest_from_big(*stack_a, (*stack_b)->value);
		while (i-- > 0)
			find_mode(*stack_a, *stack_b, &tmp, &best);
		while ((*stack_a)->value != bigger_than_b_num && stack_len(*stack_a) > 1)
		{
			ra_rra(stack_a, stack_len(*stack_a), bigger_than_b_num);
			find_mode(*stack_a, *stack_b, &tmp, &best);
		}
		pa(stack_a, stack_b, "pa\n");
	}
	printf("satck_a: ");
	print_stack(*stack_a);
	printf("satck_b: ");
	print_stack(*stack_b);
	if (ra_rra_end(*stack_a) == 0)
		while (is_sorted(*stack_a) != 1)
			ra(stack_a, "ra\n");
	else
		while (is_sorted(*stack_a) != 1)
			rra(stack_a, "rra\n");
}
