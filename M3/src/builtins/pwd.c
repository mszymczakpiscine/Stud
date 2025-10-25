/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:00:00 by maia            	#+#    #+#            */
/*   Updated: 2025/10/24 14:51:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_pwd(char **env)
{
	int		k;
	size_t	len;

	if (!env)
		return (NULL);
	len = 3;
	k = 0;
	while (env[k])
	{
		if (!ft_strncmp(env[k], "PWD", len) && env[k][len] == '=')
			return (env[k] + len + 1);
		k++;
	}
	return (NULL);
}

int	builtin_pwd(t_shell *shell)
{
	char	cwd[PATH_MAX];
	char	*pwd_env;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
		return (0);
	}
	pwd_env = get_env_pwd(shell->env);
	if (pwd_env)
	{
		printf("%s\n", pwd_env);
		return (0);
	}
	ft_putstr_fd("pwd: error retrieving current directory: ", 2);
	ft_putstr_fd("getcwd: cannot access parent directories: ", 2);
	ft_putstr_fd("No such file or directory\n", 2);
	return (1);
}
