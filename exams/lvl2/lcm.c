/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:42:52 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/09 17:42:52 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int i = 1;
	int j = 1;

	if (a == 0 || b == 0)
		return 0;
	while (1)
	{
		if ((i * a) == (j * b))
			return (i * a);
		if (i * a > j * b)
		{
			if ((UINT_MAX - (j * b)) < b)
				return 0;
			j++;
		}
		else if (i * a < j * b)
		{
			if ((UINT_MAX - (i * a)) < a)
				return 0;
			i++;
		}
	}
}
/*
int	main()
{
	unsigned int result = lcm(-1, 5);
	printf("%u", result);
}
*/
