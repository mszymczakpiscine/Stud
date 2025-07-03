/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_camel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 10:31:03 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/03 10:39:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int upper = 0;
	char c;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
				upper = 1;
			else
			{
				if (upper && argv[1][i] >= 'a' && argv[1][i] <= 'z')
				{
					c = argv[1][i] - 32;
					write(1, &c, 1);
				}
				else 
					write(1, &argv[1][i], 1);
				upper = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
