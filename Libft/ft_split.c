/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:41:53 by mszymcza          #+#    #+#             */
/*   Updated: 2025/04/20 13:53:57 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static char	*word_dup(const char *str, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, str, len + 1);
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	**result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = word_dup(s, c);
			if (!result[i])
			{
				while (i--)
					free(result[i]);
				free(result);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (result);
}
