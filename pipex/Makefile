
NAME		= pipex

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/

SRCS		= $(SRC_DIR)pipe.c $(SRC_DIR)utils.c

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADERS		= $(SRC_DIR)pipex.h

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\033[33m----Compiling lib----"
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean
			@echo "\n\033[31mDeleting EVERYTHING! \n"

fclean:		clean
			rm -f $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re 
