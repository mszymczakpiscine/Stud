
# ======================== #
#        PIPEX MAKEFILE    #
# ======================== #

NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/

SRCS		= $(SRC_DIR)pipe.c $(SRC_DIR)utils.c
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADERS		= $(SRC_DIR)pipex.h

# ========= Colors & Effects ========= #
BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
ORANGE		= \033[38;5;208m
BLUE		= \033[34m
PURPLE		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
BOLD		= \033[1m
RESET		= \033[0m
RAINBOW		= $(RED)$(ORANGE)$(YELLOW)$(GREEN)$(BLUE)$(PURPLE)$(CYAN)

# ========= Rules ========= #
all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)$(BOLD)🌻 Compiling libft...$(RESET)"
			@make -C $(LIBFT_DIR)
			@echo "$(ORANGE)$(BOLD)🔗 Linking project...$(RESET)"
			@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
			@echo "$(RAINBOW)$(BOLD)🌈 SUCCESS! Everything compiled perfectly! 🌈$(RESET)"
			@echo "$(YELLOW)$(BOLD)🎉 $(NAME) is ready to use! $(ORANGE)Congratulations!$(RESET)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)🛠️  Compiling $(ORANGE)$<$(YELLOW)...$(RESET)"
			@$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
			@rm -rf $(OBJ_DIR)
			@make -C $(LIBFT_DIR) clean
			@echo "$(ORANGE)🧹 $(YELLOW)Objects cleaned.$(RESET)"

fclean:		clean
			@rm -f $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(ORANGE)🔥 $(YELLOW)Executable removed.$(RESET)"

re:			fclean all

.PHONY:		all clean fclean re