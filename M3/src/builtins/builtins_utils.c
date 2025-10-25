/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:36:14 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 20:53:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_add_if_missing(t_shell *sh, char *arg)
{
	int		idx;
	char	*entry;

	if (!sh || !arg)
		return ;
	idx = find_env_index(sh->env, arg, ft_strlen(arg));
	if (idx >= 0)
		return ;
	entry = ft_strjoin(arg, "=");
	if (!entry)
		return ;
	append_env(&sh->env, entry);
	free(entry);
}

static void	export_assign(t_shell *sh, char *arg, char *eq)
{
	char	*name;
	int		idx;

	if (!sh || !arg || !eq)
		return ;
	name = ft_substr(arg, 0, (size_t)(eq - arg));
	if (!name)
		return ;
	idx = find_env_index(sh->env, name, ft_strlen(name));
	if (idx >= 0)
	{
		free(sh->env[idx]);
		sh->env[idx] = ft_strdup(arg);
		if (!sh->env[idx])
			sh->env[idx] = ft_strdup("");
	}
	else
		append_env(&sh->env, arg);
	free(name);
}

static int	export_process_arg(char *arg, t_shell *sh)
{
	char	*eq;

	if (!arg || !sh)
		return (1);
	if (!valid_name(arg))
	{
		ft_dprintf(2, "minishell: export: `%s': not a valid identifier\n",
			arg);
		return (1);
	}
	eq = ft_strchr(arg, '=');
	if (!eq)
		export_add_if_missing(sh, arg);
	else
		export_assign(sh, arg, eq);
	return (0);
}

int	builtin_export(char **args, t_shell *sh)
{
	int		k;
	int		status;

	if (!args || !sh)
		return (1);
	if (!args[1])
		return (print_export_sorted(sh));
	status = 0;
	k = 1;
	while (args[k])
	{
		if (export_process_arg(args[k], sh))
			status = 1;
		k++;
	}
	return (status);
}
