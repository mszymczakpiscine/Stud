/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:53:14 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 11:03:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
}

int	main(void)
{
	int	i = 1;
	
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz", 9);
		else if ((i % 5 == 0))
			write(1, "buzz", 5);
		else if ((i % 3 == 0))
			write(1, "fizz", 5);
		else 
			ft_putnbr(i);
		i++;
	write(1, "\n", 1);
	}
}