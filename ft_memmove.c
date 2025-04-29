/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:02:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/28 17:45:17 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;
	int				sign;

	if (!dst || !src)
		return (NULL);
	(ptr_dst = (unsigned char *)dst, ptr_src = (unsigned char *)src);
	if (ptr_dst > ptr_src)
	{
		i = len;
		sign = -1;
	}
	else
	{
		i = 0;
		sign = 1;
	}
	while (len)
	{
		i += sign;
		ptr_dst[i] = ptr_src[i];
		len--;
	}
	return (dst);
}


//int main()
//{
//	char	src[] = "lorem ipsum dolor sit amet";
//	char	*dest;

//	dest = src + 1;
//	ft_memmove(src, dest, 8);
//	if (src != ft_memmove(src, dest, 8))
//		write(1, "dest's adress was not returned\n", 31);
//	printf("%s\n", src);
//	printf("%s\n", dest);

//}

