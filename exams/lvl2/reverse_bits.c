/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:02:57 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 15:05:25 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result = 0;
	unsigned int	bytes = 8;
	
	while (bytes--)
	{
		result = (result << 1) | (octet & 1);
		octet >>= 1;
	}
	return (octet);
}
