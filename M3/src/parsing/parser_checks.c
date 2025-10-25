/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/18 15:43:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	syntax_error(const char *msg)
{
	if (!msg)
		msg = "syntax error";
	ft_dprintf(2, "minishell: %s\n", (char *)msg);
}

int	has_unclosed_quotes(const char *s)
{
	int	sq;
	int	dq;

	if (!s)
		return (0);
	sq = 0;
	dq = 0;
	while (*s)
	{
		if (*s == '\'' && !dq)
			sq = !sq;
		else if (*s == '"' && !sq)
			dq = !dq;
		s++;
	}
	return (sq || dq);
}

int	syntax_error_pipes(t_token *t)
{
	if (!t)
		return (0);
	if (t->type == PIPE)
		return (syntax_error("syntax error near unexpected token `|'"), 1);
	while (t)
	{
		if (t->type == PIPE && (!t->next || t->next->type == PIPE))
			return (syntax_error("syntax error near unexpected token `|'"), 1);
		t = t->next;
	}
	return (0);
}

int	syntax_error_redirs(t_token *t)
{
	while (t)
	{
		if (t->type >= REDIR_IN)
		{
			if (!t->next || t->next->type != WORD)
				return (syntax_error("syntax error near redirection"), 1);
		}
		t = t->next;
	}
	return (0);
}
