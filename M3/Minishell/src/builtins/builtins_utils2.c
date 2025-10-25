/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:50:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/19 20:50:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	escape_calc_extra(const char *v)
{
	size_t	i;
	size_t	extra;

	i = 0;
	extra = 0;
	while (v && v[i])
	{
		if (v[i] == '"' || v[i] == '\\')
			extra++;
		i++;
	}
	return (extra);
}

static void	escape_copy_with_backslash(char *out, const char *v)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (v[i])
	{
		if (v[i] == '"' || v[i] == '\\')
			out[j++] = '\\';
		out[j++] = v[i++];
	}
	out[j] = '\0';
}

char	*escape_value(const char *v)
{
	size_t	len;
	size_t	extra;
	char	*out;

	if (!v)
		return (ft_strdup(""));
	len = ft_strlen(v);
	extra = escape_calc_extra(v);
	out = (char *)malloc(len + extra + 1);
	if (!out)
		return (NULL);
	escape_copy_with_backslash(out, v);
	return (out);
}
