/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:52:26 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/11 14:52:26 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	char bytes = 8;
	while(bytes--)
	{
		int result = (octet >> bytes & 1) + '0';
		write(1, &result, 1);
	}
}
//
// int	main()
// {
// 	print_bits(2);
// }
