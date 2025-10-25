/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:41:01 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/13 15:00:50 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_paths(char **paths)
{
	int	i;

	if (!paths)
		return ;
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

static char	*find_path(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*get_direct_cmd_path(char *cmd)
{
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

static char	*search_paths(char **paths, char *cmd)
{
	int		i;
	char	*dir;
	char	*candidate;
	char	*result;

	i = 0;
	result = NULL;
	while (paths && paths[i] && !result)
	{
		dir = ft_strjoin(paths[i], "/");
		if (!dir)
			break ;
		candidate = ft_strjoin(dir, cmd);
		free(dir);
		if (!candidate)
			break ;
		if (access(candidate, F_OK | X_OK) == 0)
			result = candidate;
		else
			free(candidate);
		i++;
	}
	return (result);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path_var;
	char	*found;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (get_direct_cmd_path(cmd));
	path_var = find_path(envp);
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var, ':');
	if (!paths)
		return (NULL);
	found = search_paths(paths, cmd);
	free_paths(paths);
	return (found);
}
