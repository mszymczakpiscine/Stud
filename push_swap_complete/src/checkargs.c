/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:19:46 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/29 18:57:35 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	if (!num || !num[0])
		return (0);
	i = 0;
	if (num[0] == '-')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	free_and_error(char **args, int argc)
{
	if (argc == 2)
		ft_free(args);
	ft_error("Error");
}

static void	check_limits_and_duplicates(char **args, int argc, int i)
{
	long	tmp;

	while (args[i])
	{
		if (!ft_isnum(args[i]))
			free_and_error(args, argc);
		tmp = ft_atoi(args[i]);
		if (tmp < -2147483648 || tmp > 2147483647)
			free_and_error(args, argc);
		if (ft_contains(tmp, args, i))
			free_and_error(args, argc);
		i++;
	}
	if (i <= 1)
		free_and_error(args, argc);
}

void	ft_check_args(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			if (args)
				ft_free(args);
			ft_error("Error");
		}
	}
	else
	{
		i = 1;
		args = argv;
	}
	check_limits_and_duplicates(args, argc, i);
	if (argc == 2)
		ft_free(args);
}
