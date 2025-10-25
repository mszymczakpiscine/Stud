/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_execution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:20:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 21:30:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_ambiguous(const char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

static t_redir	*last_out_redir(t_redir *r)
{
	while (r)
	{
		if ((r->type == REDIR_OUT || r->type == REDIR_APPEND) && !r->next)
			return (r);
		r = r->next;
	}
	return (NULL);
}

static int	open_intermediate(t_redir *r)
{
	int	fd;

	if (r->type == REDIR_OUT)
		fd = open(r->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(r->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (perror("minishell"), -1);
	close(fd);
	return (0);
}

int	create_intermediate_outfiles(t_cmd *cmd)
{
	t_redir	*last;
	t_redir	*r;

	last = last_out_redir(cmd->redirs);
	r = cmd->redirs;
	while (r)
	{
		if ((r->type == REDIR_OUT || r->type == REDIR_APPEND) && r != last)
		{
			if (open_intermediate(r) == -1)
				return (-1);
		}
		r = r->next;
	}
	return (0);
}

void	consume_one_heredoc(const char *delim)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			return ;
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}
