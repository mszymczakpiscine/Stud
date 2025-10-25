/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 18:00:00 by marvin            #+#    #+#             */
/*   Updated: 2025/10/19 20:53:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_create(char *value, t_tokentype type)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	token->type = type;
	token->next = NULL;
	return (token);
}

void	token_add_back(t_token **list, t_token *new)
{
	t_token	*current;

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

static void	advance_spaces(char **p)
{
	while (**p && ft_isspace(**p))
		(*p)++;
}

static void	consume_word(char **p)
{
	char	q;

	while (**p && !ft_isspace(**p) && !ft_strchr("|<>", **p))
	{
		if (**p == '\'' || **p == '"')
		{
			q = **p;
			(*p)++;
			while (**p && **p != q)
				(*p)++;
			if (**p == q)
				(*p)++;
		}
		else
			(*p)++;
	}
}

int	skip_heredoc_string(char **input)
{
	char	*in;

	in = *input;
	if (ft_strncmp(in, "<<<", 3) != 0 || in[3] == '<')
		return (0);
	in += 3;
	advance_spaces(&in);
	consume_word(&in);
	*input = in;
	return (1);
}
