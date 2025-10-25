/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:14:57 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/24 11:55:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	process_multiple_heredocs(t_cmd *cmd, t_shell *shell)
{
	t_redir	*r;
	t_redir	*last;

	last = NULL;
	r = cmd->redirs;
	while (r)
	{
		if (r->type == REDIR_HEREDOC)
			last = r;
		r = r->next;
	}
	if (!last)
		return (0);
	r = cmd->redirs;
	while (r)
	{
		if (r->type == REDIR_HEREDOC && r != last)
			consume_one_heredoc(r->file);
		r = r->next;
	}
	cmd->heredoc_delimiter = last->file;
	return (handle_heredoc(cmd, shell));
}

static int	open_infile(t_cmd *cmd)
{
	int	fd;

	if (is_ambiguous(cmd->infile))
		return (ft_putstr_fd("minishell: ambiguous redirect\n", 2), -1);
	fd = open(cmd->infile, O_RDONLY);
	if (fd == -1)
		return (perror("minishell"), -1);
	cmd->fd_in = fd;
	return (0);
}

static int	open_outfile(t_cmd *cmd)
{
	int	fd;

	if (is_ambiguous(cmd->outfile))
		return (ft_putstr_fd("minishell: ambiguous redirect\n", 2), -1);
	if (cmd->append)
		fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror("minishell"), -1);
	cmd->fd_out = fd;
	return (0);
}

int	handle_heredoc(t_cmd *cmd, t_shell *shell)
{
	int	pipefd[2];

	if (!cmd->heredoc_delimiter)
		return (0);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	if (prompt_heredoc(pipefd[1], pipefd[0], cmd->heredoc_delimiter, shell))
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	cmd->fd_in = pipefd[0];
	return (0);
}

int	handle_redirections(t_cmd *cmd, t_shell *shell)
{
	if (create_intermediate_outfiles(cmd) == -1)
		return (-1);
	if (cmd->infile && open_infile(cmd) == -1)
		return (-1);
	if (process_multiple_heredocs(cmd, shell) == -1)
		return (-1);
	if (cmd->outfile && open_outfile(cmd) == -1)
		return (-1);
	return (0);
}
