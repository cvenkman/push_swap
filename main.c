#include "push_swap.h"

int	smallest(stack *head)
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
		}
		head = head->next;
	}
	return(smallest);
}

int foo(int *arr, int num)
{
	int i = 0;
	while (arr[i])
	{
		if (arr[i] == num)
			return (-1);
		i++;
	}
	return (0);
}

int	smallest1(stack *head, int num)
{
	int	smallest;
	int	smallest_i;
	int	i;

	i = 0;
	smallest = 2147483647;
	while (head)
	{
		if (head->value < smallest && head->value > num)
		{
			smallest = head->value;
		}
		head = head->next;
	}
	return(smallest);
}
void sortt(stack **stack_a, stack *stack_b)
{
	int i;
	int small;
	int u;
	stack *head;

	i = 0;
	u = 0;
	int y = 0;
	head = *stack_a;
	int len = stack_len(*stack_a);
	small = smallest(*stack_a);
	while (i != len)
	{
		while ((*stack_a)->value != small)
		{
			*stack_a = (*stack_a)->next;
		}
		(*stack_a)->order = i;
		i++;
		*stack_a = head;
		small = smallest1(*stack_a, small);
	}
	// printf("sstack_a (head):     ");
	// print_stack(*stack_a);
}

void order_stack_a(stack **stack_a, stack *tmp)
{
	stack *head;

	head = *stack_a;
	while (tmp)
	{
		*stack_a = head;
		while ((*stack_a)->value != tmp->value)
			*stack_a = (*stack_a)->next;
		(*stack_a)->order = tmp->order;
		tmp = tmp->next;
	}
}


int gg(stack *stack_a, int bit)
{
	int i = 0;
	int order;
	order = stack_a->order;
	while (stack_a)
	{
		if (((order >> bit) & 1) == 0)
			return (-1);
		stack_a = stack_a->next;
		if (stack_a)
			order = stack_a->order;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	stack	*stack_a;
	stack	*stack_b;
	stack	stack_for_sort;
	int		len;
	stack *tmp;
	stack *head;
	int order;

	int i = 1;
	len = 1;
	tmp = NULL;

	stack_a = NULL;
	stack_b = NULL;
	// argv[1] = "2"; //      10
	// argv[2] = "1"; //       1
	// argv[3] = "7"; //     111
	// argv[4] = "30"; //  11110
	// argv[5] = "-7"; //  10111
	// argv[6] = "11"; //   1011
	// argv[7] = "43"; // 101011
	// argv[8] = "22"; //  10110
	// argv[9] = "0"; //       0
	// argc = 10;
	if (argc == 1)
		exit_str("");
	while (len < argc)
	{
		add_argv(&stack_a, ft_atoi(argv[len]));
		len++;
	}
	head = stack_a;
	duplicates_check(stack_a);
	// print_stack(stack_a);
	len = stack_len(stack_a);
	sortt(&stack_a, stack_b);
	stack_a = head;
	// printf("satck_a: ");
	// print_stack(stack_a);
	// printf("satck_b: ");
	// print_stack(stack_b);

	// printf("%d  %d\n", 127, ((127 >> 6) & 1));
	// order = stack_a->order;
	// while (is_sorted(stack_a) != 1)
	// {
	i = 0;
		int u = 0;
		while (is_sorted(stack_a) != 1)
		{
			u = 0;
			while (u < len)
			{
				order = stack_a->order;
				if (((order >> i) & 1) == 0)
				{
					pb(&stack_a, &stack_b, "pb\n");

				}
				else
				{
					ra(&stack_a, "ra\n");
				}
				u++;
			}
			
			// printf("sort satck_a: ");
			// print_stack(stack_a);
			// printf("sort satck_b: ");
			// print_stack(stack_b);
			while (stack_b)
				pa(&stack_a, &stack_b, "pa\n");
			i++;
		}
	// }
	// printf("sort satck_a: ");
	// print_stack(stack_a);
	// printf("sort satck_b: ");
	// print_stack(stack_b);
}
