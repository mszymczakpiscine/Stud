
NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src/
INC_DIR		= includes/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/

SRCS		= $(SRC_DIR)main.c \
			$(SRC_DIR)utils.c \
			$(SRC_DIR)utils_b.c \
			$(SRC_DIR)t_stack.c \
			$(SRC_DIR)t_stack_b.c \
			$(SRC_DIR)index.c \
			$(SRC_DIR)checkargs.c \
			$(SRC_DIR)sort.c \
			$(SRC_DIR)swap.c \
			$(SRC_DIR)push.c \
			$(SRC_DIR)rotate.c \
			$(SRC_DIR)reverse.c \
			$(SRC_DIR)radix.c

HEADERS		= $(INC_DIR)push_swap.h

OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			rm -f $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re 
