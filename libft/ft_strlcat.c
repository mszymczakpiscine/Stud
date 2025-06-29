/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:42:59 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/30 09:07:24 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!src || !dest)
		return (0);
	i = 0;
	j = 0;
	len = 0;
	while (dest[i] != '\0')
		i++;
	while (src[len] != '\0')
		len++;
	if (size <= i)
		len += size;
	else
		len += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}
