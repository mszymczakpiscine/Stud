# **************************************************************************** #
#                               MINISHELL MAKEFILE                             #
# **************************************************************************** #

NAME		= minishell

# ─── FOLDERS ────────────────────────────────────────────────────────────────
INCDIR		= include
SRCDIR		= src
OBJDIR		= objs

# ─── FILES ──────────────────────────────────────────────────────────────────

SRCS		= $(SRCDIR)/main.c \
			  $(SRCDIR)/shell_loop.c \
			  $(SRCDIR)/utils/dprintf.c \
			  $(SRCDIR)/utils/path.c \
			  $(SRCDIR)/utils/env.c \
			  $(SRCDIR)/utils/env_utils.c \
			  $(SRCDIR)/utils/cleanup.c \
		  	  $(SRCDIR)/builtins/builtins.c \
		      $(SRCDIR)/builtins/echo.c \
		      $(SRCDIR)/builtins/pwd.c \
		      $(SRCDIR)/builtins/cd.c \
		      $(SRCDIR)/builtins/exit.c \
			  $(SRCDIR)/builtins/builtins_env.c \
			  $(SRCDIR)/builtins/builtins_utils.c \
			  $(SRCDIR)/builtins/builtins_utils2.c \
			  $(SRCDIR)/builtins/builtins_pub.c \
			  $(SRCDIR)/parsing/parser.c \
			  $(SRCDIR)/parsing/parser_checks.c \
			  $(SRCDIR)/parsing/parser_free.c \
			  $(SRCDIR)/parsing/tokenization.c \
			  $(SRCDIR)/parsing/token_scan.c \
			  $(SRCDIR)/parsing/expansion.c \
			  $(SRCDIR)/parsing/expansion_dollar.c \
			  $(SRCDIR)/parsing/split_semicolons.c \
			  $(SRCDIR)/parsing/pipeline_build.c \
			  $(SRCDIR)/parsing/pipeline_cmd_utils.c \
			  $(SRCDIR)/parsing/pipeline_redir_utils.c \
			  $(SRCDIR)/parsing/signals.c \
			  $(SRCDIR)/parsing/signals_heredoc.c \
			  $(SRCDIR)/execution/executor.c \
			  $(SRCDIR)/execution/execute_pipe.c \
			  $(SRCDIR)/execution/run_command.c \
			  $(SRCDIR)/execution/redirection_execution.c \
			  $(SRCDIR)/execution/redirections_utils.c \
			  $(SRCDIR)/execution/heredoc.c \
			  $(SRCDIR)/execution/heredoc_expand.c \
			  $(SRCDIR)/execution/heredoc_utils.c \
			  $(SRCDIR)/execution/heredoc_prompt.c

OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS		= $(OBJS:.o=.d)

# ─── COMPILER SETTINGS ─────────────────────────────────────────────────────
CC			= cc
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFT_DIR) -g3 -MMD -MP
LDFLAGS		= -lreadline $(LIBFT_A)

# ─── COLORS ────────────────────────────────────────────────────────────────
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;36m
RED			= \033[0;31m
RESET		= \033[0m
LINE		= ============================================

# ─── RULES ─────────────────────────────────────────────────────────────────
all: header $(NAME)

header:
	@echo "$(LINE)"
	@echo "$(BLUE)[ COMPILATION DU PROJET: $(NAME) ]$(RESET)"
	@echo "$(LINE)"

$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)[✓] Compilation réussie → $(NAME)$(RESET)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)[.o] Compilation de $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)[x] Suppression des objets$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[x] Suppression de ./$(NAME)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# ─── DEBUG / TOOLS ─────────────────────────────────────────────────────────
debug: CFLAGS += -g3 -fsanitize=address -fno-omit-frame-pointer
debug: re

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# ─── INCLUDES DES DEPENDANCES ──────────────────────────────────────────────
-include $(DEPS)

.PHONY: all clean fclean re header debug valgrind
