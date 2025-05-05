/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:21:08 by codespace         #+#    #+#             */
/*   Updated: 2025/05/05 11:59:30 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);

int	ft_putptr(uintptr_t n)
{
	char			*base;
	int				len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_putptr(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}
