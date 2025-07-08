/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:46:35 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 19:05:41 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct t_stack
{
	int				value;
	int				index;
	struct t_stack	*next;
}				t_stack;

// Utils functions
t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *head);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
void	printlist(t_stack *head);
int		stack_size(t_stack *head);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_stack **stack);
int		get_distance(t_stack **stack, int index);
void	make_top(t_stack **stack, int distance);
void	free_stack(t_stack **stack);
void	ft_free(char **str);

// Algo utils
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	index_stack(t_stack **stack);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

// Instruction functions
int		swap(t_stack **stack);
int		push(t_stack **stack_to, t_stack **stack_from);
int		rotate(t_stack **stack);
int		reverse(t_stack **stack);

int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_b);
int		rr(t_stack **stack_a, t_stack **stack_b);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_b);
int		rrr(t_stack **stack_a, t_stack **stack_b);

#endif
