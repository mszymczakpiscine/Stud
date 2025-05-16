/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/16 11:48:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = init_stack();
	*stack_b = init_stack();
	if (!*stack_a || !*stack_b)
		error_exit(*stack_a, *stack_b);
}

static void	fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		add_node(stack_a, ft_atoi(argv[i]));
		i--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || !check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stacks(&stack_a, &stack_b);
	fill_stack_a(stack_a, argc, argv);
	if (check_doubles(stack_a))
	{
		write(2, "Error\n", 6);
		error_exit(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
