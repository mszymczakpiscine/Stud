# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 22:04:24 by mszymcza          #+#    #+#              #
#    Updated: 2025/10/30 22:04:24 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'exécutable
NAME		= phonebook

# Compilateur et flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS		= main.cpp \
			  contact.cpp \
			  PhoneBook.cpp

# Fichiers objets (remplace .cpp par .o)
OBJS		= $(SRCS:.cpp=.o)

# Fichiers headers
HEADERS		= contact.hpp \
			  PhoneBook.hpp

# Couleurs pour l'affichage
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Compilation des fichiers objets
%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(RESET)"

# Nettoyage des fichiers objets
clean:
	@rm -f $(OBJS)
	@echo "$(RED)✗ Object files removed$(RESET)"

# Nettoyage complet
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

# Recompilation complète
re: fclean all

# Indique que ces règles ne sont pas des fichiers
.PHONY: all clean fclean re
