/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:33:21 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/10 14:36:16 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char	tab[256] = {0};

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (tab[(int)argv[1][i]] == 0)
			{
				write(1, &argv[1][i], 1);
				tab[(int)argv[1][i]] = 1;
			}
			i++;
		}
		while (argv[2][j])
		{
			if (tab[(int)argv[2][j]] == 0)
			{
				write(1, &argv[2][j], 1);
				tab[(int)argv[2][j]] = 1;
			}
			j++;
		}
	}
	write(1, "\n", 1);
}
