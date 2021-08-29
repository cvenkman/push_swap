#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

#define RR_RA_RB 0
#define RRR_RRA_RRB 1
#define RA_RRB 2
#define RRA_RB 3

typedef struct	q_list {
	int		value;
	int		order;
	struct	q_list *next;
}				stack;
typedef struct	t_list {
	int	RA;
	int	RRA;
	int	RB;
	int	RRB;
	int	total;
	int	mode;
}				stuff;

void	add_argv(stack **head, int num);
void	exit_str(char *str_error);
void	print_stack(stack* head);
void	push(stack **head, int num, int order);
void	duplicates_check(stack *head);
void	sa(stack **stack_a, char *str);
void	sb(stack **stack_b, char *str);
void	ss(stack **stack_a, stack **stack_b, char *str);
void	pb(stack **stack_a, stack **stack_b, char *str);
void	pa(stack **stack_a, stack **stack_b, char *str);
void	ra(stack **stack_a, char *str);
void	rb(stack **stack_b, char *str);
void	rr(stack **stack_a, stack **stack_b, char *str);
void	rra(stack **stack_a, char *str);
void	rrb(stack **stack_a, char *str);
void	rrr(stack **stack_a, stack **satck_b,  char *str);
int		stack_len(stack *head);
int		find_biggest(stack *head);
int		find_smallest(stack *head);
int		pop(stack **head);
int		ft_array(stack *stack_a, int len);
void	median(stack **head, int stack_len);
void	sort_two(stack **stack_a);
void	sort_three(stack **head);
void	sort(stack **stack_a, stack **stack_b);
void	sort_small_stack(stack **stack_a, stack **stack_b, int stack_len);
int	is_sorted(stack *head);
#endif