/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_w.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:38:22 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 10:52:34 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	first_w(int argc, char **argv)
{
	int	i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == 9)
			i++;
		while ((argv[1][i] != ' ' && argv[1][i] != 9) && argv[1][i])
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return 0;
}
int	main (int argc, char **argv)
{
	first_w(argc, argv);
	return 0;
}