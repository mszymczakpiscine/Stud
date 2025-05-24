# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 11:46:49 by mszymcza          #+#    #+#              #
#    Updated: 2025/05/24 13:34:22 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom du programme
NAME		= push_swap

# Compilateur et flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Dossiers
BASICS_DIR	= basics/
UTILS_DIR	= utils/
ERROR_DIR	= errors_and_validations/
DEBUG_DIR	= debug/
SORT_DIR	= sorting/

# Sources par catégorie
BASICS_SRCS	= $(BASICS_DIR)swap_operations.c \
			  $(BASICS_DIR)push_operations.c \
			  $(BASICS_DIR)rotate_operations.c \
			  $(BASICS_DIR)reverse_rotate_operations.c

UTILS_SRCS	= $(UTILS_DIR)stack_u.c $(UTILS_DIR)stack_utils.c

ERROR_SRCS	= $(ERROR_DIR)error_handling.c \
			  $(ERROR_DIR)args_validation.c \
			  $(ERROR_DIR)stack_validation.c

DEBUG_SRCS	= $(DEBUG_DIR)print_stack.c

SORT_SRCS	= $(SORT_DIR)small_sort.c \
			  $(SORT_DIR)big_sort.c

# Tous les fichiers sources
SRCS		= push_swap.c \
			  $(BASICS_SRCS) \
			  $(UTILS_SRCS) \
			  $(ERROR_SRCS) \
			  $(DEBUG_SRCS) \
			  $(SORT_SRCS)

# Objets
OBJS		= $(SRCS:.c=.o)

# Règles
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler chaque fichier source en objet
%.o:		%.c push_swap.h
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

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
