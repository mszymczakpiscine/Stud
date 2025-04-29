# ====================================================#
#                FT_PRINTF MAKEFILE					  #
# ====================================================#

NAME = ft_printf.a

SRCS = ft_printf.c utils/ft_putchar.c utils/ft_putstr.c utils/ft_putnbr.c utils/ft_putnbr_unsigned.c utils/ft_puthex.c utils/ft_putptr.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
