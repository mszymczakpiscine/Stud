/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:15:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 21:22:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	append_char(char **out, char ch)
{
	char	*tmp;
	char	*joined;

	tmp = ft_strndup(&ch, 1);
	if (!tmp)
		return (-1);
	joined = ft_strjoin(*out, tmp);
	free(*out);
	free(tmp);
	if (!joined)
		return (-1);
	*out = joined;
	return (0);
}

char	*init_process_heredoc_delim(char *delim, char **quote,
	char **out)
{
	errno = 0;
	*quote = ft_strchr(delim, '"');
	if (!*quote)
		*quote = ft_strchr(delim, '\'');
	if (!*quote)
		return (NULL);
	*out = malloc(1);
	if (!*out)
		return (NULL);
	**out = '\0';
	return (delim);
}

static char	*process_quotes(char *s, char *out, char quote)
{
	while (*s)
	{
		if (*s != quote && append_char(&out, *s) < 0)
		{
			free(out);
			return (NULL);
		}
		s++;
	}
	return (out);
}

char	*process_heredoc_delim(char *delim)
{
	char		*quote;
	char		*s;
	char		*out;
	char		*rec;

	quote = NULL;
	s = init_process_heredoc_delim(delim, &quote, &out);
	if (!s || !quote)
		return (NULL);
	out = process_quotes(s, out, *quote);
	if (!out)
		return (NULL);
	rec = process_heredoc_delim(out);
	if (errno)
		return (free(out), NULL);
	if (rec)
		return (free(out), rec);
	return (out);
}

int	expand_it_then(char **line, int fd_out, t_shell *shell_data)
{
	char	*dup;
	char	*expanded;

	dup = ft_strdup(*line);
	expanded = expand_line(dup, shell_data);
	if (errno)
		return (-1);
	ft_putstr_fd(expanded, fd_out);
	free(expanded);
	return (0);
}
