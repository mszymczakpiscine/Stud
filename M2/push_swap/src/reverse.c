/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:16:28 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 17:39:49 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse(t_stack **stack)
{
	t_stack	*top;
	t_stack	*last;
	t_stack	*before_last;

	if (stack_size(*stack) < 2)
		return (-1);
	top = *stack;
	last = stack_last(top);
	before_last = top;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last->next = top;
	before_last->next = NULL;
	*stack = last;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverse(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverse(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) < 2 || stack_size(*stack_b) < 2)
		return (-1);
	reverse(stack_a);
	reverse(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
