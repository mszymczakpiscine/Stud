/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_semicolons.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 15:44:31 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_quotes(char c, int *sq, int *dq)
{
	if (c == '\'' && !*dq)
		*sq = !*sq;
	else if (c == '"' && !*sq)
		*dq = !*dq;
}

static int	count_parts(const char *s)
{
	int	i;
	int	sq;
	int	dq;
	int	n;

	i = 0;
	sq = 0;
	dq = 0;
	n = 1;
	while (s[i])
	{
		if (s[i] == ';' && !sq && !dq)
			n++;
		else if (s[i] == '\'' || s[i] == '"')
			update_quotes(s[i], &sq, &dq);
		i++;
	}
	return (n);
}

static char	*trim_sub(const char *s, int start, int end)
{
	while (start < end && ft_isspace(s[start]))
		start++;
	while (end > start && ft_isspace(s[end - 1]))
		end--;
	return (ft_substr(s, start, end - start));
}

static void	fill_segments(const char *s, char **v)
{
	int	i;
	int	j;
	int	sq;
	int	dq;
	int	last;

	i = 0;
	j = 0;
	sq = 0;
	dq = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == ';' && !sq && !dq)
		{
			v[j++] = trim_sub(s, last, i);
			last = i + 1;
		}
		else if (s[i] == '\'' || s[i] == '"')
			update_quotes(s[i], &sq, &dq);
		i++;
	}
	v[j++] = trim_sub(s, last, i);
	v[j] = NULL;
}

char	**split_unquoted_semicolons(const char *s)
{
	char	**v;
	int		parts;

	if (!s)
		return (NULL);
	parts = count_parts(s);
	v = (char **)ft_calloc(parts + 1, sizeof(char *));
	if (!v)
		return (NULL);
	fill_segments(s, v);
	return (v);
}
