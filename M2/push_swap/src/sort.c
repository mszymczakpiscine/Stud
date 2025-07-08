/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:02:29 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/03 11:18:34 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	sort_two(t_stack **stack_a, t_stack *top)
{
	top = *stack_a;
	if (top->value > top->next->value)
		sa(stack_a);
}

static void	sort_three(t_stack **stack_a)
{
	t_stack	*top;

	top = *stack_a;
	if (top->value > top->next->value
		&& top->next->value < top->next->next->value
		&& top->value < top->next->next->value)
		sa(stack_a);
	else if (top->value > top->next->value
		&& top->next->value > top->next->next->value)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top->value > top->next->value
		&& top->next->value < top->next->next->value)
		ra(stack_a);
	else if (top->value < top->next->value
		&& top->next->value > top->next->next->value)
	{
		if (top->value < top->next->next->value)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
}

static int	find_min_index(t_stack *stack)
{
	int	min;
	int	index;

	min = stack->value;
	index = stack->index;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	while (stack_size(*stack_a) > 3 && !is_sorted(stack_a))
	{
		min_index = find_min_index(*stack_a);
		while ((*stack_a)->index != min_index)
			rra(stack_a);
		pb(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	t_stack	top;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a, &top);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
}
