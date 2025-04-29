/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:53:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/29 11:08:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int ft_format(va_list args, char c)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int)));
    else if (c == 's')
        return (ft_putstr(va_arg(args, char *)));
    else if (c == 'd' || c == 'i')
        return (ft_putnbr(va_arg(args, int)));
    else if (c == 'u')
        return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
    else if (c == 'x')
        return (ft_puthex(va_arg(args, unsigned int), 0));
    else if (c == 'X')
        return (ft_puthex(va_arg(args, unsigned int), 1));
    else if (c == 'p')
    {
        int len = 0;
        len += ft_putstr("0x");
        len += ft_putptr(va_arg(args, void *));
        return (len);
    }
    else if (c == '%')
        return (ft_putchar('%'));
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int len = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
            len += ft_format(args, format[++i]);
        else
            len += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (len);
}
