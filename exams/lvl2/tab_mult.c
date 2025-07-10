/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 09:14:05 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/10 09:28:31 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	char c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int rest = 0, i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rest = rest * 10 + (str[i] - 48);
		i++;
	}
	return rest;
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 1, n = ft_atoi(argv[1]);
		while (i < 10)
		{
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(n);
			ft_putstr(" = ");
			ft_putnbr(i * n);
			write(1, "\n", 1);
			i++;
		}
	}
	else 
		write(1, "\n", 1);
}

		
