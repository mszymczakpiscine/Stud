/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:44:50 by codespace         #+#    #+#             */
/*   Updated: 2025/05/07 13:33:30 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c);

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}
