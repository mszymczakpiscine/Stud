/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mszymcza <mszymcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:22:12 by mszymcza          #+#    #+#             */
/*   Updated: 2025/06/17 14:34:04 by mszymcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

# define TILE_SIZE 64
# define KEY_UP 119
# define KEY_DOWN 115
# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_ESC 65307

typedef enum e_tile 
{
    TILE_EMPTY = 0,
    TILE_WALL,
    TILE_FLOOR,
    TILE_ITEM,
    TILE_EXIT,
    TILE_START,
	TILE_ENEMY,
    TILE_INVALID
} t_tile;

typedef struct s_img
{
	void	*data;
}	t_img;

typedef struct s_window
{
	void	*ptr;
	t_img	img;
	unsigned int	width;
	unsigned int	height;
}	t_window;

typedef struct s_game 
{
	void		*mlx;
	t_window	window;
	t_tile		*map;
	int			width;
	int			height;
	int			enemy_x;
	int			enemy_y;
	int			enemy_dir;
	int			frame_count;
	int			needs_redraw;
	t_img		wall;
	t_img		player;
	t_img		exit;
	t_img		collect;
	t_img		floor;
	t_img		enemy;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			collected;
	int			steps;
	int			fps;
}	t_game;

/* map.c */
int	    handle_keypress(int keycode, t_game *game);
int	    handle_close(t_game *game);
void	move_player(t_game *game, int keycode);
void	put_tile(t_game *game, t_img img, int x, int y);
void	move_enemy_towards_player(t_game *game);
void	render_map(t_game *game);
void	free_map(t_tile *map);
void	put_steps_to_screen(t_game *game);
int		render_frame(t_game *game);
int		close_game(t_game *game);
int		validate_map(t_tile *map, int width, int height);
t_tile	*read_map(char *file_in, int width, int height, t_game *game);
void	print_map(t_tile *map, int width, int height);
void 	init_enemy_position(t_game *game);
t_tile	char_to_tile(char c);
int		count_line(char *file);
int		tile_count(char *file);
int		col_count(char *file);

/* input.c */
int		handle_input(int keycode, t_game *game);

/* render.c */
int		render_frame(t_game *game);

#endif
