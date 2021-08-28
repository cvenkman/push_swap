#include "push_swap.h"

int	is_sorted(stack *head)
{
	while (head->value < head->next->value)
	{
		head = head->next;
		if (head->next == NULL)
			return (1);
	}
	return (0);
}

int	find_smallest(stack *head)
{
	int	smallest;
	int	smallest_i;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (head)
	{
		if (head->value < smallest)
		{
			smallest = head->value;
			smallest_i = i;
		}
		i++;
		head = head->next;
	}
	// printf("smallest %d on %d\n", smallest, smallest_i);
	return(smallest_i);
}

int	find_biggest(stack *head)
{
	int	biggest;
	int	biggest_i;
	int	i;

	i = 0;
	biggest = -2147483648;
	while (head)
	{
		if (head->value > biggest)
		{
			biggest = head->value;
			biggest_i = i;
		}
		i++;
		head = head->next;
	}
	// printf("biggest %d on %d\n", biggest, biggest_i);
	return(biggest_i);
}

void	median(stack **head, int stack_len)
{
	int i;
	i = find_smallest(*head);
	if (i < stack_len / 2)
	{
		while (find_smallest(*head) != 0)
			ra(head, "ra\n");
	}
	else
	{
		while (find_smallest(*head) != 0)
			rra(head, "rra\n");
	}
}

void	print_stack(stack *head)
{
    while (head)
	{
        printf("%d (%d)   ", head->value, head->order);
        head = head->next;
    }
	printf ("\n");
}

int	stack_len(stack *head)
{
	int		len;
	stack	*tmp;

	tmp = head;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	push(stack **head, int num)
{
	stack	*new;
	stack	*first;

	new = malloc(sizeof(stack));
	if (!new)
    	exit_str("malloc");
	new->next = *head;
	new->value = num;
	*head = new;
}

int	pop(stack **head)
{
	stack	*out;
	int		num;

	if (*head == NULL)
	{
		ft_putstr_fd("stack end\n", 1);
		return (-1);
	}
	out = *head;
	*head = (*head)->next;
	num = out->value;
	free (out);
	return (num);
}
// int foo(stack *head, int midpoint)
// {
// 	while (head->next)
// 	{
// 		if (head->value < midpoint)
// 			return (1);
// 		head = head->next;
// 	}
// 	return (0);
// }

	// while (stack_a)
	// {
	// 	tmp->value = stack_a->value;
	// 	tmp->next = NULL;
	// 	stack_a = stack_a->next;
	// 	tmp = tmp->next;
	// }
	// tmp->next = NULL;