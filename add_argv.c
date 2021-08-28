#include "push_swap.h"

static stack	*ft_lstlast_stack(stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

static void	ft_lstadd_back_stack(stack **lst, stack *new)
{
	stack	*last;

	last = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_stack(*lst);
		last->next = new;
	}
}


void	add_argv(stack **head, int num)
{
	stack	*new;

	new = malloc(sizeof(stack));
	if (!new)
		exit_str("malloc");
	new->value = num;
	new->next = NULL;
	ft_lstadd_back_stack(head, new);
}
