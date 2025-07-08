/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:19:57 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/23 12:55:06 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("\033[1;31mError\n\033[0m");
	exit(EXIT_FAILURE);
}

static char	*join_path(char *dir, char *cmd)
{
	char	*tmp;
	char	*full;

	tmp = ft_strjoin(dir, "/");
	full = ft_strjoin(tmp, cmd);
	free(tmp);
	return (full);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = join_path(paths[i], cmd);
		if (path && access(path, X_OK) == 0)
			return (free_tab(paths), path);
		free(path);
		i++;
	}
	return (free_tab(paths), NULL);
}

void	execute(char *cmd_line, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd_line, ' ');
	if (!args || !args[0])
	{
		free_tab(args);
		error();
	}
	cmd_path = find_path(args[0], envp);
	if (!cmd_path)
	{
		ft_putstr_fd("Error: command not found\n", 2);
		free_tab(args);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		free(cmd_path);
		free_tab(args);
		error();
	}
}
