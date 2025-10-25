/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_redir_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:12:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 15:52:40 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*redir_create(t_token *token, int *heredoc_expand_out)
{
	t_redir	*r;

	if (!token || !token->next)
		return (NULL);
	r = malloc(sizeof(t_redir));
	if (!r)
		return (NULL);
	r->type = token->type;
	if (token->type == REDIR_HEREDOC)
		r->file = strip_quotes_keep_flags(token->next->value,
				heredoc_expand_out);
	else
	{
		r->file = ft_strdup(token->next->value);
		if (heredoc_expand_out)
			*heredoc_expand_out = 0;
	}
	r->next = NULL;
	return (r);
}

void	redir_append(t_cmd *cmd, t_redir *r)
{
	t_redir	*cur;

	if (!cmd || !r)
		return ;
	if (!cmd->redirs)
	{
		cmd->redirs = r;
		return ;
	}
	cur = cmd->redirs;
	while (cur->next)
		cur = cur->next;
	cur->next = r;
}

void	redir_apply_effects(t_cmd *cmd, t_token *token)
{
	char	*file;

	if (!token || !token->next)
		return ;
	file = token->next->value;
	if (token->type == REDIR_IN)
	{
		free(cmd->infile);
		cmd->infile = ft_strdup(file);
	}
	else if (token->type == REDIR_OUT || token->type == REDIR_APPEND)
	{
		if (cmd->outfile)
			free(cmd->outfile);
		cmd->outfile = ft_strdup(file);
		cmd->append = (token->type == REDIR_APPEND);
	}
}

void	redir_add(t_cmd *cmd, t_token *token)
{
	t_redir	*r;
	int		heredoc_expand;

	heredoc_expand = 1;
	r = redir_create(token, &heredoc_expand);
	if (!r)
		return ;
	redir_append(cmd, r);
	redir_apply_effects(cmd, token);
	if (token->type == REDIR_HEREDOC)
		cmd->heredoc_expand = heredoc_expand;
}
