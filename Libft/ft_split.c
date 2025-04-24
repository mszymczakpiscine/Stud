/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:41:53 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/24 12:13:23 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (in_word == 0 && *str != c)
		{
			in_word = 1;
			count++;
		}
		else if (in_word == 1 && *str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

int	next_charset(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
				len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = next_charset(s, c);
			result[i] = ft_substr(s, 0, len);
			if (!result[i++])
				return (NULL);
			s += len;
		}
	}
	return (result);
}
