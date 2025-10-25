/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 16:15:42 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_quotes(char c, int *sq, int *dq)
{
	if (c == '\'' && !*dq)
		*sq = !*sq;
	else if (c == '"' && !*sq)
		*dq = !*dq;
}

static int	process_char(t_exp_ctx *c)
{
	char	*tmp;

	if ((c->src[c->i] == '\'' && !c->dq) || (c->src[c->i] == '"' && !c->sq))
	{
		update_quotes(c->src[c->i], &c->sq, &c->dq);
		c->i++;
		return (1);
	}
	if (c->src[c->i] == '$' && !c->sq)
	{
		tmp = expand_dollar(c->src, &c->i, c->shell);
		c->out = hd_join_str(c->out, tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

static char	*expand_word(char *v, t_shell *shell)
{
	t_exp_ctx	c;

	c.src = v;
	c.i = 0;
	c.sq = 0;
	c.dq = 0;
	c.out = NULL;
	c.shell = shell;
	while (c.src[c.i])
	{
		if (process_char(&c))
			continue ;
		c.out = hd_join_char(c.out, c.src[c.i++]);
	}
	free(v);
	if (c.out)
		return (c.out);
	return (ft_strdup(""));
}

void	expand_tokens(t_token *t, t_shell *shell)
{
	while (t)
	{
		if (t->type == WORD)
			t->value = expand_word(t->value, shell);
		t = t->next;
	}
}
