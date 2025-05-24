/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 21:36:17 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

static void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;

	if (a > b && b > c)  // 3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)  // 3 1 2
	{
		ra(stack_a);
	}
	else if (a > b && b < c && a < c)  // 2 1 3
	{
		sa(stack_a);
	}
	else if (a < b && b > c && a < c)  // 1 3 2
	{
		rra(stack_a);
	}
	else if (a < b && b > c && a > c)  // 2 3 1
	{
		ra(stack_a);
		sa(stack_a);
	}
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;
	int	size;

	min = get_min(a);
	pos = 0;
	size = get_stack_size(a);
	while (a->top->value != min && pos < size)
	{
		if (a->top->next && a->top->next->value == min)
			sa(a);
		else if (pos >= size / 2)
			rra(a);
		else
			ra(a);
		pos++;
	}
	pb(a, b);
}

static void	sort_four_to_six(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	while (get_stack_size(stack_a) > 3 && !is_sorted(stack_a))
	{
		push_min_to_b(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	while (stack_b->top)
		pa(stack_a, stack_b);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 6)
		sort_four_to_six(stack_a, stack_b);
}
