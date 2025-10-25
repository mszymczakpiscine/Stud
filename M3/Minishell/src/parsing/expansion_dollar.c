/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:20:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 16:18:55 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*collect_quoted(const char *v, int *i)
{
	char	quote;
	int		start;

	quote = v[*i];
	(*i)++;
	start = *i;
	while (v[*i] && v[*i] != quote)
		(*i)++;
	if (v[*i] == quote)
		return (ft_substr(v, start, (*i)++ - start));
	return (ft_substr(v, start, *i - start));
}

static char	*expand_braced(const char *v, int *i, t_shell *shell)
{
	int		start;
	int		saved;
	char	*name;
	char	*val;

	saved = *i;
	(*i)++;
	start = *i;
	while (v[*i] && is_name_char(v[*i]))
		(*i)++;
	if (v[*i] == '}' && *i > start)
	{
		name = ft_substr(v, start, *i - start);
		(*i)++;
		val = env_lookup(name, shell);
		free(name);
		return (val);
	}
	*i = saved;
	return (ft_strdup("$"));
}

static char	*expand_name(const char *v, int *i, t_shell *shell)
{
	int		start;
	char	*name;
	char	*val;

	start = *i;
	while (v[*i] && is_name_char(v[*i]))
		(*i)++;
	name = ft_substr(v, start, *i - start);
	val = env_lookup(name, shell);
	free(name);
	if (!val)
		return (ft_strdup(""));
	return (val);
}

char	*expand_dollar(const char *v, int *i, t_shell *shell)
{
	(*i)++;
	if (v[*i] == '?')
		return ((*i)++, ft_itoa(shell->last_exit_status));
	if (v[*i] == '\0' || v[*i] == '\"' || !is_name_char(v[*i]))
		return (ft_strdup("$"));
	if (v[*i] == '\'' || v[*i] == '"')
		return (collect_quoted(v, i));
	if (v[*i] == '{')
		return (expand_braced(v, i, shell));
	return (expand_name(v, i, shell));
}
