/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 13:43:20 by mszymcza         ###   ########.fr       */
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

static void	sort_four_to_six(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = get_stack_size(stack_a);
	i = 0;
	// Trouve et pousse les plus petits éléments dans l'ordre
	while (i < size - 3)
	{
		int	min = get_min(stack_a);
		while (stack_a->top->value != min)
		{
			if (stack_a->top->next && stack_a->top->next->value == min)
				sa(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}

	// Trie les 3 éléments restants
	if (!is_sorted(stack_a))
		sort_three(stack_a);

	// Ramène les éléments dans l'ordre
	while (stack_b->top)
		pa(stack_a, stack_b);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (is_sorted(stack_a))
		return;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 6)
		sort_four_to_six(stack_a, stack_b);
}
