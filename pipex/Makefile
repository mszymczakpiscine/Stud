# ======================== #
#        PIPEX MAKEFILE   #
# ======================== #

NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -ggdb

SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/

SRCS		= $(SRC_DIR)pipe.c
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADERS		= $(SRC_DIR)pipex.h

# ========= Colors ========= #
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
RED			= \033[31m
RESET		= \033[0m

# ========= Rules ========= #
all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)Compiling libft...$(RESET)"
			@make -C $(LIBFT_DIR)
			@echo "$(GREEN)Linking project...$(RESET)"
			@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
			@echo "$(GREEN)✔ Build complete: $(NAME)$(RESET)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "$(BLUE)Compiling $<...$(RESET)"
			@$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "$(RED)✘ Objects cleaned.$(RESET)"

fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(RED)✘ Executable removed.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re



