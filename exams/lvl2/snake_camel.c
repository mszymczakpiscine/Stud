/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_camel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:17:05 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 15:30:07 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_putchar(char c)
{
	write (1, &c , 1);
}

int main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
				ft_putchar(toupper(argv[1][++i]));
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
}