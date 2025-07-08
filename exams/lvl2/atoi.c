/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 12:32:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 12:39:43 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int atoi = 0;

	if (!str)
		return 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sign = (sign * 10);
		sign += (str[i] - '0');
		i++;
	}
	return (atoi *= sign);
}