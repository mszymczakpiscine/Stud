#	PROGRAM NAME AND SOURCE FILES

NAME = cub3D

SRCS = \
	main.c \
	tile.c \
	init.c \
	lines.c \
	raycast.c \
	raycast_h.c \
	raycast_v.c \
	raycast_utils.c \
	handle_input.c \
	flood_fill.c \
	parse_tiles.c \
	parse_metadata.c \
	parse_metadata_utils.c \
	get_dimensions.c \
	skip_metadata.c \
	utils.c \

#	CONFIG

CC = cc
CFLAGS += -Wall -Wextra -Werror
OBJS_PATH = objs/

LIBFT_PATH = libft/
LIBFT_NAME = ft
LIBFT = $(LIBFT_PATH)lib$(LIBFT_NAME).a
IFLAGS += -I$(LIBFT_PATH)
LFLAGS += -L$(LIBFT_PATH) -l$(LIBFT_NAME)

LIBRLX_PATH = librlx/
LIBRLX_NAME = rlx
LIBRLX = $(LIBRLX_PATH)lib$(LIBRLX_NAME).a
IFLAGS += -I$(LIBRLX_PATH)
LFLAGS += -L$(LIBRLX_PATH) -l$(LIBRLX_NAME)

LIBMLX_PATH = minilibx-linux/
LIBMLX_NAME = mlx
LIBMLX = $(LIBMLX_PATH)lib$(LIBMLX_NAME).a
LFLAGS += -L$(LIBMLX_PATH) -l$(LIBMLX_NAME)
LFLAGS += -lXext -lX11 -lm -lz

#	VARS

OBJS = $(addprefix $(OBJS_PATH), ${SRCS:.c=.o})

# ─── COLORS ────────────────────────────────────────────────────────────────
GREEN		= \033[0;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;36m
RED			= \033[0;31m
RESET		= \033[0m
LINE		= ============================================

#	RULES

all: header $(NAME)

header:
	@echo "$(LINE)"
	@echo "$(BLUE)[ COMPILATION DU PROJET: $(NAME) ]$(RESET)"
	@echo "$(LINE)"

bonus : all

$(NAME): $(OBJS)
	@echo "$(BLUE)[→] Compilation de libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory
	@echo "$(BLUE)[→] Compilation de librlx...$(RESET)"
	@$(MAKE) -C $(LIBRLX_PATH) --no-print-directory
	@echo "$(BLUE)[→] Compilation de minilibx...$(RESET)"
	@$(MAKE) -C $(LIBMLX_PATH) --no-print-directory
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "$(GREEN)[✓] Compilation réussie → $(NAME)$(RESET)"

$(OBJS_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)[.o] Compilation de $<$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $?

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(LIBRLX):
	$(MAKE) -C $(LIBRLX_PATH)

$(LIBMLX):
	$(MAKE) -C $(LIBMLX_PATH)

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)[x] Suppression des objets$(RESET)"
	@echo "$(RED)[x] Nettoyage de libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@echo "$(RED)[x] Nettoyage de librlx...$(RESET)"
	@$(MAKE) -C $(LIBRLX_PATH) clean --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[x] Suppression de ./$(NAME)$(RESET)"
	@echo "$(RED)[x] Nettoyage complet de libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "$(RED)[x] Nettoyage complet de librlx...$(RESET)"
	@$(MAKE) -C $(LIBRLX_PATH) fclean --no-print-directory
	@echo "$(RED)[x] Nettoyage de minilibx...$(RESET)"
	@$(MAKE) -C $(LIBMLX_PATH) clean --no-print-directory

re: fclean all

.PHONY: all bonus clean fclean re
