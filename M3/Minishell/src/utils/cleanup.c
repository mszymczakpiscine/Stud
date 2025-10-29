#include "minishell.h"

static void	free_strv(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

void	cleanup_shell(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->cmds)
	{
		free_cmds(shell->cmds);
		shell->cmds = NULL;
	}
	if (shell->env)
	{
		free_env(shell->env);
		shell->env = NULL;
	}
	if (shell->current_segments)
	{
		free_strv(shell->current_segments);
		shell->current_segments = NULL;
	}
	if (shell->current_input)
	{
		free(shell->current_input);
		shell->current_input = NULL;
	}
	get_next_line(-42);
}

void	cleanup_and_exit(t_shell *shell, int exit_code)
{
	cleanup_shell(shell);
	rl_clear_history();
	exit(exit_code);
}