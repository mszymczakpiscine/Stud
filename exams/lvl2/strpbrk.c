/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpbrk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:57:37 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/05 13:59:45 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return (s1[i]);
			j++;
		}
		i++;
	}
	return NULL;
}