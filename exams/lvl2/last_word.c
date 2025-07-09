/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:22:07 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 14:53:33 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int argc, char **argv)
{
	int i = 0;
	int in_word = 0;
	int first_word = 1;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				in_word = 0;
			else
			{
				if (!in_word)
				{
					if (!first_word)
						write(1, " ", 1);
					first_word = 0;
				}
				write(1, &argv[1][i], 1);
				in_word = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
