/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:15:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 20:38:00 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *shell)
{
	int	i;

	if (!shell || !shell->env)
		return (1);
	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		i++;
	}
	return (0);
}

int	valid_name(const char *s)
{
	int	i;

	if (!s || !(*s))
		return (0);
	if (!(ft_isalpha(*s) || *s == '_'))
		return (0);
	i = 1;
	while (s[i] && s[i] != '=')
	{
		if (!(ft_isalnum(s[i]) || s[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	find_env_index(char **env, const char *name, size_t nlen)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], name, nlen) && env[i][nlen] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	append_env(char ***penv, const char *entry)
{
	int		len;
	int		i;
	char	**newv;

	len = 0;
	while (*penv && (*penv)[len])
		len++;
	newv = (char **)malloc(sizeof(char *) * (len + 2));
	if (!newv)
		return (1);
	i = 0;
	while (i < len)
	{
		newv[i] = (*penv)[i];
		i++;
	}
	newv[len] = ft_strdup(entry);
	newv[len + 1] = NULL;
	free(*penv);
	*penv = newv;
	return (0);
}
