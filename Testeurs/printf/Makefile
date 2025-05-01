NAME = test_ft_printf
SRC_DIR = src
SRC = \
	$(SRC_DIR)/ft_printf.c \
	$(SRC_DIR)/ft_putchar.c \
	$(SRC_DIR)/ft_putstr.c \
	$(SRC_DIR)/ft_putnbr.c \
	$(SRC_DIR)/ft_putnbr_unsigned.c \
	$(SRC_DIR)/ft_puthex.c \
	$(SRC_DIR)/ft_putptr.c \
	$(SRC_DIR)/test_all_printf.c

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	echo -e "\033[1;34m[Compiling]\033[0m Building test_all_printf..."
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	echo -e "\033[1;32m[OK]\033[0m Compilation terminée.\n"
	echo -e "\033[1;36m[Running Tests]\033[0m"
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

