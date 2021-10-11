#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct q_list {
	int				value;
	unsigned int	order;
	struct q_list	*next;
}				t_stack;

// src
void	add_argv(t_stack **head, char *num);
void	solve(t_stack **stack_a, t_stack **stack_b, int len);
void	sort_small_stack(t_stack **stack_a, t_stack **stack_b, int stack_len);

// src/stuff.c
int		stack_len(t_stack *head);
int		find_biggest(t_stack *head);
int		find_smallest(t_stack *head);
int		is_sorted(t_stack *head);

// src/errors.c
void	exit_str(char *str_error);
void	print_stack(t_stack *head);

// src/dup_check.c
void	duplicates_check(t_stack *head);

// src/sort_order.c
void	sort(t_stack **stack_a, t_stack *stack_b);

// commands
void	sa(t_stack **stack_a, char *str);
void	sb(t_stack **stack_b, char *str);
void	ss(t_stack **stack_a, t_stack **stack_b, char *str);
void	pb(t_stack **stack_a, t_stack **stack_b, char *str);
void	pa(t_stack **stack_a, t_stack **stack_b, char *str);
void	ra(t_stack **stack_a, char *str);
void	rb(t_stack **stack_b, char *str);
void	rr(t_stack **stack_a, t_stack **stack_b, char *str);
void	rra(t_stack **stack_a, char *str);
void	rrb(t_stack **stack_a, char *str);
void	rrr(t_stack **stack_a, t_stack **stack_b, char *str);

#endif