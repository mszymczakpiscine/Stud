/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:02:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/29 09:57:06 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
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
