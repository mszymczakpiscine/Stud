/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:47:09 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 19:10:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// forward (already elsewhere) : spawn_child, wait_for_children, count_cmds

static int	parent_builtin_simple(t_cmd *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return (0);
	if (ft_strcmp(cmd->args[0], "exit") == 0
		|| ft_strcmp(cmd->args[0], "export") == 0
		|| ft_strcmp(cmd->args[0], "unset") == 0
		|| ft_strcmp(cmd->args[0], "cd") == 0)
		return (1);
	return (0);
}

static int	handle_parent_builtin(t_shell *sh, t_cmd *cmd)
{
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		sh->last_exit_status = builtin_exit_args(cmd->args, 1, sh);
	else if (ft_strcmp(cmd->args[0], "export") == 0)
		sh->last_exit_status = builtin_export(cmd->args, sh);
	else if (ft_strcmp(cmd->args[0], "unset") == 0)
		sh->last_exit_status = builtin_unset(cmd->args, sh);
	else if (ft_strcmp(cmd->args[0], "cd") == 0)
		sh->last_exit_status = builtin_cd(cmd->args, sh);
	else
		return (0);
	return (1);
}

static pid_t	run_pipeline_children(t_shell *sh, t_cmd *cmd_head, int num)
{
	int		pipe_fd[2];
	int		prev_in;
	pid_t	last;
	t_cmd	*cur;

	prev_in = STDIN_FILENO;
	cur = cmd_head;
	last = -1;
	while (cur)
	{
		if (cur->next && pipe(pipe_fd) == -1)
			perror("pipe");
		last = spawn_child(cur, sh, prev_in, pipe_fd);
		if (last == -1)
			break ;
		if (prev_in != STDIN_FILENO)
			close(prev_in);
		if (cur->next)
		{
			prev_in = pipe_fd[0];
			close(pipe_fd[1]);
		}
		cur = cur->next;
	}
	return ((void)num, last);
}

void	execute_pipeline(t_shell *shell)
{
	int		count;
	pid_t	last;
	t_cmd	*cmd;

	cmd = shell->cmds;
	count = exec_count_cmds(cmd);
	g_signal_pid = 1;
	if (count == 1 && cmd && !cmd->infile && !cmd->outfile
		&& !cmd->heredoc_delimiter && parent_builtin_simple(cmd))
	{
		handle_parent_builtin(shell, cmd);
		g_signal_pid = 0;
		return ;
	}
	last = run_pipeline_children(shell, cmd, count);
	if (last == -1)
		return (shell->last_exit_status = 1, (void)0);
	exec_wait_children(count, last, shell);
	g_signal_pid = 0;
}
