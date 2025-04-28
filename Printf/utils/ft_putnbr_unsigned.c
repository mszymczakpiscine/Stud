/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 19:44:50 by codespace         #+#    #+#             */
/*   Updated: 2025/04/28 19:44:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
    int len = 0;

    if (n >= 10)
        len += ft_putnbr_unsigned(n / 10);
    len += ft_putchar(n % 10 + '0');
    return (len);
}
