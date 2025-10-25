/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:00:00 by maia              #+#    #+#             */
/*   Updated: 2025/10/24 14:52:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cd_get_env(char **env, const char *name)
{
	int		k;
	size_t	len;

	if (!env || !name)
		return (NULL);
	len = ft_strlen(name);
	k = 0;
	while (env[k])
	{
		if (!ft_strncmp(env[k], name, len) && env[k][len] == '=')
			return (env[k] + len + 1);
		k++;
	}
	return (NULL);
}

static void	cd_update_env(t_shell *sh, const char *oldpwd)
{
	char	cwd[PATH_MAX];

	if (oldpwd)
		env_set(sh, "OLDPWD", oldpwd);
	if (getcwd(cwd, sizeof(cwd)))
		env_set(sh, "PWD", cwd);
}

static int	cd_resolve_target(char **args, t_shell *sh, const char **target)
{
	const char	*home;
	const char	*oldpwd;

	if (!args[1] || args[1][0] == '\0')
	{
		home = cd_get_env(sh->env, "HOME");
		if (!home)
			return (ft_putstr_fd("minishell: cd: HOME not set\n", 2), 1);
		*target = home;
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		oldpwd = cd_get_env(sh->env, "OLDPWD");
		if (!oldpwd)
			return (ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2), 1);
		*target = oldpwd;
		ft_putstr_fd((char *)oldpwd, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		*target = args[1];
	return (0);
}

int	builtin_cd(char **args, t_shell *sh)
{
	char		cwd[PATH_MAX];
	const char	*target;

	if (!args)
		return (1);
	target = NULL;
	if (args[1] && args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n", 2), 1);
	if (!getcwd(cwd, sizeof(cwd)))
		cwd[0] = '\0';
	if (cd_resolve_target(args, sh, &target))
		return (1);
	if (chdir(target) != 0)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd((char *)target, 2);
		ft_putstr_fd(": ", 2);
		perror("");
		return (1);
	}
	cd_update_env(sh, cwd);
	return (0);
}
