/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 12:23:45 by mszymcza          #+#    #+#             */
/*   Updated: 2025/07/11 12:23:45 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;
	while(s[i])
	{
		j = 0;
		while(reject[j])
		{
			if (reject[j++] == s[i])
				return i;
		}
		i++;
	}
	return i;
}
//
// int	main()
// {
// 	char *s = "test";
// 	const char *reject = "es";
// 	printf("%zu\n", ft_strcspn(s, reject));
// }
