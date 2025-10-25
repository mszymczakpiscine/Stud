/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:00:41 by mszymcza          #+#    #+#             */
/*   Updated: 2025/10/19 20:45:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_tok_ret(t_token **tokens, const char *s, int type, int ret)
{
	token_add_back(tokens, token_create(ft_strdup(s), type));
	return (ret);
}

static int	process_lt_sequence(char *in, t_token **tokens, char **input)
{
	int	count;

	count = 0;
	while (in[count] == '<')
		count++;
	if (count >= 4)
	{
		add_tok_ret(tokens, "<", REDIR_IN, 0);
		add_tok_ret(tokens, "<", REDIR_IN, 0);
		*input += count;
		return (0);
	}
	if (count >= 1)
	{
		if (in[1] == '<')
			return (add_tok_ret(tokens, "<<", REDIR_HEREDOC, 2));
		return (add_tok_ret(tokens, "<", REDIR_IN, 1));
	}
	return (-1);
}

int	handle_special_chars(char **input, t_token **tokens)
{
	char	*in;
	int		res;

	in = *input;
	if (skip_heredoc_string(&in))
	{
		*input = in;
		return (0);
	}
	if (*in == '|')
		return (add_tok_ret(tokens, "|", PIPE, 1));
	if (*in == '<')
	{
		res = process_lt_sequence(in, tokens, input);
		if (res >= 0)
			return (res);
	}
	if (*in == '>')
	{
		if (in[1] == '>')
			return (add_tok_ret(tokens, ">>", REDIR_APPEND, 2));
		return (add_tok_ret(tokens, ">", REDIR_OUT, 1));
	}
	return (0);
}

int	handle_word(char **input, t_token **tokens)
{
	char	*in;
	char	*start;
	char	quote;

	in = *input;
	start = in;
	while (*in && !ft_isspace(*in) && !strchr("|<>", *in))
	{
		if (*in == '\'' || *in == '"')
		{
			quote = *in;
			in++;
			while (*in && *in != quote)
				in++;
			if (*in)
				in++;
		}
		else
			in++;
	}
	if (in > start)
		token_add_back(tokens,
			token_create(ft_substr(start, 0, in - start), WORD));
	return (in - start);
}

t_token	*tokenize(char *input)
{
	t_token	*tokens;
	int		len;

	tokens = NULL;
	while (*input)
	{
		while (ft_isspace(*input))
			input++;
		if (!*input)
			break ;
		len = handle_special_chars(&input, &tokens);
		if (len > 0)
		{
			input += len;
			continue ;
		}
		len = handle_word(&input, &tokens);
		if (len > 0)
			input += len;
	}
	return (tokens);
}
