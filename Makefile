# Nom du programme
NAME		= push_swap

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Dossiers
SRC_DIR		= src/
INC_DIR		= include/
OBJ_DIR		= obj/

# Sources
SRCS		= $(SRC_DIR)main.c \
			  $(SRC_DIR)init.c \
			  $(SRC_DIR)instructions.c \
			  $(SRC_DIR)instructions2.c \
			  $(SRC_DIR)radix.c \
			  $(SRC_DIR)reverse_rotate.c \
			  $(SRC_DIR)rotate.c \
			  $(SRC_DIR)sort_small.c \
			  $(SRC_DIR)utils.c

# Headers
HEADERS		= $(INC_DIR)push_swap.h

# Objets
OBJS		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Règles
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler chaque fichier source en objet
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

# Règle pour tester le programme
test:		$(NAME)
			./$(NAME) 2 1 3 6 5 8
			./$(NAME) 4 67 3 87 23
			./$(NAME) 1 2 3 4 5

# Règle pour vérifier les fuites de mémoire
leak_check:	$(NAME)
			valgrind --leak-check=full ./$(NAME) 2 1 3 6 5 8

# Règle pour rendre le checker exécutable
checker:
	chmod +x checker_linux

# Règle pour tester avec le checker
test_checker: $(NAME) checker
	./$(NAME) 2 1 3 6 5 8 | ./checker_linux 2 1 3 6 5 8
	./$(NAME) 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
	./$(NAME) 1 2 3 4 5 | ./checker_linux 1 2 3 4 5

.PHONY:		all clean fclean re test leak_check checker test_checker
