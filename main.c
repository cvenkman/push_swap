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

void sortt(stack *stack_a, stack *stack_b)
{
	int i;
	int small;
	int u;

	i = 1;
	u = 0;
	while (stack_a)
	{
		small = smallest(stack_a);
		while (stack_a->value != small)
		{
			ra(&stack_a, NULL);
		}
		stack_a->order = i;
		i++;
		pb(&stack_a, &stack_b, NULL);
		u++;
	}
	while (u > 0)
	{
		pa(&stack_a, &stack_b, NULL);
		u--;
	}
}

int	main(int argc, char **argv)
{
	stack	*stack_a;
	stack	*stack_b;
	stack	stack_for_sort;
	int		len;
	stack *tmp;
	stack *head;

	len = 1;
	tmp = NULL;

	stack_a = NULL;
	stack_b = NULL;
	argv[1] = "2";
	argv[2] = "1";
	argv[3] = "19";
	argv[4] = "30";
	argv[5] = "23";
	argv[6] = "11";
	argv[7] = "43";
	argv[8] = "22";
	argv[9] = "0";
	argc = 10;
	if (argc == 1)
		exit_str("");
	while (len < argc)
	{
		add_argv(&stack_a, ft_atoi(argv[len]));
		len++;
	}
	head = stack_a;
	len = 1;
	while (len < argc)
	{
		add_argv(&tmp, ft_atoi(argv[len]));
		len++;
	}
	duplicates_check(stack_a);
	print_stack(stack_a);
	len = stack_len(stack_a);
	sortt(tmp, stack_b);

	// while (stack_a)
	// {
	// 	while (stack_a->value != tmp->value)
	// 		stack_a = stack_a->next;
	// }
	// (tmp + 2)->next = tmp + 3;

	stack_a = head;
	printf("tmp:     ");
	print_stack(tmp);
	printf("satck_a: ");
	print_stack(stack_a);
	printf("satck_b: ");
	print_stack(stack_b);

}
