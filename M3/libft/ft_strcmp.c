/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libft                                        +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 11:45:00 by automated         #+#    #+#             */
/*   Updated: 2025/09/27 11:45:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*a;
	const unsigned char	*b;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (0);
		if (!s1)
			return (-1);
		return (1);
	}
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((int)(*a) - (int)(*b));
}
