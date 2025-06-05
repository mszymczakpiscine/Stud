/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:59:18 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 15:02:01 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i;
	i = 256;
	while (i >>= 1)
	{
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	}
}
int main()
{
	unsigned char octet = 2;
	print_bits(octet);
}
