/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:58:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/18 15:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hd_join_char(char *s, char c)
{
	size_t	l;
	char	*r;

	if (s)
		l = ft_strlen(s);
	else
		l = 0;
	r = (char *)malloc(l + 2);
	if (!r)
		return (s);
	if (s)
		ft_memcpy(r, s, l);
	r[l] = c;
	r[l + 1] = '\0';
	free(s);
	return (r);
}

char	*hd_join_str(char *left, const char *right)
{
	size_t	ll;
	size_t	rl;
	char	*res;

	if (left)
		ll = ft_strlen(left);
	else
		ll = 0;
	if (right)
		rl = ft_strlen(right);
	else
		rl = 0;
	res = (char *)malloc(ll + rl + 1);
	if (!res)
		return (left);
	if (left)
		ft_memcpy(res, left, ll);
	if (right)
		ft_memcpy(res + ll, right, rl);
	res[ll + rl] = '\0';
	free(left);
	return (res);
}

int	is_name_char(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
		|| c == '_')
		return (1);
	return (0);
}

char	*env_lookup(const char *name, t_shell *shell)
{
	size_t	len;
	int		k;

	if (!name || !shell || !shell->env)
		return (ft_strdup(""));
	len = ft_strlen(name);
	k = 0;
	while (shell->env[k])
	{
		if (!ft_strncmp(shell->env[k], name, len)
			&& shell->env[k][len] == '=')
			return (ft_strdup(shell->env[k] + len + 1));
		k++;
	}
	return (ft_strdup(""));
}

size_t	size_t_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}
