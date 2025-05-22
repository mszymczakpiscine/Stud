/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:35 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/20 14:48:43 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//write(2, "Error\n", 6) -> si pas nb, pas dans int ou doublons
static	void	init_stack(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = init_stack();
	*stack_a = init_stack();
	if (!*stack_a || !*stack_b)
		error_exit(*stack_a, *stack_b);
}	

static	void	fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int i;

	i = argc -1;
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
	
	if (argv < 2 || !check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stacks(&stack_a, &stack_b);
	fill_stack_a(stack_a, argc, argv);
	if (check_double(stack_a))
	{
		write(2, "Error\n", 6);
		error_exit(stack_a, stack_b);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
