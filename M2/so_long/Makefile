# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 11:46:15 by mszymcza          #+#    #+#              #
#    Updated: 2025/07/05 16:27:26 by mszymcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

FLAGS	=	-Wall -Wextra -Werror

FILES	=	map.c map_utils.c main.c input.c render.c game.c utils.c
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
