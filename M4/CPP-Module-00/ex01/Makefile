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

NAME		= phonebook

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= main.cpp \
			  contact.cpp \
			  PhoneBook.cpp

OBJS		= $(SRCS:.cpp=.o)

HEADERS		= contact.hpp \
			  PhoneBook.hpp

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

%.o: %.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
