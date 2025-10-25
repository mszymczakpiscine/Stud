/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_build.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:32:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 16:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*create_and_link_cmd(t_cmd **cmds)
{
	t_cmd	*cmd;

	cmd = cmd_create();
	if (!cmd)
		return (NULL);
	cmd_add_back(cmds, cmd);
	return (cmd);
}

static void	trim_empty_args(char **args, int *i)
{
	while (*i > 0 && args[*i - 1] && args[*i - 1][0] == '\0')
	{
		free(args[*i - 1]);
		args[--(*i)] = NULL;
	}
}

static int	allocate_args(t_cmd *cmd, t_token *head)
{
	cmd->args = malloc(sizeof(char *) * (cmd_count_args(head) + 1));
	if (!cmd->args)
	{
		cmd->args = malloc(sizeof(char *) * 1);
		if (cmd->args)
			cmd->args[0] = NULL;
		return (0);
	}
	return (1);
}

static void	process_until_pipe(t_cmd *cmd, t_token **head)
{
	int		i;

	if (!cmd || !allocate_args(cmd, *head))
		return ;
	i = 0;
	while (*head && (*head)->type != PIPE)
	{
		if ((*head)->type == WORD)
		{
			if ((*head)->value)
				cmd->args[i++] = ft_strdup((*head)->value);
		}
		else if ((*head)->type >= REDIR_IN)
		{
			redir_add(cmd, *head);
			*head = (*head)->next;
		}
		*head = (*head)->next;
	}
	cmd->args[i] = NULL;
	trim_empty_args(cmd->args, &i);
}

t_cmd	*build_commands(t_token *tokens)
{
	t_cmd	*cmds;
	t_cmd	*cmd;
	t_token	*head;

	cmds = NULL;
	head = tokens;
	while (head)
	{
		cmd = create_and_link_cmd(&cmds);
		process_until_pipe(cmd, &head);
		if (head)
			head = head->next;
	}
	return (cmds);
}
