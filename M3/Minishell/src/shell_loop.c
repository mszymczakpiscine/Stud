/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:20:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/21 20:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	process_segment(char *segment, t_shell *shell)
{
	if (!segment || !*segment)
		return ;
	shell->cmds = parse_input(segment, shell);
	if (shell->cmds)
	{
		execute_pipeline(shell);
		free_cmds(shell->cmds);
		shell->cmds = NULL;
	}
}

void	process_input_line(char *input, t_shell *shell)
{
	char	**segments;
	int		i;

	segments = split_unquoted_semicolons(input);
	if (!segments)
		return ;
	shell->current_segments = segments;
	i = 0;
	while (segments[i])
	{
		process_segment(segments[i], shell);
		i++;
	}
	free_strv(segments);
	shell->current_segments = NULL;
}

char	*read_input_line(void)
{
	char	*input;
	char	*tmp;

	if ((isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)
			&& isatty(STDERR_FILENO)) == 0)
	{
		input = get_next_line(0);
		tmp = input;
		get_next_line(-42);
		input = tmp;
	}
	else
		input = readline("\001\033[1;95m\002🐱 moulishell\001\033[0m\002> ");
	return (input);
}
