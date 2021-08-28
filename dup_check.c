#include "push_swap.h"

void	duplicates_check(stack *head)
{
	stack	*tmp;
	stack	*tmp_head;
	
	tmp_head = head;
	int i;
	while (head)
	{
		tmp = tmp_head;
		i = 0;
		while (tmp)
		{
			if (head->value == tmp->value)
				i++;
			if (i > 1)
				exit_str("there are duplicates");
			tmp = tmp->next;
		}
		head = head->next;
	}
}
