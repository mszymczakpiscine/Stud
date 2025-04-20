/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:02:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/20 13:40:09 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	if (!dst || !src)
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst > ptr_src)
	{
		while (len > 0)
		{
			len--;
			ptr_dst[len] = ptr_src[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i++] = ptr_src[i];
		}
	}
	return (dst);
}
