#include "push_swap.h"

static void	check_and_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		len;

	duplicates_check(*stack_a);
	len = stack_len(*stack_a);
	if (len <= 5)
		sort_small_stack(stack_a, stack_b, len);
	sort(stack_a, *stack_b);
	solve(stack_a, stack_b, len);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
	int		i;
	char	**arr_argv;

	i = 0;
	len = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit_str("");
	if (argc == 2)
		add_argv(&stack_a, argv[1]);
	else
		while (len < argc)
			add_argv(&stack_a, argv[len++]);
	if (stack_len(stack_a) == 1)
		return (0);
	if (stack_len(stack_a) == 0)
		exit_str("Error");
	check_and_sort(&stack_a, &stack_b);
	return (0);
}
