/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:58:37 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/09 16:58:37 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	char *str;

	if (argc >= 2)
	str = argv[1];
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = i;
	while (str[i])
	{
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while ((str[i] && str[i] != ' ' && str[i] != '\t') && (str[i - 1] == ' ' || str[i - 1] == '\t'))
		{
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
			i++;
		}
	}
	while (str[j] && str[j] != ' ' && str[j] != '\t')
	{
		write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
	return (0);
}

