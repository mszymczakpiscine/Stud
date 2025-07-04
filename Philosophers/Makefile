# **************************************************************************** #
#                                PHILO MAKEFILE                                #
# **************************************************************************** #

NAME		= philo

# ─── FOLDERS ────────────────────────────────────────────────────────────────
INCDIR		= include
SRCDIR		= src
OBJDIR		= objs

# ─── FILES ──────────────────────────────────────────────────────────────────
SRCS		= $(SRCDIR)/main.c \
			  $(SRCDIR)/init.c \
			  $(SRCDIR)/routine.c \
			  $(SRCDIR)/monitor.c \
			  $(SRCDIR)/utils.c

OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ─── COMPILER SETTINGS ─────────────────────────────────────────────────────
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INCDIR)

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

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[✓] Compilation réussie → $(NAME)$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)[.o] Compilation de $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)[x] Suppression des fichiers objets$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[x] Suppression du binaire $(NAME)$(RESET)"

re: fclean all

.PHONY: all clean fclean re header

