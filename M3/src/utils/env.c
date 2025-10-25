/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:41:14 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/15 09:04:10 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_env_entry(const char *name, const char *value)
{
	size_t	name_len;
	size_t	value_len;
	char	*entry;

	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	entry = (char *)malloc(name_len + 1 + value_len + 1);
	if (!entry)
		return (NULL);
	ft_memcpy(entry, name, name_len);
	entry[name_len] = '=';
	ft_strlcpy(entry + name_len + 1, value, value_len + 1);
	return (entry);
}

static int	replace_env_value(char **env, int idx, char *entry)
{
	if (idx < 0)
		return (1);
	free(env[idx]);
	env[idx] = entry;
	return (0);
}

static int	append_env_value(t_shell *shell, char *entry)
{
	int		len;
	char	**newv;
	int		i;

	len = 0;
	while (shell->env && shell->env[len])
		len++;
	newv = (char **)malloc(sizeof(char *) * (len + 2));
	if (!newv)
		return (free(entry), 1);
	i = 0;
	while (i < len)
	{
		newv[i] = shell->env[i];
		i++;
	}
	newv[len] = entry;
	newv[len + 1] = NULL;
	free(shell->env);
	shell->env = newv;
	return (0);
}

int	env_set(t_shell *shell, const char *name, const char *value)
{
	int		idx;
	char	*entry;

	if (!shell || !name || !value)
		return (1);
	idx = find_env_index(shell->env, name, ft_strlen(name));
	entry = build_env_entry(name, value);
	if (!entry)
		return (1);
	if (idx >= 0)
		return (replace_env_value(shell->env, idx, entry));
	return (append_env_value(shell, entry));
}
