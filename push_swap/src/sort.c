/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:02:29 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/03 10:32:24 by mszymcza         ###   ########.fr       */
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

static void	sort_three(t_stack **stack_a, t_stack *top)
{
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

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		index;
	t_stack	*top;

	while (stack_size(*stack_a) > 3)
	{
		top = *stack_a;
		min = top->value;
		index = top->index;
		while (top)
		{
			if (top->value < min)
			{
				min = top->value;
				index = top->index;
			}
			top = top->next;
		}			
		while ((*stack_a)->index != index)
			rra(stack_a);
		if (!is_sorted(stack_a))
			pb(stack_b, stack_a);
		else
			break;
	}
	sort_three(stack_a, top);
	while (stack_size(*stack_b) > 0)
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
		sort_three(stack_a, &top);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
}

//static int	get_max_bits(t_stack **stack)
//{
//	t_stack	*top;
//	int		max;
//	int		max_bits;

//	top = *stack;
//	max = top->index;
//	max_bits = 0;
//	while (top)
//	{
//		if (top->index > max)
//			max = top->index;
//		top = top->next;
//	}
//	while ((max >> max_bits) != 0)
//		max_bits++;
//	return (max_bits);
//}

//void	radix_sort(t_stack **stack_a, t_stack **stack_b)
//{
//	t_stack	*top;
//	int		i;
//	int		j;
//	int		size;
//	int		max_bits;

//	i = 0;
//	top = *stack_a;
//	size = stack_size(top);
//	max_bits = get_max_bits(stack_a);
//	while (i < max_bits)
//	{
//		j = 0;
//		while (j++ < size)
//		{
//			top = *stack_a;
//			if (((top->index >> i) & 1) == 1)
//				ra(stack_a);
//			else
//				pb(stack_b, stack_a);
//		}
//		while (stack_size(*stack_b) != 0)
//			pa(stack_a, stack_b);
//		i++;
//	}
//}
