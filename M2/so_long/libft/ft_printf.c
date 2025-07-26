/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:53:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/05 16:16:52 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

static int	ft_pointer(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (ft_putstr("0x") + ft_putptr((uintptr_t)ptr));
}

static int	ft_format(va_list args, char c)
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
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_format(args, format[i]);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

//int	main(void)
//{
//	int	result1;
//	int	ressult2;

//	result1 = ft_printf("Test : %d\n", 92);
//	ressult2 = printf("Test : %d\n", 92);
//	printf("return ft_printf : %d, printf : %d\n", result1, ressult2);

//	ft_printf("cas spe 0 : %d\n", 0);
//	ft_printf("INT_MIN : %d, INT_MAX : %d\n", INT_MIN, INT_MAX);
//	ft_printf("NULL string : %s\n", (char *)NULL);

//	ft_printf("Mix : %d, %s, %c\n", 123, "abc", 'Z');
//	ft_printf("man on the moon : %d in space\n", 3);

//	result1 = ft_printf("return value : %s\n", "Flowers");
//	printf("return value ft_printf : %d\n", result1);
//}

//int	main(void)
//{
//	//char	*ptr = "hey";
//	ft_printf("%paaaaaaaaaaaaa%p\n", NULL, NULL);
//	printf("%paaaaaaaaaaaaaa%p\n", NULL,NULL);
//	return 0;
//}

//int	ft_printf(const char *format, ...);

//#include <stdlib.h>
//#include <stdio.h>
//int	main(void)
//{
//	char	*ptdr = "ndsjkbfkjslfjbkwes";
//	int ft_printf_ret = ft_printf("printing %d characters\n", 
//ft_printf("ahdshjvwfvhwefej!!(%p)!!!\n", &ptdr));
//	int printf_ret = printf("printing %d characters\n", 
//printf("ahdshjvwfvhwefej!!(%p)!!!\n", &ptdr));

//	printf("%s", ft_printf_ret == printf_ret ? "OK :D" : "KO :[");
//}