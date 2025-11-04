# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 13:47:03 by mszymcza          #+#    #+#              #
#    Updated: 2025/11/04 13:47:03 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ClapTrap

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iincludes -Wno-implicit-fallthrough

SRCS		= main.cpp \
			  src/ClapTrap.cpp

OBJS		= $(SRCS:.cpp=.o)

HEADERS		= includes/ClapTrap.hpp

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
