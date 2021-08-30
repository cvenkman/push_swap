#include "../push_swap.h"

void	duplicates_check(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp_head;
	int		i;

	tmp_head = head;
	while (head)
	{
		tmp = tmp_head;
		i = 0;
		while (tmp)
		{
			if (head->value == tmp->value)
				i++;
			if (i > 1)
				exit_str("Error");
			tmp = tmp->next;
		}
		head = head->next;
	}
}
