/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_cmd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/04 15:56:11 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_create(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->argv = NULL;
	cmd->redirs = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->heredoc_delimiter = NULL;
	cmd->heredoc_expand = 1;
	cmd->append = 0;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_add_back(t_cmd **list, t_cmd *new)
{
	t_cmd	*current;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new;
}

int	cmd_count_args(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == WORD)
			count++;
		else if (tokens->type >= REDIR_IN)
			tokens = tokens->next;
		if (tokens)
			tokens = tokens->next;
	}
	return (count);
}

static void	update_quote_state(char c, int *sq, int *dq)
{
	if (c == '\'' && !*dq)
		*sq = !*sq;
	else if (c == '"' && !*sq)
		*dq = !*dq;
}

char	*strip_quotes_keep_flags(const char *file, int *expand)
{
	int		i;
	int		j;
	int		sq;
	int		dq;
	char	*delim;

	*expand = 1;
	if (ft_strchr(file, '\'') || ft_strchr(file, '"'))
		*expand = 0;
	delim = malloc(ft_strlen(file) + 1);
	if (!delim)
		return (NULL);
	i = 0;
	j = 0;
	sq = 0;
	dq = 0;
	while (file[i])
	{
		if ((file[i] == '\'' && !dq) || (file[i] == '"' && !sq))
			update_quote_state(file[i++], &sq, &dq);
		else
			delim[j++] = file[i++];
	}
	delim[j] = '\0';
	return (delim);
}
