# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 19:00:28 by codespace         #+#    #+#              #
#    Updated: 2025/04/28 20:10:50 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ====================================================
#                FT_PRINTF MAKEFILE
# ====================================================

# 🧱 Configuration
NAME     := test_all_printf
CC       := gcc
CFLAGS   := -Wall -Wextra -Werror
SRC_DIR  := utils
SRC      := \
    $(SRC_DIR)/ft_printf.c \
    $(SRC_DIR)/ft_putchar.c \
    $(SRC_DIR)/ft_putstr.c \
    $(SRC_DIR)/ft_putnbr.c \
    $(SRC_DIR)/ft_putnbr_unsigned.c \
    $(SRC_DIR)/ft_puthex.c \
    $(SRC_DIR)/ft_putptr.c \
    test_all_printf.c

# 🎨 Couleurs
YELLOW   := \033[0;33m
GREEN    := \033[0;32m
RED      := \033[0;31m
RESET    := \033[0m

# 🔧 Compilation
$(NAME): $(SRC)
	@echo "$(YELLOW)[Compiling]$(RESET) Building $(NAME)..."
	@$(CC) $(CFLAGS) -I$(SRC_DIR) $(SRC) -o $(NAME)
	@echo "$(GREEN)[OK]$(RESET) Compilation terminée."

# ▶️ Exécution des tests
run_all: $(NAME)
	@echo "$(YELLOW)[Running]$(RESET) Lancement des tests..."
	@./$(NAME)

# 🧹 Nettoyage
clean:
	@echo "$(YELLOW)[Cleaning]$(RESET) Suppression de l'exécutable..."
	@rm -f $(NAME)
	@echo "$(GREEN)[Done]$(RESET)"

# 📦 Tout refaire
re: clean $(NAME)

# 🚀 Cible par défaut
all: $(NAME)

# 🎯 Cibles utiles
.PHONY: all clean re run_all
