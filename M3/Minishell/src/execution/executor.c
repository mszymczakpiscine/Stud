/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/15 21:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_count_cmds(t_cmd *cmds)
{
	int	i;

	i = 0;
	while (cmds)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

void	exec_wait_children(int num_cmds, pid_t last_pid, t_shell *shell)
{
	int		i;
	int		status;
	pid_t	wpid;

	i = 0;
	while (i < num_cmds)
	{
		wpid = wait(&status);
		if (wpid == -1)
			continue ;
		if (wpid == last_pid)
		{
			if (WIFEXITED(status))
				shell->last_exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell->last_exit_status = 128 + WTERMSIG(status);
		}
		i++;
	}
}

void	exec_setup_child_stdio(t_cmd *cmd, int prev_in, int pipe_fd[2])
{
	if (prev_in != STDIN_FILENO)
	{
		dup2(prev_in, STDIN_FILENO);
		close(prev_in);
	}
	if (cmd->next)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
}

pid_t	spawn_child(t_cmd *cmd, t_shell *shell, int prev_in, int pipe_fd[2])
{
	pid_t	pid;

	if (handle_redirections(cmd, shell) == -1)
		return (-1);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		exec_setup_child_stdio(cmd, prev_in, pipe_fd);
		if (cmd->fd_in != -1)
			dup2(cmd->fd_in, STDIN_FILENO);
		if (cmd->fd_out != -1)
			dup2(cmd->fd_out, STDOUT_FILENO);
		run_command(cmd, shell);
		cleanup_shell(shell);
		exit(EXIT_SUCCESS);
	}
	return (pid);
}
