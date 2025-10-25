/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:58:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/18 16:58:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*hd_expand_dollar(const char *v, int *i, t_shell *shell)
{
	char		*name;
	int			j;
	char		*val;

	(*i)++;
	if (v[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->last_exit_status));
	}
	if (!is_name_char(v[*i]))
		return (ft_strdup("$"));
	j = *i;
	while (v[*i] && is_name_char(v[*i]))
		(*i)++;
	name = ft_substr(v, j, *i - j);
	val = env_lookup(name, shell);
	free(name);
	return (val);
}

static int	hd_handle_quotes(t_heredoc_ctx *s)
{
	if (s->v[s->i] == '\'' && !s->dq)
	{
		s->sq = !s->sq;
		s->out = hd_join_char(s->out, s->v[s->i++]);
		return (1);
	}
	if (s->v[s->i] == '"' && !s->sq)
	{
		s->dq = !s->dq;
		s->out = hd_join_char(s->out, s->v[s->i++]);
		return (1);
	}
	return (0);
}

static int	hd_handle_dollar(t_heredoc_ctx *s)
{
	char	*tmp;

	if (s->v[s->i] == '$' && !s->sq)
	{
		tmp = hd_expand_dollar(s->v, &s->i, s->shell);
		s->out = hd_join_str(s->out, tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

char	*expand_line(char *v, t_shell *shell)
{
	t_heredoc_ctx	s;

	if (!v)
		return (ft_strdup(""));
	s.v = v;
	s.i = 0;
	s.sq = 0;
	s.dq = 0;
	s.out = NULL;
	s.shell = shell;
	while (s.v[s.i])
	{
		if (hd_handle_quotes(&s))
			continue ;
		if (hd_handle_dollar(&s))
			continue ;
		s.out = hd_join_char(s.out, s.v[s.i]);
		s.i++;
	}
	free(s.v);
	if (!s.out)
		return (ft_strdup(""));
	return (s.out);
}
