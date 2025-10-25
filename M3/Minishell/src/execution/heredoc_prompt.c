/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 08:49:42 by marvin            #+#    #+#             */
/*   Updated: 2025/10/01 09:49:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	while_heredoc(char *no_expand, int fd_out, char *delim,
	t_shell *shell_data)
{
	char	*line;

	if (!delim)
		return (-1);
	errno = 0;
	g_signal_pid = 0;
	line = readline("> ");
	if (errno)
		return (-1);
	if (!line || g_signal_pid)
		return (1);
	if (!ft_strncmp(line, delim, size_t_max(ft_strlen(line),
				ft_strlen(delim))))
		return (1);
	if (no_expand)
		ft_putstr_fd(line, fd_out);
	else if (expand_it_then(&line, fd_out, shell_data))
		return (-1);
	ft_putstr_fd("\n", fd_out);
	return (free(line), 0);
}

static int	check_heredoc_status(int status)
{
	if (WIFSIGNALED(status))
		return (-1);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
		return (-1);
	return (0);
}

static void	heredoc_child_exit(char *no_expand, int fd_out, t_shell *shell)
{
	if (no_expand)
		free(no_expand);
	close(fd_out);
	cleanup_shell(shell);
	if (g_signal_pid)
		exit(130);
	exit(0);
}

static void	heredoc_child_loop(char *no_expand, int fd, char *d, t_shell *sh)
{
	int	err;

	while (1)
	{
		err = while_heredoc(no_expand, fd, d, sh);
		if (err == 1)
			break ;
		else if (err)
			(cleanup_shell(sh), exit(err));
	}
}

int	prompt_heredoc(int fd_out, int fd_in, char *delim, t_shell *shell)
{
	char		*no_expand;
	int			status;
	int			pid;

	if (!delim)
		return (-1);
	no_expand = process_heredoc_delim(delim);
	if (errno)
		return (-1);
	if (no_expand)
		delim = no_expand;
	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, &status, 0);
		return (check_heredoc_status(status));
	}
	close(fd_in);
	signals_heredoc();
	heredoc_child_loop(no_expand, fd_out, delim, shell);
	heredoc_child_exit(no_expand, fd_out, shell);
	return (0);
}
