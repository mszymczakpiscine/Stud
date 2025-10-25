/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:05:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 21:26:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtin_dispatch(t_cmd *cmd, t_shell *shell)
{
	if (ft_strcmp(cmd->args[0], "echo") == 0)
		return (builtin_echo(cmd->args));
	if (ft_strcmp(cmd->args[0], "cd") == 0)
		return (builtin_cd(cmd->args, shell));
	if (ft_strcmp(cmd->args[0], "pwd") == 0)
		return (builtin_pwd(shell));
	if (ft_strcmp(cmd->args[0], "export") == 0)
		return (builtin_export(cmd->args, shell));
	if (ft_strcmp(cmd->args[0], "unset") == 0)
		return (builtin_unset(cmd->args, shell));
	if (ft_strcmp(cmd->args[0], "env") == 0)
		return (builtin_env(shell));
	if (ft_strcmp(cmd->args[0], "exit") == 0)
		return (builtin_exit_args(cmd->args, 0, shell));
	return (-1);
}

static char	*resolve_path(t_cmd *cmd, t_shell *shell)
{
	if (ft_strchr(cmd->args[0], '/'))
		return (cmd->args[0]);
	return (get_cmd_path(cmd->args[0], shell->env));
}

static void	exit_not_found(char *name, t_shell *shell)
{
	char	*saved_name;

	saved_name = ft_strdup(name);
	cleanup_shell(shell);
	ft_putstr_fd("minishell: command not found: ", 2);
	if (saved_name)
	{
		ft_putstr_fd(saved_name, 2);
		free(saved_name);
	}
	ft_putstr_fd("\n", 2);
	exit(127);
}

static void	handle_exec_error(char *path, int path_allocated, t_shell *shell)
{
	char	*saved_path;
	int		saved_errno;

	saved_path = ft_strdup(path);
	saved_errno = errno;
	if (path_allocated)
		free(path);
	cleanup_shell(shell);
	ft_putstr_fd("minishell: ", 2);
	if (saved_path)
	{
		ft_putstr_fd(saved_path, 2);
		ft_putstr_fd(": ", 2);
		free(saved_path);
	}
	errno = saved_errno;
	perror("");
	if (errno == EACCES || errno == EISDIR)
		exit(126);
	if (errno == ENOENT)
		exit(127);
	exit(1);
}

void	run_command(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	int		st;
	int		path_was_allocated;

	if (!cmd->args || !cmd->args[0])
		return ;
	st = builtin_dispatch(cmd, shell);
	if (st != -1)
	{
		cleanup_shell(shell);
		exit(st);
	}
	path = resolve_path(cmd, shell);
	path_was_allocated = (ft_strchr(cmd->args[0], '/') == NULL);
	if (!path)
		exit_not_found(cmd->args[0], shell);
	execve(path, cmd->args, shell->env);
	handle_exec_error(path, path_was_allocated, shell);
}
