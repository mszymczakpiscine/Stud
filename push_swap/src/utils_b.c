/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:41:33 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 17:41:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_top(t_stack **stack, int distance)
{
	int	size;

	size = stack_size(*stack);
	if (distance > size / 2)
	{
		while (distance < size)
		{
			reverse(stack);
			distance++;
		}
	}
	else
	{
		while (distance > 0)
		{
			rotate(stack);
			distance--;
		}
	}
}
