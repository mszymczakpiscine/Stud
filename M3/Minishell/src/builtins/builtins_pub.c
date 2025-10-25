/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_pub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:55:17 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/04 16:02:39 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	key_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	return (i);
}

int	name_cmp(const void *a, const void *b)
{
	const char	*sa;
	const char	*sb;
	size_t		la;
	size_t		lb;
	int			res;

	sa = *(const char *const *)a;
	sb = *(const char *const *)b;
	la = key_len(sa);
	lb = key_len(sb);
	if (la < lb)
		res = ft_strncmp(sa, sb, la);
	else
		res = ft_strncmp(sa, sb, lb);
	if (res)
		return (res);
	if (la == lb)
		return (0);
	if (la < lb)
		return (-1);
	return (1);
}

static char	**env_dup_without(char **env, int skip)
{
	int		len;
	int		i;
	int		j;
	char	**newv;

	len = 0;
	while (env && env[len])
		len++;
	newv = (char **)malloc(sizeof(char *) * len);
	if (!newv)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != skip)
			newv[j++] = env[i];
		i++;
	}
	newv[j] = NULL;
	return (newv);
}

void	env_remove_entry(t_shell *shell, int idx)
{
	char	**newv;

	if (!shell || !shell->env || idx < 0)
		return ;
	newv = env_dup_without(shell->env, idx);
	if (!newv)
		return ;
	free(shell->env[idx]);
	free(shell->env);
	shell->env = newv;
}

int	builtin_unset(char **args, t_shell *shell)
{
	int	k;
	int	idx;

	k = 1;
	while (args && args[k])
	{
		if (valid_name(args[k]))
		{
			idx = find_env_index(shell->env, args[k], ft_strlen(args[k]));
			if (idx >= 0)
				env_remove_entry(shell, idx);
		}
		k++;
	}
	return (0);
}
