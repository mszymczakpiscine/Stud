/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:48:00 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 17:40:55 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*top;
	t_stack	*next;
	int		tmp_val;
	int		tmp_index;

	if (stack_size(*stack) < 2)
		return (-1);
	top = *stack;
	next = top->next;
	if (!top && !next)
		ft_error("Ho my bad it's an error !");
	tmp_val = top->value;
	tmp_index = top->index;
	top->value = next->value;
	top->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(*stack_a) < 2 || stack_size(*stack_b) < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
