/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:31:55 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/10 10:41:03 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int word = 0;
	int word_see = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				word = 0;
			else
			{
				if (!word && word_see)
					write(1, " ", 1);
				write(1, &argv[1][i], 1);
				word = 1;
				word_see = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
		
