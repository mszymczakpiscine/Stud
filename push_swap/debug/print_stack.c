/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/24 11:49:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	print_stack(t_stack *stack, char stack_name)
{
	t_node	*current;

	write(1, "Stack ", 6);
	write(1, &stack_name, 1);
	write(1, ":\n", 2);
	if (!stack || !stack->top)
	{
		write(1, "(empty)\n", 8);
		return ;
	}
	current = stack->top;
	while (current)
	{
		ft_putnbr_fd(current->value, 1);
		write(1, "\n", 1);
		current = current->next;
	}
	write(1, "---\n", 4);
} 