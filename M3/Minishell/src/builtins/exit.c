/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:42:30 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 20:45:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric_str(const char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	exit_numeric_arg(char **args, t_shell *shell)
{
	long long	code;

	if (!is_numeric_str(args[1]))
	{
		ft_dprintf(2, "minishell: exit: %s: numeric argument required\n",
			args[1]);
		cleanup_and_exit(shell, 2);
	}
	code = ft_atoi(args[1]);
	if (args[2])
	{
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (1);
	}
	cleanup_and_exit(shell, (unsigned char)code);
	return (0);
}

int	builtin_exit_args(char **args, int interactive, t_shell *shell)
{
	int	fd_tty;

	if (!args)
		cleanup_and_exit(shell, 0);
	if (interactive)
	{
		fd_tty = open("/dev/tty", O_RDWR);
		if (fd_tty != -1)
		{
			ft_dprintf(fd_tty, "exit\n");
			close(fd_tty);
		}
	}
	if (args[1])
		return (exit_numeric_arg(args, shell));
	cleanup_and_exit(shell, 0);
	return (0);
}
