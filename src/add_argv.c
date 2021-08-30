#include "../push_swap.h"

static t_stack	*ft_lstlast_stack(t_stack *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

static void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast_stack(*lst);
		last->next = new;
	}
}

static t_stack	*ft_lstnew_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit_str("malloc error");
	new->value = content;
	new->next = NULL;
	return (new);
}

void	add_argv(t_stack **head, char *num_str)
{
	t_stack	*new;
	char	**num_arr;
	int		num;
	int		i;
	int		flag;

	i = 0;
	num_arr = ft_split(num_str, ' ');
	while (num_arr[i])
	{
		num = ft_atoi(num_arr[i], &flag);
		if (flag == 1)
			exit_str("Error");
		new = ft_lstnew_stack(num);
		ft_lstadd_back_stack(head, new);
		i++;
	}
	i = 0;
	while (num_arr[i])
	{
		free(num_arr[i]);
		i++;
	}
	free(num_arr);
}
