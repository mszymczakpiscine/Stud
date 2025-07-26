# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 11:46:15 by mszymcza          #+#    #+#              #
#    Updated: 2025/07/26 12:03:47 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

FLAGS	=	-Wall -Wextra -Werror -g3

FILES	=	src/map.c src/map_utils.c src/main.c src/input.c \
			src/render.c src/game.c src/utils.c src/init.c \
			src/start.c src/floodfill.c src/count.c src/enemy.c \
			src/enemy_postion.c src/valid_map.c src/count_bis.c \
			src/screen.c src/tile.c
OBJ		=	$(FILES:.c=.o)

RM		=	rm -f

MLX_NAME	=	mlx
MLX_PATH	=	minilibx-linux/
MLX			=	$(MLX_PATH)lib$(MLX_NAME).a
IFLAGS		=	-I$(MLX_PATH) -I./libft
LFLAGS		=	-L$(MLX_PATH) -l$(MLX_NAME) -lXext -lX11 -lm -lbsd -L./libft -l:libft.a

LIBFT_PATH	=	./libft

all:	$(NAME)

$(NAME): make_libft $(OBJ) $(MLX)
	cc $(FLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@ $(IFLAGS)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

make_libft:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all make_libft clean fclean re
