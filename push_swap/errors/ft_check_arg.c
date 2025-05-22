/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:27:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/05/22 13:46:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	if (str[i] < '0' || str[i] > '9')
	{
		return (0);
		i++;
	}
	return (1);
}

int			check_args(int argc, char **argv)
{
	int		i;
	long	value;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (0);
		if (!is_valid_number(argv[i]))
			return (0);
		value = ft_atoi(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}