/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:14:47 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/22 10:24:50 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack_a, t_stack *stack_b)
{
	char	*msg;
	
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	exit(EXIT_FAILURE);
}