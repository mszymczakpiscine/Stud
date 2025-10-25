/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 16:04:27 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->value);
		free(tmp);
	}
}

void	free_redirs(t_redir *redirs)
{
	t_redir	*tmp;

	while (redirs)
	{
		tmp = redirs;
		redirs = redirs->next;
		free(tmp->file);
		free(tmp);
	}
}

static void	free_cmd_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	free_one_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_cmd_args(cmd->args);
	if (cmd->redirs)
		free_redirs(cmd->redirs);
	free(cmd->infile);
	free(cmd->outfile);
	if (cmd->fd_in > STDERR_FILENO)
		close(cmd->fd_in);
	if (cmd->fd_out > STDERR_FILENO)
		close(cmd->fd_out);
	free(cmd);
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*next;

	while (cmds)
	{
		next = cmds->next;
		free_one_cmd(cmds);
		cmds = next;
	}
}
