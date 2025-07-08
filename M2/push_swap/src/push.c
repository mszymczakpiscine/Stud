/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:17:47 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 17:40:35 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **stack_to, t_stack **stack_from)
{
	t_stack	*tmp;
	t_stack	*source_to;
	t_stack	*dest_from;

	if (stack_size(*stack_from) == 0)
		return (-1);
	source_to = *stack_to;
	dest_from = *stack_from;
	tmp = dest_from;
	dest_from = dest_from->next;
	*stack_from = dest_from;
	if (!source_to)
	{
		source_to = tmp;
		source_to->next = NULL;
		*stack_to = source_to;
	}
	else
	{
		tmp->next = source_to;
		*stack_to = tmp;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
