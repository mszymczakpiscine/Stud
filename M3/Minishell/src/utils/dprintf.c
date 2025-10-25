/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                          :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:41:54 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/04 19:41:54 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_dprintf_putstr(int fd, char *s)
{
	if (!s)
		s = "(null)";
	return (write(fd, s, ft_strlen(s)));
}

static int	ft_dprintf_putnbr(int fd, int n)
{
	char	*s;
	int		len;

	s = ft_itoa(n);
	if (!s)
		return (0);
	len = ft_dprintf_putstr(fd, s);
	free(s);
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				len += ft_dprintf_putstr(fd, va_arg(args, char *));
			else if (format[i] == 'd')
				len += ft_dprintf_putnbr(fd, va_arg(args, int));
			else if (format[i] == '%')
				len += write(fd, "%", 1);
		}
		else
			len += write(fd, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
