# ====================================================#
#              	PUSH_SWAP MAKEFILE					  #
# ====================================================#

NAME		= push_swap.a

SRCS 		= 
OBJS 		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
