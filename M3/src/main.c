/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:35:46 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 21:03:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_shell(t_shell *shell, char **envp)
{
	shell->env = dup_envp(envp);
	if (!shell->env)
		return (1);
	shell->last_exit_status = 0;
	signals();
	rl_outstream = stderr;
	return (0);
}

static void	shell_loop(t_shell *shell)
{
	char	*input;

	while (1)
	{
		g_signal_pid = 0;
		input = read_input_line();
		if (!input)
			break ;
		shell->current_input = input;
		if (*input)
			add_history(input);
		process_input_line(input, shell);
		free(input);
		shell->current_input = NULL;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	shell.cmds = NULL;
	shell.env = NULL;
	shell.current_segments = NULL;
	shell.current_input = NULL;
	if (init_shell(&shell, envp))
		return (1);
	shell_loop(&shell);
	rl_clear_history();
	cleanup_shell(&shell);
	return (shell.last_exit_status);
}
