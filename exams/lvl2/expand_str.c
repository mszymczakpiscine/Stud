/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:05:42 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/03 11:11:35 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int word = 0;
	int first = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				word = 0;
			else
			{
				if (word == 0 && !first)
					write(1, "   ", 3);
				write(1, &argv[1][i], 1);
				word = 1;
				first = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
