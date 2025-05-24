/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 11:47:53 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_doubles(t_stack *stack)
{
	t_node	*current;
	t_node	*check;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (check->value == current->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
} 