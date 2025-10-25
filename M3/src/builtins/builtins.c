/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:43:31 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/17 08:32:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_export_entry(char *entry)
{
	char	*eq;
	char	*name;
	char	*val;
	size_t	len;

	eq = ft_strchr(entry, '=');
	if (!eq)
	{
		ft_dprintf(1, "declare -x %s\n", entry);
		return ;
	}
	len = (size_t)(eq - entry);
	name = ft_substr(entry, 0, len);
	val = escape_value(eq + 1);
	if (name && val)
		ft_dprintf(1, "declare -x %s=\"%s\"\n", name, val);
	free(name);
	free(val);
}

int	export_dup_env(char **env, char ***copy)
{
	int	len;
	int	i;

	len = 0;
	while (env && env[len])
		len++;
	if (len == 0)
		return (0);
	*copy = (char **)malloc(sizeof(char *) * len);
	if (!*copy)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*copy)[i] = env[i];
		i++;
	}
	return (len);
}

void	ft_qsort(char **arr, int len,
	int (*cmp)(const void *, const void *))
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (cmp(&arr[j], &arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	print_export_sorted(t_shell *shell)
{
	int		len;
	char	**copy;
	int		i;

	copy = NULL;
	len = export_dup_env(shell->env, &copy);
	if (len <= 0)
		return (0);
	ft_qsort(copy, len, name_cmp);
	i = 0;
	while (i < len)
	{
		print_export_entry(copy[i]);
		i++;
	}
	free(copy);
	return (0);
}
