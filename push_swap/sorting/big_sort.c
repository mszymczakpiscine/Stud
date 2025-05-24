/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 21:37:43 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	normalize_stack(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		*normalized;
	int		size;
	int		pos;

	size = get_stack_size(stack);
	normalized = (int *)malloc(sizeof(int) * size);
	i = stack->top;
	while (i)
	{
		pos = 0;
		j = stack->top;
		while (j)
		{
			if (j->value < i->value)
				pos++;
			j = j->next;
		}
		normalized[size - get_stack_size(stack)] = pos;
		i = i->next;
	}
	i = stack->top;
	pos = 0;
	while (i)
	{
		i->value = normalized[pos++];
		i = i->next;
	}
	free(normalized);
}

static int	find_best_move(t_stack *stack_a, int value)
{
	t_node	*current;
	int		pos;
	int		size;

	pos = 0;
	size = get_stack_size(stack_a);
	current = stack_a->top;
	while (current && current->value != value)
	{
		pos++;
		current = current->next;
	}
	if (pos > size / 2)
		return (size - pos);
	return (pos);
}

static void	optimize_chunks(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int		size;
	int		chunk;
	int		i;
	int		pos;
	t_node	*current;

	size = get_stack_size(stack_a);
	chunk = 0;
	while (get_stack_size(stack_a) > 0)
	{
		i = 0;
		while (i < size && get_stack_size(stack_a) > 0)
		{
			current = stack_a->top;
			if (current->value >= chunk * chunk_size && 
				current->value < (chunk + 1) * chunk_size)
			{
				pb(stack_a, stack_b);
				if (stack_b->top->value < chunk * chunk_size + chunk_size / 2)
					rb(stack_b);
			}
			else
				ra(stack_a);
			i++;
		}
		chunk++;
	}

	while (stack_b->top)
	{
		i = get_max(stack_b);
		pos = find_best_move(stack_b, i);
		
		while (pos != 0)
		{
			if (pos > 0)
			{
				if (pos > get_stack_size(stack_b) / 2)
					rrb(stack_b);
				else
					rb(stack_b);
				pos = find_best_move(stack_b, i);
			}
		}
		pa(stack_a, stack_b);
	}
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	if (is_sorted(stack_a))
		return ;
	normalize_stack(stack_a);
	size = get_stack_size(stack_a);
	if (size <= 100)
		optimize_chunks(stack_a, stack_b, 15);
	else
		optimize_chunks(stack_a, stack_b, 30);
}
