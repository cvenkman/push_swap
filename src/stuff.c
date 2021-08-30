#include "../push_swap.h"

int	is_sorted(t_stack *head)
{
	while (head->value < head->next->value)
	{
		head = head->next;
		if (head->next == NULL)
			return (1);
	}
	return (0);
}

void	print_stack(t_stack *head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf ("\n");
}

int	stack_len(t_stack *head)
{
	int		len;
	t_stack	*tmp;

	tmp = head;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	find_smallest(t_stack *head)
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
	return (smallest_i);
}

int	find_biggest(t_stack *head)
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
	return (biggest_i);
}
