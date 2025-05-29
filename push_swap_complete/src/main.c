/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:33:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 19:03:40 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**init_args(int argc, char **argv, int *i)
{
	char	**args;

	if (argc == 2)
	{
		if (!argv[1][0])
			exit(0);
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				ft_free(args);
			exit(0);
		}
		*i = 0;
	}
	else
	{
		args = argv;
		*i = 1;
	}
	return (args);
}

static void	fill_stack(t_stack **stack, char **args, int i)
{
	while (args[i])
		stack_add_back(stack, stack_new(ft_atoi(args[i++])));
	if (stack_size(*stack) == 1)
	{
		free_stack(stack);
		exit(0);
	}
	index_stack(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = init_args(argc, argv, &i);
	ft_check_args(argc, args);
	fill_stack(&stack_a, args, i);
	if (!is_sorted(&stack_a))
	{
		if (stack_size(stack_a) <= 5)
			simple_sort(&stack_a, &stack_b);
		else
			radix_sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc == 2)
		ft_free(args);
	return (0);
}
