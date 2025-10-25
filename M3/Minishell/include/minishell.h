/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 21:30:00 by <maia>            #+#    #+#             */
/*   Updated: 2025/10/24 14:51:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <errno.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

extern pid_t	g_signal_pid;
// -- ENUMS --

typedef enum e_tokentype
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC
}	t_tokentype;

// -- STRUCTURES --

typedef struct s_token
{
	char			*value;
	t_tokentype		type;
	struct s_token	*next;
}	t_token;

typedef struct s_redir
{
	char			*file;
	t_tokentype		type;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	char			**argv;
	t_redir			*redirs;
	char			*infile;
	int				fd_in;
	int				fd_out;
	char			*outfile;
	char			*heredoc_delimiter;
	int				heredoc_expand;
	int				append;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_cmd	*cmds;
	char	**env;
	char	**current_segments;
	char	*current_input;
	int		last_exit_status;
}	t_shell;

typedef struct s_heredoc_ctx
{
	char		*v;
	int			i;
	int			sq;
	int			dq;
	char		*out;
	t_shell		*shell;
}	t_heredoc_ctx;

typedef struct s_exp_ctx
{
	char		*src;
	int			i;
	int			sq;
	int			dq;
	char		*out;
	t_shell		*shell;
}	t_exp_ctx;

// -- FONCTIONS --

// --- Parsing ---
t_cmd	*parse_input(char *input, t_shell *shell);
void	free_tokens(t_token *tokens);
void	free_cmds(t_cmd *cmds);
t_token	*tokenize(char *input);
t_token	*token_create(char *value, t_tokentype type);
void	token_add_back(t_token **list, t_token *new);
int		skip_heredoc_string(char **input);
int		handle_special_chars(char **input, t_token **tokens);
int		handle_word(char **input, t_token **tokens);
void	expand_tokens(t_token *tokens, t_shell *shell);
t_cmd	*build_commands(t_token *tokens);

// pipeline helpers
t_cmd	*cmd_create(void);
void	cmd_add_back(t_cmd **list, t_cmd *new);
int		cmd_count_args(t_token *tokens);
void	redir_add(t_cmd *cmd, t_token *token);
t_redir	*redir_create(t_token *token, int *heredoc_expand_out);
void	redir_append(t_cmd *cmd, t_redir *r);
void	redir_apply_effects(t_cmd *cmd, t_token *token);
char	*strip_quotes_keep_flags(const char *file, int *expand);

// input split helpers
char	**split_unquoted_semicolons(const char *s);

// parser checks
void	syntax_error(const char *msg);
int		has_unclosed_quotes(const char *s);
int		syntax_error_pipes(t_token *t);
int		syntax_error_redirs(t_token *t);

// --- Execution ---
void	execute_pipeline(t_shell *shell); // Depuis executor.c
void	run_command(t_cmd *cmd, t_shell *shell);
int		handle_redirections(t_cmd *cmd, t_shell *shell);
int		handle_heredoc(t_cmd *cmd, t_shell *shell);
pid_t	spawn_child(t_cmd *cmd, t_shell *shell, int prev_in, int pipe_fd[2]);
void	exec_setup_child_stdio(t_cmd *cmd, int prev_in, int pipe_fd[2]);
int		exec_count_cmds(t_cmd *cmds);
int		is_ambiguous(const char *s);
int		create_intermediate_outfiles(t_cmd *cmd);
void	consume_one_heredoc(const char *delim);
int		process_multiple_heredocs(t_cmd *cmd, t_shell *shell);
char	*init_process_heredoc_delim(char *delim, char **quote, char **out);
char	*process_heredoc_delim(char *delim);
int		expand_it_then(char **line, int fd_out, t_shell *shell_data);
size_t	size_t_max(size_t a, size_t b);
int		while_heredoc(char *no_expand, int fd_out, char *delim,
			t_shell *shell_data);
int		prompt_heredoc(int fd_out, int fd_in, char *delim, t_shell *shell_data);

// Heredoc helpers (split across files, declared here per requirement)
char	*hd_join_char(char *s, char c);
char	*hd_join_str(char *left, const char *right);
int		is_name_char(char c);
char	*env_lookup(const char *name, t_shell *shell);
char	*expand_line(char *v, t_shell *shell);
char	*expand_dollar(const char *v, int *i, t_shell *shell);
void	execute_child(t_cmd *cmd, char **envp);
int		is_parent_builtin(t_cmd *cmd);
void	exec_wait_children(int count, pid_t last_pid, t_shell *shell);
char	*get_cmd_path(char *cmd, char **envp);

// Env helpers
char	**dup_envp(char **envp);
void	free_env(char **env);
int		env_set(t_shell *shell, const char *name, const char *value);

// --- Builtins ---
int		is_builtin(char **tokens);
void	run_builtin(char **tokens, int fd);
int		builtin_echo(char **args);
int		builtin_cd(char **args, t_shell *shell);
int		builtin_pwd(t_shell *shell);
int		builtin_exit_args(char **args, int interactive, t_shell *shell);
int		builtin_env(t_shell *shell);
int		builtin_export(char **args, t_shell *shell);
int		builtin_unset(char **args, t_shell *shell);
int		valid_name(const char *s);
int		find_env_index(char **env, const char *name, size_t nlen);
int		append_env(char ***penv, const char *entry);
int		name_cmp(const void *a, const void *b);
char	*escape_value(const char *v);
int		print_export_sorted(t_shell *shell);
int		builtin_export(char **args, t_shell *shell);
int		builtin_unset(char **args, t_shell *shell);
void	env_remove_entry(t_shell *shell, int idx);
void	ft_qsort(char **arr, int len, int (*cmp)(const void *, const void *));
int		export_dup_env(char **env, char ***copy);
void	print_export_entry(char *entry);
// --- Utils ---
int		ft_dprintf(int fd, const char *format, ...);
void	cleanup_shell(t_shell *shell);
void	cleanup_and_exit(t_shell *shell, int exit_code);

// --- Shell Loop ---
void	process_segment(char *segment, t_shell *shell);
void	process_input_line(char *input, t_shell *shell);
char	*read_input_line(void);

// --- Signal ---
void	signals(void);
void	signals_heredoc(void);

#endif