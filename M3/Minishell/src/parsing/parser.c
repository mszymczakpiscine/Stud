/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 16:00:37 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	unclosed_quote_error(char *input, t_shell *shell)
{
	if (!has_unclosed_quotes(input))
		return (0);
	if (shell)
		shell->last_exit_status = 2;
	syntax_error("unclosed quotes");
	return (1);
}

static int	syntax_errors(t_token *tokens, t_shell *shell)
{
	if (!tokens)
		return (1);
	if (syntax_error_pipes(tokens) || syntax_error_redirs(tokens))
	{
		if (shell)
			shell->last_exit_status = 2;
		return (1);
	}
	return (0);
}

t_cmd	*parse_input(char *input, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*cmds;

	if (!input || !*input)
		return (NULL);
	if (unclosed_quote_error(input, shell))
		return (NULL);
	tokens = tokenize(input);
	if (!tokens)
		return (NULL);
	if (syntax_errors(tokens, shell))
		return (free_tokens(tokens), NULL);
	if (shell)
		expand_tokens(tokens, shell);
	cmds = build_commands(tokens);
	free_tokens(tokens);
	return (cmds);
}
