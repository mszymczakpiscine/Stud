/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:34:59 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 17:02:50 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**dup_envp(char **envp)
{
	int		count;
	int		i;
	char	**v;

	count = 0;
	while (envp && envp[count])
		count++;
	v = (char **)malloc(sizeof(char *) * (count + 1));
	if (!v)
		return (NULL);
	i = 0;
	while (i < count)
	{
		v[i] = ft_strdup(envp[i]);
		if (!v[i])
		{
			while (i-- > 0)
				free(v[i]);
			free(v);
			return (NULL);
		}
		i++;
	}
	v[count] = NULL;
	return (v);
}

void	free_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}
